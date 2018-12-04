//
// Created by Molly on 11/23/2018.
//

#include "Playlist.h"



Playlist::Playlist(std::string nameIn){
    name=nameIn;
    songList= new ArrayList<Song>(10);
    duration=0;
}

Playlist::Playlist(){
    name="default";
    songList=new ArrayList<Song>(10);
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

void Playlist::addSong(Song songToAdd){
    songList->insertAtEnd(songToAdd);
    duration+=songToAdd.getDuration();
}



void Playlist::playNext(){
    Song songPlayed=songList->removeValueAtFront();
    duration-=songPlayed.getDuration();

}

void Playlist::removeSong(Song songToRemove, int index){
    songList->removeValueAt(index);
    duration-=songToRemove.getDuration();
}

void Playlist::rename(std::string newName){
    name=newName;
}

std::string Playlist::getName(){
    return name;
}