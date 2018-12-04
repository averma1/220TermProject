//
// Created by Aine on 11/23/2018.
//
#include "Library.h"
#include "ArrayList.h"
#include "Song.h"
#include "List.h"
#include "Playlist.h"

Library::Library(){
    //read files and add songs and playlists
    playListList= new ArrayList<Playlist>(10);
    songList= new ArrayList<Song>(10);
    //count number of both
    numOfSongs=10;
    numOfPlaylists=10;
}

Library::~Library(){
    delete[] playListList;
    delete[] songList;
}

void Library::addSongToList(std::string songName, std::string artist, double duration){
    Song* newSong= new Song(artist, songName, duration);
    songList->insertAtEnd(*newSong);
    //write the song to the file
}

bool Library::isSonginList(std::string songName){
    int found=-1;
    for(int i=0; i<numOfSongs; i++){
        Song current= songList->getValueAt(i);
        if(current.getName()==songName){
            found=i;
        }
    }
    if(found>-1) {
        return true;
    } else {
        return false;
    }
}

void Library::addSongToPlaylist(std::string songName, std::string playlistName){
    int found=-1;
    for(int i=0; i<numOfSongs; i++){
        Song current= songList->getValueAt(i);
        if(current.getName()==songName){
            found=i;
        }
    }
    if(found>-1) {
        for (int i = 0; i < numOfPlaylists; i++) {
            Playlist current = playListList->getValueAt(i);
            if (current.getName() == playlistName) {
                Song addsong = songList->getValueAt(found);
                current.addSong(addsong);
                //update file
            }
        }
    }
}

void Library::createPlaylist(int numOfSongs, std::string playlistName){
    Playlist* newPlaylist= new Playlist(playlistName);
    playListList->insertAtEnd(*newPlaylist);
    //ask user which songs to add then add them until done
    //add the playlist to the file
}

void Library::deletePlaylist(std::string playlistName){
    int found=-1;
    for(int i=0; i<numOfPlaylists; i++){
        Playlist current= playListList->getValueAt(i);
        if(current.getName()==playlistName){
            found=i;
        }
    }
    if(found>-1) {
        playListList->removeValueAt(found);
        //delete from file as well
    }
}

int genRandInt(int min, int max){
    int min1=min;
    int max1=max;
    if(min>max){
        min=max1;
        max=min1;
    }
    bool end= false;
    while(end==false) {
        int rando = rand()%(max-min + 1) + min;
        if(rando>=min) {
            return rando;
        } else {
            end=false;
        }
    }
}

/**
 * NEED TO CALL SRAND IN MAIN
 * @param numbOfSongs
 * @param playlistName
 */
void Library::createRandomPlaylist(int numbOfSongs, std::string playlistName){
    Playlist* newPlaylist= new Playlist(playlistName);
    playListList->insertAtEnd(*newPlaylist);
    for(int i=0; i<numbOfSongs; i++){
        int randInt= genRandInt(0,numOfSongs-1);
        Song randSong= songList->getValueAt(randInt);
        newPlaylist->addSong(randSong);
    }
    //update file
}

void Library::removeSongToPlaylist(std::string songName, std::string playlistName){
    int found=-1;
    for(int i=0; i<numOfSongs; i++){
        Song current= songList->getValueAt(i);
        if(current.getName()==songName){
            found=i;
        }
    }
    if(found>-1) {
        for (int i = 0; i < numOfPlaylists; i++) {
            Playlist current = playListList->getValueAt(i);
            if (current.getName() == playlistName) {
                Song addsong = songList->getValueAt(found);
                current.removeSong(addsong);
                //update file
            }
        }
    }
}

std::string Library::libraryString(){

};
