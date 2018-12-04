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
    songList=new ArrayList<Song*>(10);
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

void Playlist::addSong(std::string songToAdd){
    std::string artist="";
    Song*newSongToAdd=new Song(artist,songToAdd,0);  //need to get the actual artist and duration for the song
    songList->insertAtEnd(newSongToAdd);
}



void Playlist::playNext(){
    Song*songPlayed=songList->removeValueAtFront();
    duration-=songPlayed->getDuration(); //does this work since songPlayed is a pointer?

}

void Playlist::removeSong(std::string songToRemove){
    int index=songList->find(songToRemove);
    songList->removeValueAt(index);
}

void Playlist::rename(std::string newName){
    name=newName;
}

std::string Playlist::getName(){
    return name;
}