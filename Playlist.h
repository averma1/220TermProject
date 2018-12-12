//
// Created by Molly on 11/23/2018.
//

#ifndef TERMPROJECT_PLAYLIST_H
#define TERMPROJECT_PLAYLIST_H
#include <string>
#include "Song.h"
#include "List.h"


class Playlist{

private:
    std::string name;
    List<Song*>* songList;
    double duration;
    int numberOfSongs;


public:
    Playlist(std::string nameIn);
    Playlist(); //default constructor
    ~Playlist();//destructor
    Playlist(const Playlist& playlistToCopy);//copy constructor
    Playlist& operator=(Playlist* playlistToCopy);//assignment operator

    void addSong(Song* songToAdd);
    void playNext();
    void removeSong(Song* songToRemove);
    void rename(std::string newName);
    std::string getName();
    double getDuration();
    std::string getSongList();




};





#endif //TERMPROJECT_PLAYLIST_H
