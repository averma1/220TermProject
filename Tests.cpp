//
// Created by stgte on 11/29/18.
//
#include <iostream>
#include "TestLib.h"
#include "Song.h"
#include "Playlist.h"
#include "LibraryMain.h"
#include "Library.h"



/*Can you create a song
        Can you add it to the library
Can you make a playlist
        Can you add multiple songs to it
Can you add multiple songs to the library
Are they in alphabetical order
        Can you save the library when the user puts in ‘quit’
Does file i/o work
 **/
void createSongAndPlaylistTest(){
    std::cout << "-------createSongAndPlaylistTest---------" <<std::endl;
    Song* song1= new Song("name1", "title1", 2);
    printAssertEquals("title1", song1->getName());
    printAssertEquals("name1", song1->getArtist());
    printAssertEquals(2, song1->getDuration());

    Song* song2=new Song("","", 33.333340);
    printAssertEquals("", song2->getName());
    printAssertEquals("", song2->getArtist());
    printAssertEqualsDouble(33.333340, song2->getDuration());

    Playlist* playlist1=new Playlist("playlist1");
    printAssertEquals("playlist1", playlist1->getName());


}


int main(){
    createSongAndPlaylistTest();

}
