//
// Created by mgfir on 12/17/2018.
//
#import "Library.h"

int main(){
    Library* test= new Library();
    test->createLibrary("Sample.csv");
    test->createRandomPlaylist(12, "butts");
    std::cout<<test->printPlaylists()<<std::endl;
    std::cout<<test->printPlaylistInfo("butts")<<std::endl;
    return 0;
}
