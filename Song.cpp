//
// Created by Anika on 11/20/18.
//

#include "Song.h"

Song::Song(std::string artist, std::string title, double duration){

    this->artist = artist;
    this->title = title;
    this->duration = duration;
    playCount = 0;

}

Song::Song(){
    this->artist = "default";
    this->title = "default";
    this->duration = 0;
    playCount = 0;
}

void Song::addToPlayCount(int playCount){
    playCount++;
}

std::string Song::getName() {
    return title;
}

double Song::getDuration(){
    return duration;
}

std::string Song::toString(std::string artist, std::string title, double duration, int playCount){

    std::string myString = "";
    myString += artist + ", " + title + ", " + duration + ", " + playCount;
    return myString;

}