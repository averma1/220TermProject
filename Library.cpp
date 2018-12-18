//
// Created by Aine on 11/23/2018.
//Implementation of the Library class that contains the list of songs and playlists, and functions that are used by the UI
//
#include "Library.h"
#include "ArrayList.h"
#include "Song.h"
#include "List.h"
#include "Playlist.h"
#include<iostream>
#include<fstream>
#include <sstream>
#include "string.h"
#include "cstdlib"
#include <vector>

Library::Library(){
    //read files and add songs and playlists
    playListList= new ArrayList<Playlist*>(10);
    songList= new ArrayList<Song*>(10);
    //count number of both
    numOfSongs=0;
    numOfPlaylists=0;
    length=0;
}

Library::~Library(){
    delete playListList;
    delete songList;
}

Library::Library(const Library &libraryToCopy){
    numOfSongs=libraryToCopy.numOfSongs;
    numOfPlaylists=libraryToCopy.numOfPlaylists;
    length=libraryToCopy.length;
    playListList=new ArrayList<Playlist*>(numOfPlaylists);
    for(int i=0;i<numOfPlaylists;i++){
        playListList->insertAtEnd(libraryToCopy.playListList->getValueAt(i));
    }
    songList=new ArrayList<Song*>(numOfSongs);
    for(int i=0;i<numOfSongs;i++){
        songList->insertAtEnd(libraryToCopy.songList->getValueAt(i));
    }
}

Library &Library::operator=(const Library* & libraryToCopy){
    if(this!=libraryToCopy){
        delete playListList;
        delete songList;
        numOfSongs=libraryToCopy->numOfSongs;
        numOfPlaylists=libraryToCopy->numOfPlaylists;
        length=libraryToCopy->length;
        playListList=new ArrayList<Playlist*>(numOfPlaylists);
        for(int i=0;i<numOfPlaylists;i++){
            playListList->insertAtEnd(libraryToCopy->playListList->getValueAt(i));
        }
        songList=new ArrayList<Song*>(numOfSongs);
        for(int i=0;i<numOfSongs;i++){
            songList->insertAtEnd(libraryToCopy->songList->getValueAt(i));
        }
    }
    return *this;
}


void Library::addSongToList(std::string songName, std::string artist, double duration){
    if(isSonginList(songName,artist)){
        throw std::invalid_argument("Song is already in list");
    }
    Song* newSong= new Song(artist, songName, duration);
    //songList->insertAtEnd(newSong);
    int index=numOfSongs;
    for(int j=numOfSongs-1;j>=0;j--){
        if((songList->getValueAt(j)->getArtist()>artist)||((songList->getValueAt(j)->getArtist()==artist)&&(songList->getValueAt(j)->getName()>songName))){
            index--;
        }
    }
    if(index==numOfSongs){
        songList->insertAtEnd(newSong);
    }else{
        songList->insertAt(newSong,index);
    }
    numOfSongs++;
}

    //write the song to the file


bool Library::isSonginList(std::string songName,std::string artistName){
    int found=-1;
    for(int i=0; i<numOfSongs; i++){
        Song* current= songList->getValueAt(i);
        if(current->getName()==songName&&current->getArtist()==artistName){
            found=i;
        }
    }
    if(found>-1) {
        return true;
    } else {
        return false;
    }
}

void Library::addSongToPlaylist(std::string songName,std::string artistName, std::string playlistName){

    int found=-1;

    for(int i=0; i<numOfSongs; i++){
        Song* current= songList->getValueAt(i);
        if(current->getName()==songName&&current->getArtist()==artistName){
            found=i;
        }
    }


    if (found==-1){
        throw std::invalid_argument("Song is not in library");
    }
    else{
        int index=-1;
        for (int i = 0; i < numOfPlaylists; i++) {
            Playlist* current = playListList->getValueAt(i);
            if (current->getName() == playlistName) {
                if(isSongInplaylist(songName, artistName, playlistName)){
                    throw std::invalid_argument("Song is already in playlist");
                }
                Song* addsong = songList->getValueAt(found);
                index=i;
                current->addSong(addsong);
                //update file
            }
        }
        if(index==-1) {
            throw std::invalid_argument("Playlist does not exist");
        }

    }

}

void Library::createPlaylist(std::string playlistName){
    for(int i=0;i<numOfPlaylists;i++){
        if(playlistName==playListList->getValueAt(i)->getName()){
            throw std::invalid_argument("Playlist already exists");
        }
    }
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
    if(found==-1){
        throw std::invalid_argument("Playlist does not exist");
    }else{
        playListList->removeValueAt(found);
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

bool Library::isSongInplaylist(std::string songName, std::string artistName, std::string playlistName){
    int found=-1;
    std::string songList=printPlaylistInfo(playlistName);
    if(songList.find(songName) != std::string::npos) {
        found++;
    }
    if (songList.find(artistName) != std::string::npos){
        found++;
    }

    if(found==1){
        return true;
    }else{
        return false;
    }
};

bool Library::samePlaylists(Playlist* playlistName){
    for (int i=0; i<numOfPlaylists-1; i++){
        Playlist* currentPlaylist=playListList->getValueAt(i);
        if (currentPlaylist->getDuration()==playlistName->getDuration()){
            if(currentPlaylist->getSongList()==playlistName->getSongList() ){
                return true;
            }
        }
    }
    return false;
}

/**
 * NEED TO CALL SRAND IN MAIN
 * @param numbOfSongs
 * @param playlistName
 */
void Library::createRandomPlaylist(int playDuration, std::string playlistName){
    double durationOfSongList=0;
    for (int i=0; i<numOfSongs; i++){
        durationOfSongList+=songList->getValueAt(i)->getDuration();
    }
    if(playDuration>durationOfSongList){
        throw std::invalid_argument("not enough songs in songlist");
    }
    for(int i=0;i<numOfPlaylists;i++){
        if(playlistName==playListList->getValueAt(i)->getName()){
            throw std::invalid_argument("Playlist already exists");
        }
    }

    Playlist* newPlaylist= new Playlist(playlistName);
    playListList->insertAtEnd(newPlaylist);
    numOfPlaylists++;
    while(newPlaylist->getDuration()<playDuration){
        int randInt= genRandInt(0,numOfSongs-1);
        Song* randSong= songList->getValueAt(randInt);
        while(this->isSongInplaylist(randSong->getName(), randSong->getArtist(),playlistName)){
            randInt= genRandInt(0,numOfSongs-1);
            randSong= songList->getValueAt(randInt);
        }
        newPlaylist->addSong(randSong);
    }
    newPlaylist->removeSongByIndex(newPlaylist->getNumberOfSongs()-1);

    for(int i=0; i<numOfSongs; i++){
        Song* randSong= songList->getValueAt(i);
        if(!isSongInplaylist(randSong->getName(), randSong->getArtist(),playlistName)){
            newPlaylist->addSong(randSong);
        }
        if(newPlaylist->getDuration()>playDuration){
            newPlaylist->removeSongByIndex(newPlaylist->getNumberOfSongs()-1);
        }
    }
}

void Library::createRandomPlaylistStart(int playDuration, std::string playlistName){
    createRandomPlaylist(playDuration, playlistName);
    Playlist* newPlaylist= playListList->getValueAt(numOfPlaylists-1);
    while(samePlaylists(newPlaylist)){
        deletePlaylist(newPlaylist->getName());
        createRandomPlaylist(playDuration, playlistName);
    }
}

void Library::removeSongToPlaylist(std::string songName,std::string artistName, std::string playlistName){
    int found=-1;
    for(int i=0; i<numOfSongs; i++){
        Song* current= songList->getValueAt(i);
        if(current->getName()==songName&&current->getArtist()==artistName){
            found=i;
        }
    }
    if(found==-1){
        throw std::invalid_argument("Song is not in library");
    } else{
        int index=-1;
        for (int i = 0; i < numOfPlaylists; i++) {
            Playlist* current = playListList->getValueAt(i);
            if (current->getName() == playlistName) {
                Song* addsong = songList->getValueAt(found);
                current->removeSong(addsong);
                index=i;
                //update file
            }
        }
        if(index==-1){
            throw std::invalid_argument("Playlist does not exist");
        }
    }
}

std::string Library::printPlaylists(){
    std::string fullstring;
    for(int i=0; i<numOfPlaylists; i++){
        Playlist* current=playListList->getValueAt(i);
        fullstring+=current->getName();
        if(i!=numOfPlaylists-1){
            fullstring+=", ";
        }
    }
    return fullstring;
}


std::string Library::libraryString(){
    std::string songsInLibrary="";
    for(int i=0; i<numOfSongs; i++){
        songsInLibrary+=printSongInfo(songList->getValueAt(i)->getName(),songList->getValueAt(i)->getArtist());
        songsInLibrary+="\n";
    }
    return songsInLibrary;
}


std::string Library::printSongsByArtist(std::string artist){
    std::string songs= "";
    for(int i=0; i<numOfSongs; i++){
        std::string currentArtist= songList->getValueAt(i)->getArtist();
        if(currentArtist == artist){
            songs+= songList->getValueAt(i)->getName();
            if(i!=numOfSongs-1){
                songs+=", ";
            }
        }
    }
    if(songs==""){
        throw std::invalid_argument("No songs by that artist");
        songs="No songs by that artist";
    }
    return songs;
}

std::string Library::printSongInfo(std::string song, std::string artistName){
    int found=-1;
    std::string songInfo;
    for(int i=0; i<numOfSongs; i++){
        Song* current= songList->getValueAt(i);
        if(current->getName()==song&&current->getArtist()==artistName){
            found=i;
        }
    }
    if(found!=-1) {
        Song* currentSong= songList->getValueAt(found);
        songInfo+="Artist: ";
        songInfo+=currentSong->getArtist();
        songInfo+=", Name: ";
        songInfo+=currentSong->getName();
        songInfo+=", Duration: ";
        std::string rounded_duration = std::to_string(currentSong->getDuration());
        int decimal_pos = rounded_duration.find('.');
        rounded_duration = rounded_duration.substr(0, decimal_pos+3);
        songInfo+=rounded_duration;
        songInfo+=", Play count: ";
        songInfo+=std::to_string(currentSong->getPlayCount());
    } else {
        throw std::invalid_argument("Song does not exist");
        songInfo= "No song by that name in the library";
    }
    return songInfo;
}
void Library::createLibrarySongs(std::string file) {
    List<std::string>* all = readFile(file);

    for(int i=1; i<length; i++){
        std::string str = all->getValueAt(i);
        std::stringstream ss(str);
        std::vector<std::string> result;

        while (ss.good()) {
            std::string substr;
            getline(ss, substr, ',');
            result.push_back(substr);
        }

        std::string artist = result.at(1);
        std::string title = result.at(0);
        double duration = std::stod(result.at(2));

        if(!isSonginList(title,artist)){
            addSongToList(title, artist, duration);
        }
    }
}

void Library::createLibrary(std::string file){
    List<std::string>* all = readFile(file);

    std::string song="Songs,,";
    int count=-1;
    for(int i= 0; i<length; i++){
        if(all->getValueAt(i)==song){
            count=i;
        }
    }

    std::string delimiter = ",";
    std::string death = all->getValueAt(0);
    std::string token = all->getValueAt(2).substr(0, all->getValueAt(2).find(delimiter));
    Playlist* playlist1=new Playlist(token);
    playListList->insertAtEnd(playlist1);
    numOfPlaylists++;

    for(int i=3;i<count-1; i++){
        if (all->getValueAt(i) != death) {
            std::string str = all->getValueAt(i);
            std::stringstream ss(str);
            std::vector<std::string> result;

            while (ss.good()) {
                std::string substr;
                getline(ss, substr, ',');
                result.push_back(substr);
            }

            std::string artist = result.at(1);
            std::string title = result.at(0);
            double duration = std::stod(result.at(2));

            Song *newsong = new Song(artist, title, duration);
            playlist1->addSong(newsong);
            addSongToList(title,artist,duration);

        } else if (all->getValueAt(i) == death) {
            i++;
            token = all->getValueAt(i).substr(0, all->getValueAt(i).find(delimiter));
            playlist1 = new Playlist(token);
            playListList->insertAtEnd(playlist1);
            numOfPlaylists++;
        }
    }
    for(int i=count+1; i<length; i++){
        std::string str = all->getValueAt(i);
        std::stringstream ss(str);
        std::vector<std::string> result;

        while (ss.good()) {
            std::string substr;
            getline(ss, substr, ',');
            result.push_back(substr);
        }

        std::string artist = result.at(1);
        std::string title = result.at(0);
        double duration = std::stod(result.at(2));


        addSongToList(title,artist,duration);
    }
}

List<std::string>* Library::readFile(std::string file){
    std::ifstream infile(file);
    if(!infile){
        std::cerr<<"text file could not be opened for reading"<<std::endl;
    }
    List<std::string>* all= new ArrayList<std::string>(10);
    length= 0;
    while (infile.good()) {
        // read stuff from the file into a string and print it
        std::string strInput;
        getline(infile, strInput);
        all->insertAtEnd(strInput);
        length++;
    }

    infile.close();
    return all;
}

void Library::removeDuplicatesongs(std::string file){
    List<std::string>* all = readFile(file);

    for(int i=1; i<length-1; i++){
        std::string str = all->getValueAt(i);
        std::stringstream ss(str);
        std::vector<std::string> result;

        while (ss.good()) {
            std::string substr;
            getline(ss, substr, ',');
            result.push_back(substr);
        }

        std::string artist = result.at(1);
        std::string title = result.at(0);
        double duration = std::stod(result.at(2));

        int found=-1;
        for(int i=0; i<numOfSongs; i++){
            Song* current= songList->getValueAt(i);
            if(current->getName()==title &&current->getArtist()==artist){
                found=i;
            }
        }
        if(found!=-1) {
            Song* current= songList->getValueAt(found);
            for (int i = 0; i < numOfPlaylists; i++) {
                try {
                    playListList->getValueAt(i)->removeSong(current);
                } catch (std::invalid_argument& e) {

                }
            }
            delete current;
            songList->removeValueAt(found);
            numOfSongs--;
        }

    }

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
    if (found==-1){
        throw std::invalid_argument("Playlist is not in a list");
    }

    else{
        Playlist* currentPlay= playListList->getValueAt(found);
        playInfo+="Name: ";
        playInfo+=currentPlay->getName();
        playInfo+=", Duration: ";
        std::string rounded_duration = std::to_string(currentPlay->getDuration());
        int decimal_pos = rounded_duration.find('.');
        rounded_duration = rounded_duration.substr(0, decimal_pos+3);
        playInfo+=rounded_duration;
        playInfo+="\nSongs: \n";
        playInfo+=currentPlay->getSongList();
    }

    return playInfo;
}

std::string Library::playPlaylist(std::string playlist){
    int found=-1;
    std::string playInfo;
    for(int i=0; i<numOfPlaylists; i++){
        Playlist* current= playListList->getValueAt(i);
        if(current->getName()==playlist){
            found=i;
        }
    }
    if(found!=-1) {
        try {
            Playlist *currentPlay = playListList->getValueAt(found);
            return currentPlay->playNext();
        } catch (std::out_of_range& e) {
            return "Playlist does not exist";
        }
    } else {
        return "Playlist does not exist";
        playInfo="No playlist by that name in the Library";
    }
}

void Library::writeLibraryToFile(std::string file){
    std::ofstream outf(file);

    if (!outf) {
        std::cerr << "Uh oh, Sample.dat could not be opened for writing!" << std::endl;
        exit(1);
    }

    std::string songs="";
    std::string allSongs="";
    outf << ",," << std::endl;
    outf << "Playlists,," << std::endl;
    for(int i=0; i<numOfPlaylists; i++){
        std::string name= playListList->getValueAt(i)->getName();
        name+=",,";
        outf << name << std::endl;
        Playlist* current= playListList->getValueAt(i);
        songs=current->getSongListForFile();
        if(i>0){
            allSongs+="\n";
        }
        allSongs+=songs;
        outf << songs << std::endl;
        outf << ",," << std::endl;
    }
    outf << "Songs,," << std::endl;

    for(int i=0;i<numOfSongs; i++){
        Song* current= songList->getValueAt(i);

        if(allSongs.find(current->getSongInfoForFile())==-1) {
            outf << current->getSongInfoForFile() << std::endl;
        }
    }

}

void Library::createLibraryPlaylists(std::string file){
    List<std::string>* all = readFile(file);

    std::string delimiter = ",";
    std::string death = all->getValueAt(0);
    std::string token = all->getValueAt(2).substr(0, all->getValueAt(2).find(delimiter));
    Playlist* playlist1=new Playlist(token);
    playListList->insertAtEnd(playlist1);
    numOfPlaylists++;

    for(int i=3;i<length; i++){
        if (all->getValueAt(i) != death) {
            std::string str = all->getValueAt(i);
            std::stringstream ss(str);
            std::vector<std::string> result;

            while (ss.good()) {
                std::string substr;
                getline(ss, substr, ',');
                result.push_back(substr);
            }

            std::string artist = result.at(1);
            std::string title = result.at(0);
            double duration = std::stod(result.at(2));

            Song *newsong = new Song(artist, title, duration);
            playlist1->addSong(newsong);
            songList->insertAtEnd(newsong);
            numOfSongs++;

        } else if (all->getValueAt(i) == death) {
            i++;
            token = all->getValueAt(i).substr(0, all->getValueAt(i).find(delimiter));
            playlist1 = new Playlist(token);
            playListList->insertAtEnd(playlist1);
            numOfPlaylists++;
        }
    }
}



