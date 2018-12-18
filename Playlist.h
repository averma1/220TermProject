//
// Created by Molly on 11/23/2018.
// Purpose: Store all information about playlists and what can be done with/to them
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
    Playlist& operator=(const Playlist* playlistToCopy);//assignment operator

    void addSong(Song* songToAdd);
    std::string playNext();
    void removeSong(Song* songToRemove);
    void removeSongByIndex(int index);
    void rename(std::string newName);
    std::string getName();
    double getDuration();
    std::string getSongList();
    int getNumberOfSongs();
    std::string getSongListForFile();

};





#endif //TERMPROJECT_PLAYLIST_H
