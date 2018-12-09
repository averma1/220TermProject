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
    std::string key;

public:
    LinkedNode(std::string key,const T& item);
    LinkedNode(const LinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    T getItem();
    std::string getKey();
    LinkedNode* getNext();
    void setItem(const T newItem);
    void setNext(LinkedNode* newNext);
};

#include "LinkedNode.inl"

#endif //LINKEDNODE_H
