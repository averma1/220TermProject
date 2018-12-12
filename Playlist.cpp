//
// Created by Molly on 11/23/2018.
//

#include "Playlist.h"
#include "LinkedList.h"


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
Playlist& Playlist:: operator=(Playlist* playlistToCopy){
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
    songList->insertAtEnd(songToAdd);
    duration+=songToAdd->getDuration();
    numberOfSongs++;
}



void Playlist::playNext(){
    duration-=songList->getValueAt(0)->getDuration();
    Song*songPlayed= songList->removeValueAtFront();
    songPlayed->addToPlayCount();
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

void Playlist::rename(std::string newName){
    name=newName;
}

std::string Playlist::getName(){
    return name;
}

double Playlist::getDuration() {
    return duration;
}

std::string Playlist::getSongList(){
    if (numberOfSongs==0){
        return "No songs in a playlist";
    }
    else {
        std::string stringArray = "{";
        int temp = 0;
        while (temp != numberOfSongs) {
            if (temp+1==numberOfSongs) {
                std::string nameSong = songList->getValueAt(temp)->getName();
                stringArray += nameSong;
                temp++;
            } else {
                std::string nameSong = songList->getValueAt(temp)->getName();
                stringArray += nameSong + ", ";
                temp++;
            }
        }
        stringArray = stringArray + "}";
        return stringArray;
    }


}