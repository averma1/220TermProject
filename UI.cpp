//
// Created by Aine on 12/9/2018.
//
#include "iostream"
#include "Library.h"
#include <stdio.h>

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
    std::cout<<"Please choose a command by entering a number: "<<std::endl;

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
            std::cout<<"What artist's songs would you like to see? "<<std::endl;
            getline(std::cin, artist);
            try {
                std::cout << mainLibrary->printSongsByArtist(artist) << std::endl;
            } catch (std::invalid_argument e){
                std::cout<<"Sorry, that song is not in the library. "<<std::endl;
            }
        }

        else if (choice == 4) {
            std::string song;
            std::string artist;
            std::cout<<"What song's info do you want to see? Please enter the song, then the artist name:"<<std::endl;
            getline(std::cin, song);
            getline(std::cin, artist);
            try {
                std::cout<<mainLibrary->printSongInfo(song, artist)<<std::endl;
            } catch (std::invalid_argument& e) {
                std::cout<<"Sorry, we could not find that song."<<std::endl;
            }
        }

        else if (choice == 5) {
            std::string file;
            std::cout<<"What is the name of the file you want to import? "<<std::endl;
            getline(std::cin, file);
            try {
                mainLibrary->readFile(file);
            } catch (std::invalid_argument& e) {
                std::cout<<"Sorry, that file could not be opened. Please try another file."<<std::endl;
            }
        }

        else if(choice==6){
            std::string file;
            std::cout<<"What is the name of the file you want to import? "<<std::endl;
            getline(std::cin, file);
            try {
                mainLibrary->removeDuplicatesongs(file);
            } catch (std::invalid_argument& e) {
                std::cout<<"Sorry, that file could not be opened. Please try another file."<<std::endl;
            }

        }

        else if (choice == 7) {
            std::cout<<mainLibrary->printPlaylists()<<std::endl;
        }

        else if (choice == 8) {
            std::string playlist;
            std::cout<<"What is the name of the playlist you want information on? "<<std::endl;
            getline(std::cin, playlist);
            try {
                std::cout<<mainLibrary->printPlaylistInfo(playlist)<<std::endl;
            } catch (std::invalid_argument& e) {
                std::cout<<"Sorry, that playlist doesn't exist."<<std::endl;
            }
        }

        else if (choice == 9) {
            std::string playlistName;
            int length;
            std::cout<<"What is the name of the playlist you want to create? "<<std::endl;
            getline(std::cin, playlistName);
            std::cout<<"How many songs long is it:"<<std::endl;
            std::cin>>length;
            std::cin.ignore();
            mainLibrary->createPlaylist(playlistName);
        }

        else if (choice == 10) {
            std::string playlist;
            std::string artist;
            std::string song;
            std::cout<<"What is the name of the playlist you want to add to? "<<std::endl;
            getline(std::cin, playlist);
            std::cout<<"What is the name of the song you want to add? "<<std::endl;
            getline(std::cin, song);
            std::cout<<"What is the artist of the song you want to add? "<<std::endl;
            getline(std::cin, artist);
            try {
                mainLibrary->addSongToPlaylist(song, artist, playlist);
            } catch (std::invalid_argument& e) {
                std::cout<<"Sorry, that playlist doesn't exist. "<<std::endl;
                std::cout<<"Please choose another playlist to add to. "<<std::endl;
            }
        }

        else if (choice == 11) {
            std::string playlist;
            std::string song;
            std::string artist;
            std::cout<<"What is the name of the playlist you want to remove from? "<<std::endl;
            getline(std::cin, playlist);
            std::cout<<"What is the name of the song you want to remove? "<<std::endl;
            getline(std::cin, song);
            std::cout<<"What is the artist of the song you want to remove? "<<std::endl;
            getline(std::cin, artist);
            try {
                mainLibrary->removeSongToPlaylist(song, artist, playlist);
            } catch (std::invalid_argument& e) {
                std::cout<<"Sorry, an error occurred while trying to remove the song from your playlist. "<<std::endl;
            }
        }
        else if (choice == 12) {
            std::string playlist;
            std::string contin;
            std::cout<<"What is the name of the playlist you want to play:"<<std::endl;
            getline(std::cin, playlist);
            try {
                mainLibrary->playPlaylist(playlist);
            } catch (std::invalid_argument& e) {
                std::cout<<"Sorry, that playlist doesn't exist. "<<std::endl;
            }
            while(contin != "no" || contin != "No"){
                mainLibrary->playPlaylist(playlist);
                std::cout<<"Would you like to play next? "<<std::endl;
                getline(std::cin, contin);
            }
        }

        else if (choice == 13) {
            std::string playlist;
            int length;
            std::cout<<"What is the name of the playlist you want to create? "<<std::endl;
            getline(std::cin, playlist);
            std::cout<<"How many songs long is it? "<<std::endl;
            std::cin>>length;
            std::cin.ignore();
            mainLibrary->createRandomPlaylist(length,playlist);
        }

        if(choice!=14) {
            std::cout << "What would you like to do next? " << std::endl;
        }

    }

    std::cout<<"Thank you for using the C++ DJ! "<<std::endl;
    std::cout<<"All your activity has been saved to your files."<<std::endl;
}

