//
// Created by Aine on 11/23/2018.
//Header file for the Library class
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
    int length;
public:
    Library();
    ~Library();
    Library(const Library & libraryToCopy);
    Library &operator=(const Library* & libraryToCopy);
    void addSongToList(std::string songName, std::string artist, double duration);
    void addSongToPlaylist(std::string songName, std::string artistName, std::string playlistName);
    void createPlaylist(std::string playlistName);
    void deletePlaylist(std::string playlistName);
    void createRandomPlaylist(int duration, std::string playlistName);
    void createRandomPlaylistStart(int playDuration, std::string playlistName);
    bool isSonginList(std::string songName,std::string artistName);
    bool isSongInplaylist(std::string songName, std::string artistName, std::string playlistName);
    void removeSongToPlaylist(std::string songName,std::string artistName,std::string playlistName);
    bool samePlaylists(Playlist* playlistName);
    std::string printPlaylists();
    std::string libraryString();
    std::string printSongsByArtist(std::string artist);
    std::string printSongInfo(std::string song,std::string artistName);
    List<std::string>* readFile(std::string file);
    void createLibrary(std::string file);
    std::string printPlaylistInfo(std::string playlist);
    std::string playPlaylist(std::string playlist);
    void removeDuplicatesongs(std::string file);
    void writeLibraryToFile(std::string file);
    void createLibrarySongs(std::string file);
    void createLibraryPlaylists(std::string file);
};

#endif //FINAL_LIBRARY_H
