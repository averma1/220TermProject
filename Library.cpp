//
// Created by Aine on 11/23/2018.
//
#include "Library.h"

Library::Library(){
    //read files and add songs and playlists
    playList= new ArrayList(10);
    songList= new ArrayList(10);
    //count number of both
    numOfSongs=10;
    numOfPlaylists=10;
}

Library::~Library(){
    delete[] playList;
    delete[] songList;
}

void Library::addSongToList(std::string songName, std::string artist){
    song* newSong= new song(songName, artist);
    songList->insertAtEnd(newSong);
    //write the song to the file
}

void addSongToPlaylist(std::string songName, std::string playlistName){
    for(int i=0; i<numOfPlaylists; i++){
        if(playList[i]->getName()==playlistName){
            playList[i]->addSong(songName);
            //update file
        }
    }
}

void Library::createPlaylist(int numOfSongs, std::string playlistName){
    playlist* newPlaylist= new playlist(numOfSongs, playlistName);
    playList->insertAtEnd(newPlaylist);
    //ask user which songs to add then add them until done
    //add the playlist to the file
}

void Library::deletePlaylist(std::string playlistName){
    int found=-1;
    for(int i=0; i<numOfPlaylists; i++){
        if(playList[i]->getName()==playlistName){
            found=i;
        }
    }
    if(found>-1) {
        playList->removeValueAt(found);
        //delete from file as well
    }
}

void Library::createRandomPlaylist(int numbOfSongs, std::string playlistName){
    playlist* newPlaylist= new playlist(numbOfSongs, playlistName);
    playList->insertAtEnd(newPlaylist);
    for(int i=0; i<numbOfSongs; i++){
        int randInt= genRandNumber();
        song* randSong= songList->getValueAt(randInt);
        newPlaylist->addSong(randSong);
    }
    //update file

}
