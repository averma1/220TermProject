//
// Created by Anika on 11/20/18.
//

#ifndef TERMPROJECT_SONG_H
#define TERMPROJECT_SONG_H

#include "ArrayList.h"
#include<iostream>

class Song{

private:
    std::string artist;
    std::string title;
    double duration;
    int playCount; //number of times we played the song

public:
    Song(std::string artist, std::string title, double duration);
    void addToPlayCount(int playCount);
    std::string getName();
    //double getDuration();
};



#endif //TERMPROJECT_SONG_H
