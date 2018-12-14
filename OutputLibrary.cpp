//
// Created by Anika Verma on 12/9/18.
//
#include<iostream>
#include<fstream>
#include<ostream>
#include "Library.h"


/*
std::ofstream writeLibraryToFile(){

    std::ofstream outfile("output.csv"); //change to text
    //outfile.open();
    if(!outfile){
        throw std::invalid_argument("file could not be opened for writing");
    }

    for(int i = 0; i < numOfPlaylists; i++){
        Playlist* current = playListList->getValueAt(i);
        outfile << "Title: " + current->getName();
        outfile << " Artist: " + current->getArtist();
        outfile << " Duration: " + current->getDuration()<<std::endl;

    }
    //outfile.close();

    return outfile;

}
 */

int main(){
    Library* mainLibrary= new Library;
    mainLibrary->createLibrarySongs("SongsDU.csv");
    std::cout<<"done"<<std::endl;

    return 0;


//    Library* library = new Library();
//    library->createPlaylist("myPlaylist");
//    library-addSongToPlayList("Beautiful", "myPlaylist");
//
//    std::string fileName = "Sample.csv"; //will change this to be user input in interface
}