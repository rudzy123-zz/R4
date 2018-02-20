/** @file
 *
 *  @course CS1521
 *  @section 3
 *
 *  Implementation file for a node in the linked implementation of the
 *  ADT set.
 *
 *  Adapted from page 137 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Rudolf Musika
 *
 *  @date 14 Feb 2018
 *
 *  @version 7.0 */
#include "Node.h"

template <typename ItemType>
Node<ItemType>::Node(const ItemType& anItem,
                     Node<ItemType>* nextNodePtr)
                : item(anItem), next(nextNodePtr)
{
}// end constructor

template <typename ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
    
    item = anItem;
}// end setItem

template <typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
    
    next = nextNodePtr;
}// end setNext

template <typename ItemType>
ItemType Node<ItemType>::getItem() const {
    
    return item;
}// end getItem

template <typename ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    
    return next;
}// end getNext
