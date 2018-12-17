//
// Created by Aine on 12/9/2018.
// Purpose: Interact with the user and make changes to files based on their input
//


#include "iostream"
#include "Library.h"
#include <stdio.h>


int main(){
    Library* mainLibrary= new Library;
    mainLibrary->createLibrary("SampleNew.csv");

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


    std::string choice = "0";

    std::cout<<"Please choose a command by entering a number: "<<std::endl;


    while(choice != "14"){
        getline(std::cin, choice);

        int fail=0;
        while(1) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "PLEASE do not enter letters. Try again:" << std::endl;
                std::cin>>choice;
            } if(!std::cin.fail()){
                break;
            }
        }
        if (choice == "1") {
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

        else if (choice == "2") {
            try {
                std::cout << mainLibrary->libraryString() << std::endl;
            }
            catch(std::invalid_argument& e){
                std::cout<<"Sorry, an error occured. Please try again. "<<std::endl;
            }
        }

        else if (choice == "3") {
            std::string artist;
            std::cout<<"What artist's songs would you like to see? "<<std::endl;
            getline(std::cin, artist);
            try {
                std::cout << mainLibrary->printSongsByArtist(artist) << std::endl;
            } catch (std::invalid_argument e){
                std::cout<<"Sorry, that artist's songs are not in the library. "<<std::endl;
            }
        }

        else if (choice == "4") {
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

        else if (choice == "5") {
            std::string file;
            std::string option;
            std::cout<<"What is the name of the file you want to import? "<<std::endl;
            getline(std::cin, file);
            std::cout<<"Does your file contain playlists, songs, or both?"<<std::endl;
            getline(std::cin, option);
            if(option == "Playlists" || option == "playlists"){
                try {
                    mainLibrary->createLibraryPlaylists(file);
                } catch (std::invalid_argument& e) {
                    std::cout<<"Sorry, that file could not be opened. Please try another file."<<std::endl;
                }
            }
            else if(option == "Songs" || option == "songs"){
                try {
                    mainLibrary->createLibrarySongs(file);
                } catch (std::invalid_argument& e) {
                    std::cout<<"Sorry, that file could not be opened. Please try another file."<<std::endl;
                }
            }
            else if(option == "Both" || option == "both"){
                try {
                    mainLibrary->createLibrary(file);
                } catch (std::invalid_argument& e) {
                    std::cout<<"Sorry, that file could not be opened. Please try another file."<<std::endl;
                }
            }
            else{
                std::cout<<"Sorry, that's not an option."<<std::endl;
            }


        }

        else if(choice == "6"){
            std::string file;
            std::cout<<"What is the name of the file you want to import for removal? "<<std::endl;
            getline(std::cin, file);
            try {
                mainLibrary->removeDuplicatesongs(file);
            } catch (std::invalid_argument& e) {
                std::cout<<"Sorry, that file could not be opened. Please try another file."<<std::endl;
            }

        }

        else if (choice == "7") {
            std::cout<<mainLibrary->printPlaylists()<<std::endl;
        }

        else if (choice == "8") {
            std::string playlist;
            std::cout<<"What is the name of the playlist you want information on? "<<std::endl;
            getline(std::cin, playlist);
            try {
                std::cout<<mainLibrary->printPlaylistInfo(playlist)<<std::endl;
            } catch (std::invalid_argument& e) {
                std::cout<<"Sorry, that playlist doesn't exist."<<std::endl;
            }
        }

        else if (choice == "9") {
            std::string playlistName;
            int length;
            std::cout<<"What is the name of the playlist you want to create? "<<std::endl;
            getline(std::cin, playlistName);
            mainLibrary->createPlaylist(playlistName);
        }

        else if (choice == "10") {
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
                std::cout<<"Sorry, an error occurred. "<<std::endl;
            }
        }

        else if (choice == "11") {
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
        else if (choice == "12") {
            std::string playlist;
            std::string contin;
            std::cout<<"What is the name of the playlist you want to play:"<<std::endl;
            getline(std::cin, playlist);
            try {
                std::cout<<"Songs Played:"<<std::endl;
                std::cout<<mainLibrary->playPlaylist(playlist)<<std::endl;
            } catch (std::invalid_argument& e) {
                std::cout<<"Sorry, that playlist doesn't exist. "<<std::endl;
            }
            std::cout<<"Would you like to play next? "<<std::endl;
            getline(std::cin, contin);

            while(contin != "no" || contin != "No"){
                std::cout << mainLibrary->playPlaylist(playlist) << std::endl;
                std::cout << "Would you like to play next? " << std::endl;
                getline(std::cin, contin);
                if(contin == "no" || contin == "No"){
                    break;
                }
            }
        }

        else if (choice == "13") {
            std::string playlist;
            int length;
            std::cout<<"What is the name of the playlist you want to create? "<<std::endl;
            getline(std::cin, playlist);
            std::cout<<"How many songs long is it? "<<std::endl;
            std::cin>>length;
            std::cin.ignore();
            try {
                mainLibrary->createRandomPlaylist(length, playlist);
            } catch(std::invalid_argument e) {
                std::cout<<"That Playlist already exists, or there are not enough songs. "<<std::endl;
            }
        }

        if(choice != "14"){
            std::cout<<"Enter next choice:"<<std::endl;
        }


    }

    std::string file;
    std::cout<<"What is the name of the file you want to save your library to? "<<std::endl;
    getline(std::cin, file);
    mainLibrary->writeLibraryToFile(file);
    std::cout<<"All your activity has been saved to your file."<<std::endl;
    std::cout<<"Thank you for using the C++ DJ! "<<std::endl;

}

