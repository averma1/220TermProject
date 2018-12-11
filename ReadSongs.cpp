//
// Created by mgfir on 11/30/2018.
//
#include<iostream>
#include<fstream>
#include<istream>
#include"Song.h"
#include"ReadSongs.h"

/*
 * Song.cpp Playlist.cpp Tests.cpp ArrayList.inl TestLib.cpp
 * use ios::app to append to the file rather than rewrite
 * */



void addSongToLibrary(std::string fileName){



}

std::istream& operator>>(std::ifstream infile, Song()){



}


int main(){

    std::string fileName = "input.txt"; //will change this to be user input in interface
    std::ifstream infile(fileName);

    if(!infile){
        std::cerr<<"text file could not be opened for reading"<<std::endl;
    }



    /*

    std::ifstream infile("test.txt");

    //change the above to be entered by the user
    if(!infile){
        std::cerr<<"text file could not be opened for reading?"<<std::endl;
    }


    infile.close();
    outfile.close();

    */


    //function to read in info on new songs to be added to library
    //function to read in info on songs to REMOVE from library

    return 0;

}