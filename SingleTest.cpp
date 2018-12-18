//
// Created by mgfir on 12/17/2018.
//
#import "Library.h"

int main(){
    Library* test= new Library();
    test->createLibrary("Sample.csv");
    test->createRandomPlaylistStart(12, "butts");
    std::cout<<test->printPlaylists()<<std::endl;
    std::cout<<test->printPlaylistInfo("butts")<<std::endl;

    std::cout<<""<<std::endl;
    test->createRandomPlaylistStart(12, "butts2");
    std::cout<<test->printPlaylists()<<std::endl;
    std::cout<<test->printPlaylistInfo("butts2")<<std::endl;

    std::cout<<""<<std::endl;
    test->createRandomPlaylistStart(30, "butts3");
    std::cout<<test->printPlaylists()<<std::endl;
    std::cout<<test->printPlaylistInfo("butts3")<<std::endl;
    return 0;
}
