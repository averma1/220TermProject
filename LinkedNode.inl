//
// Created by Toby Dragon on 10/17/17.
//
#include "LinkedNode.h"
#include "../../Downloads/COMP220-lab9MapFiles-withTemplates/Car.h"
#include <stdexcept>
#include <string>

template<class T>
LinkedNode<T>::LinkedNode(std::string key,const T& item){
    this->item = new T(item);
    this->key=key;
    next = nullptr;
}

template<class T>
LinkedNode<T>::LinkedNode(const LinkedNode& nodeToCopy){
    item = nodeToCopy.item;
    key=nodeToCopy.key;
    next = nullptr;
}

template<class T>
T LinkedNode<T>::getItem(){
    return *item;
}

template<class T>
std::string LinkedNode<T>::getKey(){
    return key;
}

template<class T>
LinkedNode<T>* LinkedNode<T>::getNext(){
    return next;
}

template<class T>
void LinkedNode<T>::setItem(const T newItem){
    item = new T(newItem);
}

template<class T>
void LinkedNode<T>::setNext(LinkedNode<T>* newNext){
    next = newNext;
}
