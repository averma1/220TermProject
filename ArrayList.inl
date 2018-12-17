//
// Created by Aine on 10/16/2018.
//Templated implementation of the ArrayList class of type List
//Used to implement songList and playlistList in the Library class
//

#include <iostream>
#include "ArrayList.h"
#include "Song.h"
#include "Playlist.h"


/**
 * replaces the old array with an array twice the size
 * private method only called within ArrayList when necessary
 * @post: array points to a new array of twice the size with values copied from the old one,
 *        the old array is deleted.
 */
template <class T>
void ArrayList<T>::doubleCapacity(){
    T* sizeChange= new T[currCapacity*2];
    for(int i=0; i<currCapacity; i++){
        sizeChange[i]=array[i];
    }
    delete[] array;
    array=sizeChange;
    currCapacity=currCapacity*2;
}

/**
 * Constructor
 * @throws an std::invalid_argument exception if size < 1
 */
template <class T>
ArrayList<T>::ArrayList(int initialCapacity){
    if(initialCapacity<1){
        throw std::invalid_argument( "not in range" );
    } else {
        currItemCount = 0;
        currCapacity = initialCapacity;
        array = new T[initialCapacity];

    }
}

//Copy Constructor
template <class T>
ArrayList<T>::ArrayList(const ArrayList& arrayListToCopy){
    currItemCount=arrayListToCopy.currItemCount;
    currCapacity=arrayListToCopy.currCapacity;
    array= new T[currCapacity];
    for(int i=0; i<currCapacity; i++){
        array[i]=arrayListToCopy.array[i];
    }

}

//Overloaded Assignment Operator
template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& arrayListToCopy){
    if(this!=&arrayListToCopy) {
        delete[] array;
        array = nullptr;

        currItemCount = arrayListToCopy.currItemCount;
        currCapacity = arrayListToCopy.currCapacity;
        array = new T[currCapacity];
        for (int i = 0; i < currCapacity; i++) {
            array[i] = arrayListToCopy.array[i];
        }
        return *this;
    }

}

//Destructor
template <class T>
ArrayList<T>::~ArrayList(){
    delete[] array;
    array= nullptr;
}

template <class T>
void ArrayList<T>::replacAt(int location, T thing){
    array[location]=thing;
}

template <class T>
bool ArrayList<T>::campareAt(int location, T thing){
    if(array[location]==thing){
        return true;
    } else {
        return false;
    }

}

/**
 * appends the new item to the end of the list
 * @post the list has an additional value in it, at the end
 */
template <class T>
void ArrayList<T>::insertAtEnd(T itemToAdd){
    if(currItemCount+1>currCapacity){
        ArrayList::doubleCapacity();
    }
    array[currItemCount]= itemToAdd;
    currItemCount++;
}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
template <class T>
T ArrayList<T>::getValueAt(int index){
    if(index>=currCapacity or currItemCount==0 or index>=currItemCount or index<0 or isEmpty()){
        throw std::out_of_range( "not in range" );
    } else {
        return array[index];
    }
}


/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 */
template <class T>
bool ArrayList<T>::isEmpty(){
    if(currItemCount!=0){
        return false;
    } else {
        return true;
    }
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
template <class T>
int ArrayList<T>::itemCount(){
    return currItemCount;
}

/**
 * makes the list empty of valid items
 * @post the list is empty, such that isEmpty() == true
 */
template <class T>
void ArrayList<T>::clearList(){
    for(int i=0; i<currItemCount; i++){
        array[i]=0;
    }
    currItemCount=0;
}

/**
 * Searches an int array for a certain value
 * @post numLinesRun is updated to include lines run by this function
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */


template <class T>
int ArrayList<T>:: find(T numToFind){
    for(int i=0;i<currItemCount;i++){
        if(*(array+i)==numToFind){
            return i;
        }
    }
    return -1;
}











/**
 * Searches an int array for a certain value
 * @post numLinesRun is updated to include lines run by this function
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
template <class T>
int ArrayList<T>::findLast(const T* arrayPtr, int size, T numToFind){
    if((size-1)<0){
        return -1;
    } else {
        if (arrayPtr[size-1] == numToFind) {
            return (size-1);
        } else {
            return findLast(arrayPtr, size - 1, numToFind);
        }
    }
}

/**
 * finds the largest value in the array
 * @post numLinesRun is updated to include lines run by this function
 * @return the first index of the maximum value, or -1 if size < 1
 */
template <class T>
int ArrayList<T>::findMaxIndex(const T* arrayPtr, int size){
    int found=0;
    if(size<1){

        throw std::out_of_range( "received negative value" );
    }
    int max=arrayPtr[0];

    for (int i = 0; i < size; i++) {

        if (arrayPtr[i] > max) {
            found = i;
            max=arrayPtr[i];

        }
    }
    return found;
}

/**
 * appends the new item to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
template <class T>
void ArrayList<T>::insertAtFront(T itemToAdd){
    if(currItemCount+1>currCapacity){
        ArrayList::doubleCapacity();
    }
    for(int i=currItemCount; i>0; i-=1){
        array[i]=array[i-1];
    }
    array[0]=itemToAdd;
    currItemCount++;
}

/**
 * inserts the item into the list so that it can be found with get(index)
 * @param index the location in which to insert this item
 * @post the list has an additional value in it at the specified index,
 *        all further values have been shifted down by one index
 * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
 */
template <class T>
void ArrayList<T>::insertAt(T itemToAdd, int index){
    if(index<0 or index>currItemCount){
        throw std::out_of_range( "not in range" );
    } else {
        if (currItemCount + 1 > currCapacity) {
            ArrayList::doubleCapacity();
        }
        for (int i = currItemCount ; i > index; i -= 1) {
            array[i] = array[i - 1];
        }
        array[index] = itemToAdd;
        currItemCount++;
    }
}

/**
 * removes the item at the end of the list, and returns a copy of that item
 * @post the item at the end is removed from the list
 * @return a copy of the item at the end
 * @throws out_of_range exception if there is no item to remove
 */
template <class T>
T ArrayList<T>::removeValueAtEnd(){
    if(currItemCount==0){
        throw std::out_of_range( "not in range" );
    } else {
        T lost=array[currItemCount-1];
        array[currItemCount-1] = 0;
        currItemCount --;
        return lost;
    }

}

/**
 * removes the item at the front of the list, and returns a copy of that item
 * @post the item at the front is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if there is no item to remove
 */
template <class T>
T ArrayList<T>::removeValueAtFront(){
    if(currItemCount==0){
        throw std::out_of_range( "not in range" );
    } else {
        T lost=array[0];
        for (int i = 0; i < currItemCount; i++) {
            array[i] = array[i + 1];
        }
        currItemCount--;
        return lost;
    }
}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
template <class T>
T ArrayList<T>::removeValueAt(int index){
    if(currItemCount==0 or index<0 or index>currCapacity or index>currItemCount){
        throw std::out_of_range( "not in range" );
    } else {
        T lost=array[index];
        for (int i = index; i < currItemCount - 1; i++) {
            array[i] = array[i + 1];
        }
        currItemCount--;
        return lost;
    }
}

