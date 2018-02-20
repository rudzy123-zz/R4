/** @file
 *
 *  @course CS1521
 *  @section 3
 *
 *  Header file for a node in the linked implementation of the ADT
 *  set.
 *
 *  Adapted from pages 136-137 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Rudolf Musika
 *
 *  @date 14 Feb 2018
 *
 *  @version 7.0 */

#ifndef NODE_
#define NODE_

template <typename ItemType>
class Node {
private:
    ItemType item;
    Node<ItemType>* next = nullptr;
    
public:
    Node()= default;
    
    Node(const ItemType& anItem,
         Node<ItemType>* nextNodePtr = nullptr);
    
    virtual ~Node() = default;
    
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    
    ItemType getItem() const;
    Node<ItemType>* getNext() const;
};

#include "Node.cpp"

#endif

