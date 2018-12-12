//
// Created by Anika Verma on 12/9/18.
//
#include<iostream>
#include<fstream>
#include "OutputLibrary.h"


std::ofstream writeLibraryToFile(){

    ofstream outfile(fileName); //change to text

    if(!outfile){
        throw("file could not be opened for writing");
    }

    for(int i = 0; i < numOfPlaylists; i++){
        Playlist* current = playListList->getValueAt(i);

    }



    return outfile;

}