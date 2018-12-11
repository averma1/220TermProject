//
// Created by Molly on 11/23/2018.
//

#include "Playlist.h"
#include "LinkedList.h"


Playlist::Playlist(std::string nameIn){
    name=nameIn;
    songList= new LinkedList<Song*>();
    duration=0;
}

Playlist::Playlist(){
    name="default";
    songList=new LinkedList<Song*>();
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

void Playlist::addSong(Song* songToAdd){
    songList->insertAtEnd(songToAdd);
    duration+=songToAdd->getDuration();
}



void Playlist::playNext(){
    duration-=songList->getValueAt(0)->getDuration();
    songList->removeValueAtFront();
}

void Playlist::removeSong(Song* songToRemove){
    int index=songList->find(songToRemove);
    Song* songRemoved=songList->removeValueAt(index);
    duration-=songRemoved->getDuration();
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
    return songList->toString();
}