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

void addToPlayCount(int playCount){
    playCount++;
}

std::string Song::getName() {
    return title;
}