//
// Created by Aine on 12/9/2018.
//
#include "iostream"
#include "Library.h"

int main(){
    Library* mainLibrary= new Library;

    std::cout<<"Welcome to the C++ DJ!"<<std::endl;
    std::cout<<"Please choose a command"<<std::endl;
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

    int choice;
    while(choice!=14) {
        std::cin >> choice;
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
            std::cin>> artist;
            std::cout<<mainLibrary->printSongsByArtist(artist)<<std::endl;
        }
        else if (choice == 4) {
            std::string song;
            std::cout<<"What song's info do you want to see:"<<std::endl;
            std::cin>> song;
            std::cout<<mainLibrary->printSongInfo(song)<<std::endl;
        }
        else if (choice == 5 || choice==6) {
            std::string file;
            std::cout<<"What is the name of the file you want to import:"<<std::endl;
            std::cin>> file;
            mainLibrary->readFile(file);
        }
        else if (choice == 7) {
            std::cout<<mainLibrary->printPlaylists()<<std::endl;
        }
        else if (choice == 8) {
            std::string playlist;
            std::cout<<"What is the name of the playlist you want information on:"<<std::endl;
            std::cin>> playlist;
            std::cout<<mainLibrary->printPlaylistInfo(playlist)<<std::endl;
        }
        else if (choice == 9) {
            std::string playlist;
            std::cout<<"What is the name of the playlist you want to create:"<<std::endl;
            std::cin>> playlist;
            int length;
            std::cout<<"How many songs long is it:"<<std::endl;
            std::cin>> length;
            mainLibrary->createPlaylist(length,playlist);
        }
        else if (choice == 10) {
            std::string playlist;
            std::cout<<"What is the name of the playlist you want to add to:"<<std::endl;
            std::cin>> playlist;
            std::string song;
            std::cout<<"What is the name of the song you want to add:"<<std::endl;
            std::cin>> song;
            mainLibrary->addSongToPlaylist(song,playlist);
        }
        else if (choice == 11) {
            std::string playlist;
            std::cout<<"What is the name of the playlist you want to change:"<<std::endl;
            std::cin>> playlist;
            std::string song;
            std::cout<<"What is the name of the song you want to remove:"<<std::endl;
            std::cin>> song;
            mainLibrary->removeSongToPlaylist(song,playlist);
        }
        else if (choice == 12) {
            std::string playlist;
            std::cout<<"What is the name of the playlist you to play:"<<std::endl;
            std::cin>> playlist;
            mainLibrary->playPlaylist(playlist);
            std::string contin;
            while(contin!="no"){
                mainLibrary->playPlaylist(playlist);
                std::cout<<"Would you like to play next:"<<std::endl;
                std::cin>> contin;
            }
        }
        else if (choice == 13) {
            std::string playlist;
            std::cout<<"What is the name of the playlist you want to create:"<<std::endl;
            std::cin>> playlist;
            int length;
            std::cout<<"How many songs long is it:"<<std::endl;
            std::cin>> length;
            mainLibrary->createRandomPlaylist(length,playlist);
        }
        std::cout<<"What would you like to do next:"<<std::endl;
    }
    std::cout<<"Thank you for using the C++ DJ!"<<std::endl;
    std::cout<<"Everything that has transpired has been saved to your files."<<std::endl;
}

