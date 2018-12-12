//
// Created by Anika Verma on 12/9/18.
//

#ifndef INC_220TERMPROJECT_OUTPUTLIBRARY_H
#define INC_220TERMPROJECT_OUTPUTLIBRARY_H
#include<iostream>
#include<fstream>
#include"Library.h"

class OutputLibrary {

private:
    std::string fileName;

public:
    std::ofstream writeLibraryToFile();

};


#endif //INC_220TERMPROJECT_OUTPUTLIBRARY_H
