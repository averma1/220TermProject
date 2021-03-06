//
// Created by Anika on 11/20/18.
// Purpose: Store all information about songs and what can be done with/to them
//

#ifndef TERMPROJECT_SONG_H
#define TERMPROJECT_SONG_H

#include<iostream>

class Song{

private:
    std::string artist;
    std::string title;
    double duration;
    int playCount; //number of times we played the song

public:
    Song(std::string artist, std::string title, double duration);
    Song();
    void addToPlayCount();
    std::string getName();
    std::string getArtist();
    int getPlayCount();
    double getDuration();
    std::string getSongInfo();
    std::string getSongInfoForFile();
};



#endif //TERMPROJECT_SONG_H
