//
// Created by mgfir on 11/30/2018.
//

#ifndef INC_220TERMPROJECT_LIBRARYFILES_H
#define INC_220TERMPROJECT_LIBRARYFILES_H

#include<iostream>
#include<istream>
#include<fstream>
#include"ReadFiles.h"
#include"Song.h"

class ReadSongs: public ReadFiles {

private:
    std::ifstream infile;
    std::string songInfo;

public:
    void removeSong(std::string fileName);
    void addSong(std::string fileName);
    void reloadLibrary(std::string fileName);
    friend std::istream& operator>>(std::ifstream infile, Song());

};

#endif //INC_220TERMPROJECT_LIBRARYFILES_H
