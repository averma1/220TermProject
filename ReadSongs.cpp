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
#include "Library.h"

int main() {
    Library* FUCK= new Library();
    std::cout<<FUCK->checkInput()<<std::endl;
}

//int main(){
//
//    //read the file to an ArrayList of strings called all
//    std::ifstream infile("Sample1.txt");
//    if(!infile){
//        std::cerr<<"text file could not be opened for reading"<<std::endl;
//    }
//    List<std::string>* all= new ArrayList<std::string>(10);
//    int length= 0;
//    while (infile.good()) {
//        // read stuff from the file into a string and print it
//        std::string strInput;
//        getline(infile, strInput);
//        all->insertAtEnd(strInput);
//        length++;
//    }
//
//    infile.close();
//
//    //break all up into playlists and songs
//    std::string song="Songs,,\r";
//    int count=-1;
//    for(int i= 0; i<length; i++){
//        if(all->getValueAt(i)==song){
//            count=i;
//        }
//    }
//    std::cout<<count<<std::endl;
//
//
//    std::string delimiter = ",";
//    std::string death = all->getValueAt(0);
//    std::string token = all->getValueAt(2).substr(0, all->getValueAt(2).find(delimiter));
//    Playlist* playlist1=new Playlist(token);
//    std::cout<< playlist1->getName()<< std::endl;
//
//
//    for(int i=3;i<count-1; i++){
//        if (all->getValueAt(i) != death) {
//            std::string str = all->getValueAt(i);
//            std::stringstream ss(str);
//            std::vector<std::string> result;
//
//            while (ss.good()) {
//                std::string substr;
//                getline(ss, substr, ',');
//                result.push_back(substr);
//            }
//
//            std::string artist = result.at(1);
//            std::string title = result.at(0);
//            double duration = std::stod(result.at(2));
//
//            Song *newsong = new Song(artist, title, duration);
//            playlist1->addSong(newsong);
//            std::cout << playlist1->getDuration() << std::endl;
//
//        } else if (all->getValueAt(i) == death) {
//            i++;
//            token = all->getValueAt(i).substr(0, all->getValueAt(i).find(delimiter));
//            playlist1 = new Playlist(token);
//            std::cout << playlist1->getName() << std::endl;
//        }
//    }
//    for(int i=count+1; i<length; i++){
//        std::string str = all->getValueAt(i);
//        std::stringstream ss(str);
//        std::vector<std::string> result;
//
//        while (ss.good()) {
//            std::string substr;
//            getline(ss, substr, ',');
//            result.push_back(substr);
//        }
//
//        std::string artist = result.at(1);
//        std::string title = result.at(0);
//        double duration = std::stod(result.at(2));
//
//        Song *newsong = new Song(artist, title, duration);
//        std::cout<<newsong->getName()<<std::endl;
//    }
//
//
//    return 0;
//
//}