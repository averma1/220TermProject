//
// Created by mgfir on 11/27/2018.
//

#ifndef INC_220TERMPROJECT_LIBRARYMAIN_H
#define INC_220TERMPROJECT_LIBRARYMAIN_H

#include "ArrayList.h"
#include "Song.h"
#include "Playlist.h"


class LibraryMain {
private:
    ArrayList<Playlist>* playListList;
    ArrayList<Song>* songList;
    int numOfPlaylists;
    int numOfSongs;
public:
    virtual ~LibraryMain()=0;

    virtual void addSongToList(std::string songName, std::string artist, double duration)=0;
    virtual void addSongToPlaylist(std::string songName, std::string playlistName)=0;
    virtual void createPlaylist(int numOfSongs, std::string playlistName)=0;
    virtual void deletePlaylist(std::string playlistName)=0;
    virtual void createRandomPlaylist(int numOfSongs, std::string playlistName)=0;
    virtual bool isSonginList(std::string songName)=0;
    virtual void removeSongToPlaylist(std::string songName, std::string playlistName)=0;
    virtual std::string libraryString()=0;
};

#endif //INC_220TERMPROJECT_LIBRARYMAIN_H
