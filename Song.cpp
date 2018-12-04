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

void Song::addToPlayCount(int playCount){

    playCount++;

}

double Song::getDuration(){
    return duration;
}

