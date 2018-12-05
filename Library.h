//
// Created by Aine on 11/23/2018.
//

#ifndef FINAL_LIBRARY_H
#define FINAL_LIBRARY_H


#include "ArrayList.h"
#include "Song.h"
#include "Playlist.h"

class Library {
private:
    ArrayList<Playlist>* playListList;
    ArrayList<Song>* songList;
    int numOfPlaylists;
    int numOfSongs;
public:
    Library();
    ~Library();

    void addSongToList(std::string songName, std::string artist, double duration);
    void addSongToPlaylist(std::string songName, std::string playlistName);
    void createPlaylist(int numOfSongs, std::string playlistName);
    void deletePlaylist(std::string playlistName);
    void createRandomPlaylist(int numOfSongs, std::string playlistName);
    bool isSonginList(std::string songName);
    void removeSongToPlaylist(std::string songName, std::string playlistName);
    std::string libraryString();
};

#endif //FINAL_LIBRARY_H
