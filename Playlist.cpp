//
// Created by Molly on 11/23/2018.
// Purpose: Store all information about songs and what can be done with/to them
//

#include "Playlist.h"
#include "LinkedList.h"
#include <iomanip>
#include <math.h>


Playlist::Playlist(std::string nameIn){
    name=nameIn;
    songList= new LinkedList<Song*>();
    numberOfSongs=0;
    duration=0;
}

Playlist::Playlist(){
    name="default";
    songList=new LinkedList<Song*>();
    duration=0;
    numberOfSongs=0;
}

Playlist::~Playlist(){
    delete songList;
    songList=nullptr;
}

Playlist::Playlist(const Playlist& playlistToCopy){
    name=playlistToCopy.name;
    duration=playlistToCopy.duration;
    songList=playlistToCopy.songList;
}
Playlist& Playlist:: operator=(const Playlist* playlistToCopy){
    if(this != playlistToCopy){
        delete songList;
        songList=nullptr;
        name=playlistToCopy->name;
        duration=playlistToCopy->duration;
        songList=playlistToCopy->songList;
    }
    return *this;
}

void Playlist::addSong(Song* songToAdd){
    int index=songList->find(songToAdd);
    if (index==-1) {
        songList->insertAtEnd(songToAdd);
        duration += songToAdd->getDuration();
        numberOfSongs++;
    }
}



std::string Playlist::playNext(){
    if (numberOfSongs==0){
        return "No more songs in the playlist";
    } else {
        numberOfSongs--;
        duration -= songList->getValueAt(0)->getDuration();
        Song *songPlayed = songList->removeValueAtFront();
        songPlayed->addToPlayCount();

        std::string rounded_duration = std::to_string(songList->getValueAt(0)->getDuration());
        int decimal_pos = rounded_duration.find('.');
        rounded_duration = rounded_duration.substr(0, decimal_pos+3);

        std::string songInfo = songList->getValueAt(0)->getName() + ',' + songList->getValueAt(0)->getArtist() + ',' +
                               rounded_duration + ',' +
                               std::to_string(songList->getValueAt(0)->getPlayCount());
        return songInfo;
    }
}

void Playlist::removeSong(Song* songToRemove){
    int index=songList->find(songToRemove);
    if(index==-1){
        throw std::invalid_argument("song not in list");
    }
    Song* songRemoved=songList->removeValueAt(index);
    duration-=songRemoved->getDuration();
    numberOfSongs--;
}

void Playlist::removeSongByIndex(int index){
    if(index==-1){
        throw std::invalid_argument("song not in list");
    }
    Song* songRemoved=songList->removeValueAt(index);
    duration-=songRemoved->getDuration();
    numberOfSongs--;
}

void Playlist::rename(std::string newName){
    name=newName;
}

std::string Playlist::getName(){
    return name;
}

double Playlist::getDuration() {
    return duration;
}

int Playlist::getNumberOfSongs(){
    return numberOfSongs;
}

std::string Playlist::getSongList(){
    if (numberOfSongs==0){
        return "No songs in a playlist";
    }
    else {
        std::string stringArray = "";
        int temp = 0;
        while (temp != numberOfSongs) {
            if(temp==0){
                std::string nameSong = songList->getValueAt(temp)->getName();
                std::string artist = songList->getValueAt(temp)->getArtist();
                double duration = songList->getValueAt(temp)->getDuration();
                std::string rounded_duration = std::to_string(duration);
                int decimal_pos = rounded_duration.find('.');
                rounded_duration = rounded_duration.substr(0, decimal_pos+3);
                stringArray = stringArray + nameSong + ", " + artist + ", " + rounded_duration;
            } else {
                std::string nameSong = songList->getValueAt(temp)->getName();
                std::string artist = songList->getValueAt(temp)->getArtist();
                double duration = songList->getValueAt(temp)->getDuration();
                std::string rounded_duration = std::to_string(duration);
                int decimal_pos = rounded_duration.find('.');
                rounded_duration = rounded_duration.substr(0, decimal_pos+3);
                stringArray = stringArray + "\n" + nameSong + ", " + artist + ", " + rounded_duration;
            }
            temp++;
        }
        return stringArray;
    }
    
}

std::string Playlist::getSongListForFile(){
    if (numberOfSongs==0){
        return "No songs in a playlist";
    }
    else {
        std::string stringArray = "";
        int temp = 0;
        while (temp != numberOfSongs) {
            if(temp==0){
                std::string nameSong = songList->getValueAt(temp)->getName();
                std::string artist = songList->getValueAt(temp)->getArtist();
                double duration = songList->getValueAt(temp)->getDuration();
                std::string rounded_duration = std::to_string(duration);
                int decimal_pos = rounded_duration.find('.');
                rounded_duration = rounded_duration.substr(0, decimal_pos+3);
                stringArray = stringArray + nameSong + "," + artist + "," + rounded_duration;
            } else {
                std::string nameSong = songList->getValueAt(temp)->getName();
                std::string artist = songList->getValueAt(temp)->getArtist();
                double duration = songList->getValueAt(temp)->getDuration();
                std::string rounded_duration = std::to_string(duration);
                int decimal_pos = rounded_duration.find('.');
                rounded_duration = rounded_duration.substr(0, decimal_pos+3);
                stringArray = stringArray + "\n" + nameSong + "," + artist + "," + rounded_duration;
            }
            temp++;
        }
        return stringArray;
    }

}