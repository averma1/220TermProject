//
// Created by Molly on 11/23/2018.
//

#ifndef TERMPROJECT_PLAYLIST_H
#define TERMPROJECT_PLAYLIST_H
#include <string>

class Playlist{

private:
    std::string name;
    List songList;
    double duration;


public:
    Playlist(std::string nameIn);
    Playlist(); //default constructor
    ~Playlist();//destructor
    Playlist(const Playlist& playlistToCopy);//copy constructor
    Playlist& operator=(const Playlist& playlistToCopy);//assignment operator

    void addSong(Song songToAdd);
    void playNext();
    void removeSong(Song songToRemove);
    void rename(std::string newName);





};





#endif //TERMPROJECT_PLAYLIST_H
