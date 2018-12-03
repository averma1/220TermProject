//
// Created by Molly on 11/23/2018.
//

#include "Playlist.h"


Playlist::Playlist(std::string nameIn){
    name=nameIn;
    songList= new ArrayList<Song*>(10);
    duration=0;
}

Playlist::Playlist(){
    name="default";
    songList=new ArrayList(10);
    duration=0;
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
Playlist& Playlist:: operator=(const Playlist& playlistToCopy){
    if(this != playlistToCopy){
        delete songList;
        songList=nullptr;
        name=playlistToCopy.name;
        duration=playlistToCopy.duration;
        songList=playlistToCopy.songList;
    }
    return *this;
}

void Playlist::addSong(Song songToAdd){
    songList->insertAtEnd(songToAdd);
}

void Playlist::playNext(){
    songList->removeValueAtFront();
}

void Playlist::removeSong(Song songToRemove){
    int index=songList->find(songToRemove);
    songList->removeValueAt(index);
}

void Playlist::rename(std::string newName){
    name=newName;
}