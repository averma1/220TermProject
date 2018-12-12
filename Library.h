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
    List<Playlist*>* playListList;
    List<Song*>* songList;
    int numOfPlaylists;
    int numOfSongs;
public:
    Library();
    ~Library();

    void addSongToList(std::string songName, std::string artist, double duration);
    void addSongToPlaylist(std::string songName, std::string artistName, std::string playlistName);
    void createPlaylist(std::string playlistName);
    void deletePlaylist(std::string playlistName);
    void createRandomPlaylist(int numOfSongs, std::string playlistName);
    bool isSonginList(std::string songName,std::string artistName);
    bool isSongInplaylist(std::string songName, std::string artistName, std::string playlistName);
    void removeSongToPlaylist(std::string songName,std::string artistName,std::string playlistName);
    std::string printPlaylists();
    std::string libraryString();
    std::string printSongsByArtist(std::string artist);
    std::string printSongInfo(std::string song,std::string artistName);
    void readFile(std::string file);
    std::string printPlaylistInfo(std::string playlist);
    void playPlaylist(std::string playlist);
    void removeDuplicatesongs(std::string file);
    void writeLibraryToFile();
};

#endif //FINAL_LIBRARY_H
