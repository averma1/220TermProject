//
// Created by mgfir on 11/30/2018.
//
#include<iostream>
#include<fstream>
#include "string.h"
#include "cstdlib"

/*
 * Song.cpp Playlist.cpp Tests.cpp ArrayList.inl TestLib.cpp
 * use ios::app to append to the file rather than rewrite
 */


void addSongToLibrary(std::string myString){
    //must call toString before this: split up the info then add to library
    std::string artist;
    std::string title;
    double duration;
    std::string delimiter = ", ";
    std::string token;
    myString.substr();
    int pos = 0;
    while((pos = myString.find(delimiter)) != std::string::npos){

    }

    //addSongToList(title, artist, duration); //adding it to library

}




//std::istream& operator>>(std::ifstream infile, Song()){
//
//}


int main(){

    //std::string fileName = "Sample.csv"; //will change this to be user input in interface
    std::ifstream infile("Sample.txt");
    if(!infile){
        std::cerr<<"text file could not be opened for reading"<<std::endl;
    }
    while (infile.good()) {
        // read stuff from the file into a string and print it
        std::string strInput;
        infile>>strInput;
        std::cout << strInput << std::endl;
    }

    infile.close();

//    std::string artist;
//    std::string title;
//    double duration;
//    std::string delimiter = ", ";
//    std::string token;
//    myString.substr();
//    int pos = 0;
//    while((pos = myString.find(delimiter)) != std::string::npos){
//
//    }
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