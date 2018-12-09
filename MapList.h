//
// Created by Toby Dragon on 11/6/18.
//

#ifndef LAB9SOLN_MAPLIST_H
#define LAB9SOLN_MAPLIST_H

#include <string>
#include "../../Downloads/COMP220-lab9MapFiles-withTemplates/Car.h"
#include "LinkedNode.h"
#include "../../Downloads/COMP220-lab9MapFiles-withTemplates/Map.h"


template <class T>
class MapList: public Map<T> {
private:
    LinkedNode<T>* last;
    LinkedNode<T>* head;
    int length;

    MapList(const MapList<T>& qToCopy);
    MapList<T>& operator=(const MapList<T>& qToCopy);
public:
    MapList();
    //virtual destructor to allow child destructor to be called
    ~MapList();

    /*
     * @post if the key is new, the key-value pair is added to the map
     *       if the key was already present, the new value overwrites the old value
     *       (i.e., the new value will be returned by get instead of the old value)
     */
    void put(std::string key, const T& value);

    /*
     * @return the value associated with the given key
     * @throws std::invalid_argument if the key is not present
     */
    T get(std::string key);

    /*
     * @return true if the given key is associated with a value in the map, false otherwise
     */
    bool containsKey(std::string key);
};

#include "MapList.inl"

#endif //LAB9SOLN_MAPLIST_H