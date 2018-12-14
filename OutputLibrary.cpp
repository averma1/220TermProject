//
// Created by Anika Verma on 12/9/18.
//
#include<iostream>
#include<fstream>
#include<ostream>


template <typename T>
int checkInput(){
    T choice;
    std::cin>>choice;
    std::cin.ignore();
    std::cout<<typeid(choice).name()<<std::endl;
    return -1;
}


