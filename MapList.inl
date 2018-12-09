//
// Created by Toby Dragon on 11/6/18.
//

#include <string>
#include "MapList.h"
#include "LinkedNode.h"

template <class T>
MapList<T>::MapList(){
    head = nullptr;
    last = nullptr;
    length=0;
}

//virtual destructor to allow child destructor to be called
template <class T>
MapList<T>::~MapList(){
    while(head!= nullptr){
        LinkedNode<T>* node=head;
        head=head->getNext();
        delete node;
    }
    head= nullptr;
}

template <class T>
MapList<T>::MapList(const MapList<T>& qToCopy){
    LinkedNode<T>* node =qToCopy.head;
    this->head=new LinkedNode<T>(node->getKey(),node->getItem());
    LinkedNode<T>* topNode= this->head;
    node = node->getNext();
    while(node!= nullptr) {
        LinkedNode<T>* newNode = new LinkedNode<T>(node->getKey(),node->getItem());
        topNode->setNext(newNode);
        topNode = newNode;
        node=node->getNext();
    }
}

template <class T>
MapList<T>& MapList<T>::operator=(const MapList<T>& qToCopy){
    while(head!= nullptr){
        LinkedNode<T>* node=head;
        head=head->getNext();
        delete node;
    }
    head= nullptr;
    LinkedNode<T>* node =qToCopy.head;
    this->head=new LinkedNode<T>(node->getKey(),node->getItem());
    LinkedNode<T>* topNode= this->head;
    node = node->getNext();
    while(node!= nullptr) {
        LinkedNode<T>* newNode = new LinkedNode<T>(node->getKey(),node->getItem());
        topNode->setNext(newNode);
        topNode = newNode;
        node=node->getNext();
    }
}

/*
    * @post if the key is new, the key-value pair is added to the map
    *       if the key was already present, the new value overwrites the old value
    *       (i.e., the new value will be returned by get instead of the old value)
    */
template <class T>
void MapList<T>::put(std::string key, const T& value){ //O(n), it could be more efficient but I'm choosing memory efficiency so I won't make it O(1)
    if(length==0){
        LinkedNode<T>* node= new LinkedNode<T>(key, value);
        this->head=node;
        this->last=node;
        this->length++;
    }
    else{
        LinkedNode<T>* temp = head;
        if (containsKey(key)){
            while(temp!= nullptr){
                if(temp->getKey()==key){
                    temp->setItem(value);
                }
                temp=temp->getNext();
            }
        }
        else{
            LinkedNode<T> *node = new LinkedNode<T>(key, value);
            this->last->setNext(node);
            this->last = node;
            this->length++;
        }
    }

}

/*
     * @return the value associated with the given key
     * @throws std::invalid_argument if the key is not present
     */
template <class T>
T MapList<T>::get(std::string key) { //O(n), get is as optimal as it could be because we are using templates and keys we can't 'sort' in a way that would allow us to get item easier so we have to loop through in order to find one we are looking for
    if (!containsKey(key)) {
        throw std::invalid_argument("Key is not present");
    } else {
        LinkedNode<T> *temp = head;
        while (temp != nullptr) {
            if (temp->getKey() == key) {
                T copy=temp->getItem();
                return copy;
            }
            temp=temp->getNext();
        }
    }
}

/*
    * @return true if the given key is associated with a value in the map, false otherwise
    */
template <class T>
bool MapList<T>::containsKey(std::string key) {//O(n), containsKey is as efficient as it can be
    LinkedNode<T>* temp = head;
    while(temp!= nullptr){
        if(temp->getKey()==key){
            return true;
        }
        temp=temp->getNext();
    }
    return false;
}