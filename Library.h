//
// Created by Aine on 11/23/2018.
//

#ifndef FINAL_LIBRARY_H
#define FINAL_LIBRARY_H


#include "ArrayList.h"

class Library {
private:
    ArrayList* playList;
    ArrayList* songList;
    int numOfPlaylists;
    int numOfSongs;
public:
    Library();
    ~Library();

    void addSongToList(std::string songName, std::string artist);
    void addSongToPlaylist(std::string songName, std::string playlistName);
    void createPlaylist(int numOfSongs, std::string playlistName);
    void deletePlaylist(std::string playlistName);
    void createRandomPlaylist(int numOfSongs, std::string playlistName);
};

#endif //FINAL_LIBRARY_H
