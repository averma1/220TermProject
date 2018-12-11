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

std::string Song::getArtist(){
    return artist;
}

double Song::getDuration(){
    return duration;
}

int Song::getPlayCount(){
    return playCount;
}

std::string Song::toString(std::string artist, std::string title, double duration, int playCount){

    std::string myString = "";
    myString += artist + ", " + title + ", " + std::to_string(duration) + ", " + std::to_string(playCount);
    return myString;

}