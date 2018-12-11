//
// Created by stgte on 11/29/18.
//
#include <iostream>
#include "TestLib.h"
#include "Song.h"
#include "Playlist.h"
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
    playlist1->rename("playlist2");
    printAssertEquals("playlist2", playlist1->getName());

    playlist1->addSong(song1);

    playlist1->addSong(song2);

    printAssertEqualsDouble(2+33.333340,playlist1->getDuration());


    Playlist* playlist2=new Playlist("playlist2");
    printAssertEquals("playlist2", playlist2->getName());
    playlist2->rename("playlist5");
    printAssertEquals("playlist5", playlist2->getName());

    playlist2->addSong(song1);

    playlist2->addSong(song2);

    printAssertEqualsDouble(2+33.333340,playlist2->getDuration());

    playlist1->playNext();
    printAssertEqualsDouble(33.333340,playlist1->getDuration());

   // playlist1->removeSong(song1);
    //printAssertEqualsDouble(33.333340,playlist1->getDuration());

    playlist1->addSong(song2);
    printAssertEqualsDouble(33.333340*2,playlist1->getDuration());

    playlist1->rename("newName");
    printAssertEquals("newName", playlist1->getName());
}

void printSongsFromPlaylist(){
    Song* song1= new Song("name1", "title1", 2);

    Song* song2=new Song("name2","title2", 33.333340);

    Playlist* playlist1=new Playlist("playlist1");

    playlist1->addSong(song1);

    playlist1->addSong(song2);

    printAssertEquals("{title1, title2}", playlist1->getSongList());





}


void createLibrarytest(){
    std::cout << "-------createLibraryTest---------" <<std::endl;
    Library* library1=new Library();
    library1->addSongToList("Moss", "someone", 3.50);
    library1->createPlaylist(2, "newPlaylist");
    //library1->addSongToPlaylist("Moss", "newPlaylist");
    printAssertEquals(true, library1->isSonginList("Moss"));
    std::cout<<library1->libraryString()<<std::endl;
}



int main(){
    //createSongAndPlaylistTest();
    printSongsFromPlaylist();

   //createLibrarytest();

}
