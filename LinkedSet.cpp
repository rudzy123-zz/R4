/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Implementation file for the class LinkedSet.
 *
 *  Adapted from pages 139-148 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Rudolf Musika
 *
 *  @date 17  2018
 *
 *  @version 7.0 */

#include "Node.h"
#include <cstddef>
#include "LinkedSet.hpp"
#include <vector>

template <typename ItemType>
LinkedSet<ItemType>::LinkedSet(const LinkedSet<ItemType>& aBag) {
    
    itemCount = aBag.itemCount;
    
    if (!aBag.headPtr) { // if (aBag.headPtr == nullptr) {
        headPtr = nullptr;
    }
    else {
        NodePtr origChainPtr(aBag.headPtr);
        
        headPtr = new Node<ItemType>(origChainPtr->getItem() );
        
        NodePtr newChainPtr(headPtr);
        
        origChainPtr = origChainPtr->getNext();
        
        while (origChainPtr) { // while (origChainPtr != nullptr) {
            newChainPtr->setNext(new Node<ItemType>(origChainPtr->getItem()) );
            
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }
    }
}

template<class ItemType>
LinkedSet<ItemType>::~LinkedSet()
{
    clear();
} // end destructor

template<class ItemType>
bool LinkedSet<ItemType>::isEmpty() const
{
    return itemCount == 0;
} // end isEmpty

template<class ItemType>
int LinkedSet<ItemType>::getCurrentSize() const
{
    return itemCount;
} // end getCurrentSize

template<class ItemType>
bool LinkedSet<ItemType>::add(const ItemType& newEntry)
{
    if(contains(newEntry)){
    return false;
    }
    // Add to beginning of chain: new node references rest of chain;
    // (headPtr is null if chain is empty)
    Node<ItemType>* nextNodePtr = new Node<ItemType>();
    nextNodePtr->setItem(newEntry);
    nextNodePtr->setNext(headPtr); // New node points to chain
    //   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code
    
    headPtr = nextNodePtr;          // New node is now first node
    itemCount++;
    
    return true;
} // end add

template<class ItemType>
std::vector<ItemType> LinkedSet<ItemType>::toVector() const
{
    std::vector<ItemType> bagContents;
    Node<ItemType>* curPtr = headPtr;
    int counter = 0;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        bagContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
        counter++;
    } // end while
    
    return bagContents;
} // end toVector

template<class ItemType>
bool LinkedSet<ItemType>::remove(const ItemType& anEntry)
{
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
    if (canRemoveItem)
    {
        // Copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());
        
        // Delete first node
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();
        
        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        
        itemCount--;
    } // end if
    
    return canRemoveItem;
} // end remove

template<class ItemType>
void LinkedSet<ItemType>::clear()
{
    Node<ItemType>* nodeToDeletePtr = headPtr;
    while (headPtr != nullptr)
    {
        headPtr = headPtr->getNext();
        
        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        
        nodeToDeletePtr = headPtr;
    } // end while
    // headPtr is nullptr; nodeToDeletePtr is nullptr
    
    itemCount = 0;
} // end clear

template<class ItemType>
int LinkedSet<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int counter = 0;
    Node<ItemType>* curPtr = headPtr;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        if (anEntry == curPtr->getItem())
        {
            frequency++;
        } // end if
        
        counter++;
        curPtr = curPtr->getNext();
    } // end while
    
    return frequency;
} // end getFrequencyOf

template<class ItemType>
bool LinkedSet<ItemType>::contains(const ItemType& anEntry) const
{
    return (getPointerTo(anEntry) != nullptr);
} // end contains

//Project 3
template<class ItemType>
LinkedSet<ItemType> LinkedSet<ItemType>::difference(const LinkedSet& input) const{
    // make a new LinkedBag that will hold the difference
    LinkedSet<ItemType> theDiff;
    // traverse the existing linked list
    Node<ItemType>* callerPtr = headPtr;
    Node<ItemType>* paramPtr = input.headPtr;
    while (callerPtr != nullptr)
    {
        while(paramPtr != nullptr){
            // compare item entries
            if(callerPtr->getItem() == paramPtr->getItem()){
                //do nothing and stop looking
                break;
            }
            //if we get to the end of input and don't find it.
            if(paramPtr->getNext() == nullptr){
                // items are not equivalent.
                //add to difference
                theDiff.add(callerPtr->getItem());
                break;
            }
            //advance to next item in paramPtr
            paramPtr = paramPtr->getNext();
        }
        //reset paramPtr
        paramPtr = input.headPtr;
        //advance to next item in callerPtr
        callerPtr = callerPtr->getNext();
        
    }
    return theDiff;
    
    
}

// private
// Returns either a pointer to the node containing a given entry
// or the null pointer if the entry is not in the bag.
template <typename ItemType>
Node<ItemType>* LinkedSet<ItemType>::getPointerTo(const ItemType& target) const {

    bool isFound(false);

    NodePtr curPtr(headPtr);

    while (!isFound && curPtr) { // ... && curPtr != nullptr) {
        isFound = curPtr->getItem() == target;

        if (!isFound) { // Must protect curPtr as it is returned
            curPtr = curPtr->getNext();
        }
    }

    return curPtr;
}


