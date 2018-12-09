//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include <string>

template<class T>
class LinkedNode {

private:
    T* item;
    LinkedNode* next;

public:
    LinkedNode(const T& item);
    LinkedNode(const LinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    T getItem();
    LinkedNode* getNext();
    void setItem(const T newItem);
    void setNext(LinkedNode* newNext);
};

#include "LinkedNode.inl"

#endif //LINKEDNODE_H
