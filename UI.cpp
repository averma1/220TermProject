//
// Created by Aine on 12/9/2018.
//
#include "iostream"
#include "Library.h"
#include <stdio.h>


//add so that user can input multiple words for everything
//anything that involves songs also ask for artist
//anythign that throws an exception: print out whaz going on
//also: finish the write files
//test readfiles

int main(){
    Library* mainLibrary= new Library;
    mainLibrary->createLibrary("Sample.csv");

    std::cout<<"Welcome to the C++ DJ!"<<std::endl;
    std::cout<<"    1) Help (show this list again)"<<std::endl;
    std::cout<<"    2) Print Library of Songs"<<std::endl;
    std::cout<<"    3) Show Songs by Artist"<<std::endl;
    std::cout<<"    4) Display Song Information"<<std::endl;
    std::cout<<"    5) Import File"<<std::endl;
    std::cout<<"    6) Remove Songs Based on File"<<std::endl;
    std::cout<<"    7) Display all Playlist names"<<std::endl;
    std::cout<<"    8) Display Playlist information"<<std::endl;
    std::cout<<"    9) Create an empty Playlist"<<std::endl;
    std::cout<<"    10) Add Song to Playlist"<<std::endl;
    std::cout<<"    11) Remove Song From Playlist"<<std::endl;
    std::cout<<"    12) Play Playlist"<<std::endl;
    std::cout<<"    13) Create Random Playlist"<<std::endl;
    std::cout<<"    14) Leave DJ"<<std::endl;
    std::cout<<"Please choose a command by entering a number"<<std::endl;

    int choice;
    while(choice!=14) {
        std::cin >> choice;
        std::cin.ignore();
        if (choice == 1) {
            std::cout<<"    1) Help (show this list again)"<<std::endl;
            std::cout<<"    2) Print Library of Songs"<<std::endl;
            std::cout<<"    3) Show Songs by Artist"<<std::endl;
            std::cout<<"    4) Display Song Information"<<std::endl;
            std::cout<<"    5) Import File"<<std::endl;
            std::cout<<"    6) Remove Songs Based on File"<<std::endl;
            std::cout<<"    7) Display all Playlist names"<<std::endl;
            std::cout<<"    8) Display Playlist information"<<std::endl;
            std::cout<<"    9) Create an empty Playlist"<<std::endl;
            std::cout<<"    10) Add Song to Playlist"<<std::endl;
            std::cout<<"    11) Remove Song From Playlist"<<std::endl;
            std::cout<<"    12) Play Playlist"<<std::endl;
            std::cout<<"    13) Create Random Playlist"<<std::endl;
            std::cout<<"    14) Leave DJ"<<std::endl;
        }
        else if (choice == 2) {
            std::cout<<mainLibrary->libraryString()<<std::endl;
        }
        else if (choice == 3) {
            std::string artist;
            std::cout<<"What artist's songs would you like to see:"<<std::endl;
            getline(std::cin, artist);
        }
        else if (choice == 4) {
            std::string song;
            std::string artist;
            std::cout<<"What song's info do you want to see:"<<std::endl;
            std::cin>>song;
            std::cin.ignore();
            std::cout<<mainLibrary->printSongInfo(song)<<std::endl;
        }
        else if (choice == 5) {
            std::string file;
            std::cout<<"What is the name of the file you want to import:"<<std::endl;
            getline(std::cin, file);
            mainLibrary->readFile(file);
        }
        else if(choice==6){
            std::string file;
            std::cout<<"What is the name of the file you want to import:"<<std::endl;
            getline(std::cin, file);
            mainLibrary->removeDuplicatesongs(file);
        }
        else if (choice == 7) {
            std::cout<<mainLibrary->printPlaylists()<<std::endl;
        }
        else if (choice == 8) {
            std::string playlist;
            std::cout<<"What is the name of the playlist you want information on:"<<std::endl;
            getline(std::cin, playlist);
            std::cout<<mainLibrary->printPlaylistInfo(playlist)<<std::endl;
        }
        else if (choice == 9) {
            std::string playlistName;
            std::cout<<"What is the name of the playlist you want to create:"<<std::endl;
            getline(std::cin, playlistName);
            /* IMPORTANT - ask about parameters to createPlaylist
            int length;
            std::cout<<"How many songs long is it:"<<std::endl;
            std::cin>> length;
            std::cin.ignore();*/
            mainLibrary->createPlaylist(playlistName);

        }
        else if (choice == 10) {
            std::string playlist;
            std::cout<<"What is the name of the playlist you want to add to:"<<std::endl;
            getline(std::cin, playlist);
            std::string song;
            std::cout<<"What is the name of the song you want to add:"<<std::endl;
            getline(std::cin, song);
            mainLibrary->addSongToPlaylist(song,playlist);
        }
        else if (choice == 11) {
            std::string playlist;
            std::cout<<"What is the name of the playlist you want to change:"<<std::endl;
            getline(std::cin, playlist);
            std::string song;
            std::cout<<"What is the name of the song you want to remove:"<<std::endl;
            std::cin>> song;
            mainLibrary->removeSongToPlaylist(song,playlist);
        }
        else if (choice == 12) {
            std::string playlist;
            std::cout<<"What is the name of the playlist you want to play:"<<std::endl;
            getline(std::cin, playlist);
            mainLibrary->playPlaylist(playlist);
            std::string contin;
            while(contin != "no"){
                mainLibrary->playPlaylist(playlist);
                std::cout<<"Would you like to play next:"<<std::endl;
                getline(std::cin, contin);
            }
        }
        else if (choice == 13) {
            std::string playlist;
            std::cout<<"What is the name of the playlist you want to create:"<<std::endl;
            getline(std::cin, playlist);
            int length;
            std::cout<<"How many songs long is it:"<<std::endl;
            std::cin>>length;
            std::cin.ignore();
            mainLibrary->createRandomPlaylist(length,playlist);
        }
        if(choice!=14) {
            std::cout << "What would you like to do next:" << std::endl;
        }
    }
    std::cout<<"Thank you for using the C++ DJ!"<<std::endl;
    std::cout<<"Everything that has transpired has been saved to your files."<<std::endl;
}

