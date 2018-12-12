//
// Created by mgfir on 11/30/2018.
//
#include<iostream>
#include<fstream>
#include <sstream>
#include "string.h"
#include "cstdlib"
#include "List.h"
#include "ArrayList.h"
#include <vector>

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

    //read the file to an ArrayList of strings called all
    std::ifstream infile("Sample.csv");
    if(!infile){
        std::cerr<<"text file could not be opened for reading"<<std::endl;
    }
    List<std::string>* all= new ArrayList<std::string>(10);
    int length= 0;
    while (infile.good()) {
        // read stuff from the file into a string and print it
        std::string strInput;
        getline(infile, strInput);
        all->insertAtEnd(strInput);
        length++;
    }

    infile.close();

    //break all up into playlists and songs
    std::string delimiter = ",";
    std::string token = all->getValueAt(1).substr(0, all->getValueAt(1).find(delimiter));
    Playlist* playlist1=new Playlist(token);
    std::cout<< playlist1->getName()<< std::endl;


    for(int i=6;i<13; i++){
        if(all->getValueAt(i)!=",,") {
            std::cout<<all->getValueAt(i)<<std::endl;
            std::string str = all->getValueAt(i);
            std::stringstream ss(str);
            std::vector<std::string> result;

            while (ss.good()) {
                std::string substr;
                getline(ss, substr, ',');
                result.push_back(substr);
            }

            std::string artist = result.at(1);
            std::string title = result.at(0);
            double duration = std::stod(result.at(2));

            Song *newsong = new Song(title, artist, duration);
            playlist1->addSong(newsong);

        } else if (all->getValueAt(i)==",,"){
            std::cout<<"new"<<std::endl;
            token = all->getValueAt(i+1).substr(0, all->getValueAt(i+1).find(delimiter));
            playlist1=new Playlist(token);
            std::cout<< playlist1->getName()<< std::endl;
        }
    }


    return 0;

}