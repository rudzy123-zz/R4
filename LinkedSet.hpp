/** @file
 *
 *  @course CS1521
 *  @section 3
 *
 *  Header file for a linked implementation of the ADT set.
 *
 *  Adapted from page 139 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Rudolf Musika
 *
 *  @date 14 Feb 2018
 *
 *  @version 7.0 */

#ifndef LINKED_SET_
#define LINKED_SET_

#include <vector>
#include <string>
#include "SetInterface.h"
#include "Node.h"

/** @class LinkedSet LinkedSet.h "LinkedSet.h"
 *
 *  Specification of a pointer-based ADT set. */
template<class ItemType>
class LinkedSet : public SetInterface<ItemType>
{
private:
    using NodePtr = Node<ItemType>*; // Pointer to first node
    
    NodePtr headPtr = nullptr;
    
    int itemCount= 0;           // Current count of bag items
    
    // Returns either a pointer to the node containing a given entry
    // or the null pointer if the entry is not in the bag.
    NodePtr getPointerTo(const ItemType& target) const;
    
public:
    LinkedSet()=default;
    LinkedSet(const LinkedSet<ItemType>& aBag); // Copy constructor
    virtual ~LinkedSet();                       // Destructor should be virtual
    virtual int getCurrentSize() const;
    virtual bool isEmpty() const;
    virtual bool add(const ItemType& newEntry);
    virtual bool remove(const ItemType& anEntry);
    virtual void clear();
    virtual bool contains(const ItemType& anEntry) const;
    virtual int getFrequencyOf(const ItemType& anEntry) const;
    virtual std::vector<ItemType> toVector() const;
    LinkedSet<ItemType> difference(const LinkedSet& input) const; // Project 4-3
}; // end LinkedSet
#include "LinkedSet.cpp"
#endif
