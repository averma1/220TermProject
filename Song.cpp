//
// Created by Anika on 11/20/18.
// Purpose: Store all information about songs and what can be done with/to them
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

void Song::addToPlayCount(){
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

std::string Song::getSongInfo(){
    std::string info="";
    std::string rounded_duration = std::to_string(duration);
    int decimal_pos = rounded_duration.find('.');
    rounded_duration = rounded_duration.substr(0, decimal_pos+3);
    info = info + title + ", " + artist + ", " + rounded_duration;
    return info;
}

std::string Song::getSongInfoForFile(){
    std::string info="";
    std::string rounded_duration = std::to_string(duration);
    int decimal_pos = rounded_duration.find('.');
    rounded_duration = rounded_duration.substr(0, decimal_pos+3);
    info = info + title + "," + artist + "," + rounded_duration;
    return info;
}
