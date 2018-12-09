//
// Created by Toby Dragon on 10/30/18.
//

#include "LinkedList.h"

/**
     * Constructor
     */

//O(1)
template <class T>
LinkedList<T>::LinkedList(){
    front=nullptr;
    end=nullptr;
    size=0;
}

//Destructor
//O(N)
template <class T>
LinkedList<T>::~LinkedList(){
    if(front!=nullptr) {
        LinkedNode<T> *toDelete = front;
        front = nullptr;
        end=nullptr;
        LinkedNode<T> *nextNode;
        while (toDelete->getNext() != nullptr) {
            nextNode = toDelete->getNext();
            delete toDelete;
            toDelete = nextNode;
        }
        delete toDelete;
        toDelete = nullptr;
        nextNode = nullptr;
    }

}

/**
 * appends the new item to the end of the list
 * @post the list has an additional value in it, at the end
 */
 //O(1)
 template <class T>
void LinkedList<T>::insertAtEnd(T itemToAdd){
    LinkedNode<T>* newNode = new LinkedNode<T>(itemToAdd);
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }
    else {
        end->setNext(newNode);
        end = newNode;
    }
    size++;
}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
 //O(N)
 template <class T>
T LinkedList<T>::getValueAt(int index){
    LinkedNode<T>* currentNode=front;
    int currentIndex=0;
    if(index<0 || index>=size){
        throw std::out_of_range("invalid index");
    }else if(index==0){
        return front->getItem();
    }else{
        while(currentIndex!=index){
            currentNode=currentNode->getNext();
            currentIndex++;
        }
        return currentNode->getItem();
    }
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
 //O(N)
 template <class T>
std::string LinkedList<T>::toString(){
    LinkedNode<T>* currentNode=front;
    if(size>0){
        std::string arrayString="{";

        for(int i=0; i<size-1; i++){
            arrayString=arrayString+std::to_string(currentNode->getItem())+", ";
            currentNode=currentNode->getNext();
        }
        arrayString=arrayString+std::to_string(currentNode->getItem());
        arrayString=arrayString+"}";

        return arrayString;
    }
    else{
        return "{}";
    }
}

/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 */

 //O(N)
 template <class T>
bool LinkedList<T>::isEmpty(){
    return front==nullptr;
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */

//O(1)
template <class T>
int LinkedList<T>::itemCount(){
    return size;
}

/**
 * makes the list empty of valid items
 * @post the list is empty, such that isEmpty() == true
 */

//O(N)
template <class T>
void LinkedList<T>::clearList(){
    if (front!=nullptr) {
        if (size == 1) {
            delete front;
            front = nullptr;
            end = nullptr;
        } else {
            LinkedNode<T> *nodeToDelete = front;
            LinkedNode<T> *nextNode = front->getNext();
            while(nextNode->getNext()!= nullptr) {
                delete nodeToDelete;
                nodeToDelete = nextNode;
                nextNode = nextNode->getNext();
            }
            delete nodeToDelete;
            delete nextNode;
            front = nullptr;
            end = nullptr;
            size = 0;
        }
    }
    }

/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */

//O(N)
template <class T>
int LinkedList<T>::find(T numToFind){
    LinkedNode<T>* currentNode=front;
    if(size==1){
        if(front->getItem()==numToFind){
            return 0;
        }
        else{
            return -1;
        }
    }else {
        for (int i = 0; i < size; i++) {
            if (currentNode->getItem() == numToFind) {
                return i;
            }
            currentNode = currentNode->getNext();
        }
        return -1;
    }

}

/**
 * Searches an int array for a certain value
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */

//O(N)
template <class T>
int LinkedList<T>::findLast(T numToFind){
    LinkedNode<T>* currentNode=front;
    if(size==1){
        if(front->getItem()==numToFind){
            return 0;
        }
        else{
            return -1;
        }
    }else {
        int index=-1;
        for (int i =0; i < size; i++) {
            if (currentNode->getItem() == numToFind) {
                index= i;
            }
            currentNode = currentNode->getNext();
        }
        return index;
    }
}

/**
 * finds the largest value in the array
 * @return the first index of the maximum value
 * @throws out_of_range exception if there is no item to remove
 */

//O(N)
template <class T>
int LinkedList<T>::findMaxIndex(){
    if(size==0){
        throw std::out_of_range("list is empty");
    }else if(size==1){
        return 0;
    }else{
        LinkedNode<T>* currentNode=front;
        int max=currentNode->getItem();
        int maxIndex=0;
        for(int i=0; i<size; i++){
            if(currentNode->getItem()>max){
                max=currentNode->getItem();
                maxIndex=i;
            }
            currentNode=currentNode->getNext();
        }
        return maxIndex;
    }

}

/**
 * appends the new item to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
 //O(1)
 template <class T>
void LinkedList<T>::insertAtFront(T itemToAdd){
    LinkedNode<T>* newNode = new LinkedNode<T>(itemToAdd);
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }
    else {
        LinkedNode<T>* oldFrontNode=front;
        front=newNode;
        newNode->setNext(oldFrontNode);
    }
    size++;

}

/**
 * inserts the item into the list so that it can be found with get(index)
 * @param index the location in which to insert this item
 * @post the list has an additional value in it at the specified index,
 *        all further values have been shifted down by one index
 * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
 */

//O(N)
template <class T>
void LinkedList<T>::insertAt(T itemToAdd, int index){
    if(index<0 || index>size){
        throw std::out_of_range("invalid index");
    }
    else if(index==0){
        insertAtFront(itemToAdd);
    }else if(index==size){
        insertAtEnd(itemToAdd);
    }else{
        LinkedNode<T>* currentNode=front;
        LinkedNode<T>* nextNode=front->getNext();
        int currentIndex=0;
        while(currentIndex!=index-1){
            currentNode=currentNode->getNext();
            nextNode=nextNode->getNext();
            currentIndex++;
        }
        LinkedNode<T> *newNode = new LinkedNode<T>(itemToAdd);
        currentNode->setNext(newNode);
        newNode->setNext(nextNode);
        size++;
    }
}

/**
 * removes the item at the end of the list, and returns a copy of that item
 * @post the item at the end is removed from the list
 * @return a copy of the item at the end
 * @throws out_of_range exception if there is no item to remove
 */

//O(N)
template <class T>
T LinkedList<T>::removeValueAtEnd(){
    int valueToRemove=0;
    if(isEmpty()){
        throw std::out_of_range("queue is empty");
    }else if(size==1){
        LinkedNode<T> *nodeToRemove = end;
        front=nullptr;
        end=nullptr;
        valueToRemove = nodeToRemove->getItem();
        delete nodeToRemove;
        size--;
        return valueToRemove;
    }
    else {
        LinkedNode<T> *nodeToRemove = end;
        LinkedNode<T>*previousNode=front;
        for(int i=0; i<size-2; i++){
            previousNode=previousNode->getNext();
        }
        end=previousNode;
        valueToRemove = nodeToRemove->getItem();
        delete nodeToRemove;
        size--;
        return valueToRemove;
    }

}

/**
 * removes the item at the front of the list, and returns a copy of that item
 * @post the item at the front is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if there is no item to remove
 */

//O(1)
template <class T>
T LinkedList<T>::removeValueAtFront(){
    int valueToRemove=0;
    if(isEmpty()){
        throw std::out_of_range("queue is empty");
    }else if(size==1){
        LinkedNode<T> *nodeToRemove = front;
        front=nullptr;
        end=nullptr;
        valueToRemove = nodeToRemove->getItem();
        delete nodeToRemove;
        size--;
        return valueToRemove;
    }
    else {
        LinkedNode<T> *nodeToRemove = front;
        front=nodeToRemove->getNext();
        valueToRemove = nodeToRemove->getItem();
        delete nodeToRemove;
        size--;
        return valueToRemove;
    }

}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */

//O(N)
template <class T>
T LinkedList<T>::removeValueAt(int index){
    int valueToRemove=0;
    if(index<0 || index>=size){
        throw std::out_of_range("invalid index");
    }else if(index==0){
        return removeValueAtFront();
    }else if(index==size-1){
        return removeValueAtEnd();
    }else {
        LinkedNode<T> *nodeToRemove = front->getNext();
        LinkedNode<T>*previousNode=front;
        for(int i=0; i<index-1; i++){
            previousNode=previousNode->getNext();
            nodeToRemove=nodeToRemove->getNext();
        }
        previousNode->setNext(nodeToRemove->getNext());
        valueToRemove = nodeToRemove->getItem();
        delete nodeToRemove;
        size--;
        return valueToRemove;
    }

}
