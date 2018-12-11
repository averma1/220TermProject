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
    playListList= new ArrayList<Playlist*>(10);
    songList= new ArrayList<Song*>(10);
    //count number of both
    numOfSongs=0;
    numOfPlaylists=0;
}

Library::~Library(){
    delete[] playListList;
    delete[] songList;
}

void Library::addSongToList(std::string songName, std::string artist, double duration){
    Song* newSong= new Song(artist, songName, duration);
    songList->insertAtEnd(newSong);
//    int index=-1;
//    //if the artist is already in the list
//    for(int i=0; i<numOfSongs;i++){
//        if(artist==songList[i].getArtist()){   //might not work if the song needs to go in the first spot
//            if(songName<songList[i].getSong()){
//                index=i;
//            }
//        }
//    }
//    //if the artist isn't already in the list
//    if(index==-1){
//        for(int i=0;i<numOfSongs;i++){
//            if(artist<songList[i].getArtist()){
//                index=i;
//            }
//        }
//    }
//
//    songList->insertAt(i,newSong)

    numOfSongs++;
    //write the song to the file
}

bool Library::isSonginList(std::string songName){
    int found=-1;
    for(int i=0; i<numOfSongs; i++){
        Song* current= songList->getValueAt(i);
        if(current->getName()==songName){
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
        Song* current= songList->getValueAt(i);
        if(current->getName()==songName){
            found=i;
        }
    }
    if(found>-1) {
        for (int i = 0; i < numOfPlaylists; i++) {
            Playlist* current = playListList->getValueAt(i);
            if (current->getName() == playlistName) {
                Song* addsong = songList->getValueAt(found);
                current->addSong(addsong);
                //update file
            }
        }
    }
}

void Library::createPlaylist(int numOfSongs, std::string playlistName){
    Playlist* newPlaylist= new Playlist(playlistName);
    playListList->insertAtEnd(newPlaylist);
    numOfPlaylists++;
    //ask user which songs to add then add them until done
    //add the playlist to the file
}

void Library::deletePlaylist(std::string playlistName){
    int found=-1;
    for(int i=0; i<numOfPlaylists; i++){
        Playlist* current= playListList->getValueAt(i);
        if(current->getName()==playlistName){
            found=i;
        }
    }
    if(found>-1) {
        playListList->removeValueAt(found);
        //delete from file as well
    }
    numOfPlaylists--;
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
    playListList->insertAtEnd(newPlaylist);
    for(int i=0; i<numbOfSongs; i++){
        int randInt= genRandInt(0,numOfSongs-1);
        Song* randSong= songList->getValueAt(randInt);
        newPlaylist->addSong(randSong);
    }
    //update file
}

void Library::removeSongToPlaylist(std::string songName, std::string playlistName){
    int found=-1;
    for(int i=0; i<numOfSongs; i++){
        Song* current= songList->getValueAt(i);
        if(current->getName()==songName){
            found=i;
        }
    }
    if(found>-1) {
        for (int i = 0; i < numOfPlaylists; i++) {
            Playlist* current = playListList->getValueAt(i);
            if (current->getName() == playlistName) {
                Song* addsong = songList->getValueAt(found);
                current->removeSong(addsong);
                //update file
            }
        }
    }
}

std::string Library::printPlaylists(){
    std::string fullstring;
    for(int i=0; i<numOfPlaylists; i++){
        Playlist* current=playListList->getValueAt(i);
        fullstring+=current->getName();
        fullstring+=" ";
    }
    return fullstring;
}

std::string Library::libraryString(){
    //print songs in alpha order
}

std::string Library::printSongsByArtist(std::string artist){
    std::string songs= "";
    for(int i=0; i<numOfSongs; i++){
        std::string currentArtist= songList->getValueAt(i)->getArtist();
        if(currentArtist == artist){
            songs+= currentArtist;
            songs+=", ";
        }
    }
    if(songs==""){
        songs="No songs by that artist";
    }
    return songs;
}

std::string Library::printSongInfo(std::string song){
    int found=-1;
    std::string songInfo;
    for(int i=0; i<numOfSongs; i++){
        Song* current= songList->getValueAt(i);
        if(current->getName()==song){
            found=i;
        }
    }
    if(found!=-1) {
        Song* currentSong= songList->getValueAt(found);
        songInfo+="Artist: ";
        songInfo+=currentSong->getArtist();
        songInfo+=" Name: ";
        songInfo+=currentSong->getName();
        songInfo+=" Duration: ";
        songInfo+=currentSong->getDuration();
        songInfo+=" Play count: ";
        songInfo+=currentSong->getPlayCount();
    } else {
        songInfo= "No song by that name in the library";
    }
    return songInfo;
}

void Library::readFile(std::string file){
    //read file of given name and add to library
}

void Library::removeDuplicatesongs(std::string file){
    //remove duplicate songs by reading a file
}

std::string Library::printPlaylistInfo(std::string playlist){
    int found=-1;
    std::string playInfo;
    for(int i=0; i<numOfPlaylists; i++){
        Playlist* current= playListList->getValueAt(i);
        if(current->getName()==playlist){
            found=i;
        }
    }
    if(found!=-1){
        Playlist* currentPlay= playListList->getValueAt(found);
        playInfo+="Name: ";
        playInfo+=currentPlay->getName();
        playInfo+=" Duration: ";
        playInfo+=currentPlay->getDuration();
        playInfo+=" Songs: ";
        //playInfo+=currentPlay->songs();
    } else {
        playInfo="No playlist by that name in the Library";
    }
    return playInfo;
}

void Library::playPlaylist(std::string playlist){
    int found=-1;
    std::string playInfo;
    for(int i=0; i<numOfPlaylists; i++){
        Playlist* current= playListList->getValueAt(i);
        if(current->getName()==playlist){
            found=i;
        }
    }
    if(found!=-1){
        Playlist* currentPlay= playListList->getValueAt(found);
        currentPlay->playNext();
    } else {
        playInfo="No playlist by that name in the Library";
    }
}

