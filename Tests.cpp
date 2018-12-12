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
    std::cout << "-------SongTest---------" <<std::endl;
    Song* song1= new Song("name1", "title1", 2);
    printAssertEquals("title1", song1->getName());
    printAssertEquals("name1", song1->getArtist());
    printAssertEquals(2, song1->getDuration());

    Song* song2=new Song("","", 33.333340);
    printAssertEquals("", song2->getName());
    printAssertEquals("", song2->getArtist());
    printAssertEqualsDouble(33.333340, song2->getDuration());

    Song* song3=new Song("name3","3title",4);
    printAssertEquals("3title", song3->getName());
    printAssertEquals("name3", song3->getArtist());
    printAssertEqualsDouble(4, song3->getDuration());

    printAssertEquals(0, song1->getPlayCount());
    printAssertEquals(0, song2->getPlayCount());
    printAssertEquals(0, song3->getPlayCount());



    std::cout << "-------PlaylistTest---------" <<std::endl;


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

    try{
        playlist1->removeSong(song1);
        std::cout << "FAIL:did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout<<("pass")<<std::endl;
    }
    printAssertEqualsDouble(33.333340,playlist1->getDuration());

    playlist1->addSong(song2);
    printAssertEqualsDouble(33.333340,playlist1->getDuration());

    playlist1->rename("newName");
    printAssertEquals("newName", playlist1->getName());

    Playlist* playlist3=new Playlist("playlist3");
    printAssertEquals("No songs in a playlist", playlist3->getSongList());

    printAssertEquals("{}",playlist1->getSongList());
    playlist1->addSong(song1);
    printAssertEquals("{, title1}",playlist1->getSongList());
    playlist1->playNext();
    printAssertEquals("{title1}",playlist1->getSongList());

}

void printSongsFromPlaylist(){
    std::cout << "-------printSongsFromPlaylist---------" <<std::endl;
    Song* song1= new Song("name1", "title1", 2);

    Song* song2=new Song("name2","title2", 5);

    Song* song3=new Song("3name","3title", 1);

    Playlist* playlist1=new Playlist("playlist1");

    playlist1->addSong(song1);

    playlist1->addSong(song2);

    printAssertEquals("{title1, title2}", playlist1->getSongList());

    playlist1->addSong(song3);
    printAssertEquals("{title1, title2, 3title}", playlist1->getSongList());

    playlist1->removeSong(song1);
    playlist1->removeSong(song3);

    printAssertEquals("{title2}", playlist1->getSongList());

    playlist1->removeSong(song2);

    printAssertEquals("No songs in a playlist", playlist1->getSongList());

}


void createLibrarytest(){
    std::cout << "-------LibraryTests---------" <<std::endl;
    Library* library=new Library();
    printAssertEquals("", library->printPlaylists());
    library->createPlaylist("newPlaylist");
    printAssertEquals("newPlaylist ", library->printPlaylists());
    printAssertEquals("Name: newPlaylist Duration: 0.000000 Songs: No songs in a playlist", library->printPlaylistInfo("newPlaylist"));

    library->createPlaylist("newPlaylist1");
    printAssertEquals("newPlaylist newPlaylist1 ", library->printPlaylists());
    printAssertEquals("Name: newPlaylist1 Duration: 0.000000 Songs: No songs in a playlist", library->printPlaylistInfo("newPlaylist1"));
    library->createPlaylist("newPlaylist2");
    printAssertEquals("newPlaylist newPlaylist1 newPlaylist2 ", library->printPlaylists());
    printAssertEquals("Name: newPlaylist2 Duration: 0.000000 Songs: No songs in a playlist", library->printPlaylistInfo("newPlaylist2"));
    library->createPlaylist("newPlaylist3");
    printAssertEquals("newPlaylist newPlaylist1 newPlaylist2 newPlaylist3 ", library->printPlaylists());
    printAssertEquals("Name: newPlaylist3 Duration: 0.000000 Songs: No songs in a playlist", library->printPlaylistInfo("newPlaylist3"));
    library->deletePlaylist("newPlaylist2");
    printAssertEquals("newPlaylist newPlaylist1 newPlaylist3 ", library->printPlaylists());

    library->deletePlaylist("newPlaylist1");
    printAssertEquals("newPlaylist newPlaylist3 ", library->printPlaylists());

    try{
        library->deletePlaylist("blah"); //should throw exception because playlist does not exist
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }

    try{
        library->printPlaylistInfo("newPlaylist5");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }
    //tests if it lets to createPlaylist with the same name
    try{
        library->createPlaylist("newPlaylist");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }

    //tests if non-existent song can be added
    try{
        library->addSongToPlaylist("Moss", "me","newPlaylist"); //does not throw exception when song is not in songlist
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }

    //tests isSonginList
    printAssertEquals(false, library->isSonginList("Moss","33"));

    library->addSongToList("Moss", "me", 3);
    printAssertEquals(true, library->isSonginList("Moss","me"));
    printAssertEquals("Artist: me Name: Moss Duration: 3.000000 Play count: 0",library->printSongInfo("Moss","me"));

    library->addSongToList("NO", "Yes", 2);
    printAssertEquals(true, library->isSonginList("NO","Yes"));
    printAssertEquals("Artist: Yes Name: NO Duration: 2.000000 Play count: 0",library->printSongInfo("NO","Yes"));

    printAssertEquals(false, library->isSonginList("Moss","33"));
    try{
        library->printSongInfo("Moss","33");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }

    library->addSongToList("Song1","Artist1",5);
    printAssertEquals(true,  library->isSonginList("Song1","Artist1"));
    printAssertEquals("Artist: Artist1 Name: Song1 Duration: 5.000000 Play count: 0",library->printSongInfo("Song1","Artist1"));

    library->addSongToList("","",0);
    printAssertEquals(true, library->isSonginList("",""));
    library->addSongToPlaylist("Moss", "me","newPlaylist");
    printAssertEquals("Name: newPlaylist Duration: 3.000000 Songs: {Moss}",library->printPlaylistInfo("newPlaylist"));




    try{
        library->addSongToPlaylist("Moss","me","Ff");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }
    try{
        library->addSongToPlaylist("none","me","newPlaylist");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }
    try{
        library->addSongToPlaylist("Moss","","Ff");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }
    try{
        library->addSongToPlaylist("Moss", "me","newPlaylist");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }

    try{
        library->removeSongToPlaylist("","me","newPlaylist");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }
    try{
        library->removeSongToPlaylist("Moss","me","none");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }
    try{
        library->removeSongToPlaylist("Moss","none","newPlaylist");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }
    try{
        library->playPlaylist("none");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }

    library->removeSongToPlaylist("Moss", "me", "newPlaylist");
    printAssertEquals("Name: newPlaylist Duration: 0.000000 Songs: No songs in a playlist",library->printPlaylistInfo("newPlaylist"));

    library->addSongToPlaylist("Moss", "me", "newPlaylist");
    printAssertEquals("Name: newPlaylist Duration: 3.000000 Songs: {Moss}",library->printPlaylistInfo("newPlaylist"));
    library->addSongToPlaylist("Song1","Artist1", "newPlaylist");
    printAssertEquals("Name: newPlaylist Duration: 8.000000 Songs: {Moss, Song1}",library->printPlaylistInfo("newPlaylist"));

    try{
        library->printSongsByArtist("none");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }
    printAssertEquals("Moss ",library->printSongsByArtist("me"));
    library->addSongToList("Kate", "me", 1);
    printAssertEquals("Moss Kate ",library->printSongsByArtist("me"));

    try{
        library->createRandomPlaylist(3, "newPlaylist");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }


    try{
        library->printPlaylistInfo("rand1");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::invalid_argument& e){
        std::cout <<"pass"<<std::endl;
    }



    try{
        library->createRandomPlaylist(300, "none");
        std::cout << "FAIL: did not throw exception" << std::endl;
    }
    catch(std::out_of_range& e){
        std::cout <<"pass"<<std::endl;
    }

    library->addSongToList("songNone", "singer", 3);

    printAssertEquals(false,library->isSongInplaylist("songNone", "singer", "newPlaylist"));

    //library->createRandomPlaylist(3, "rand1");


}



int main(){
    srand(time(NULL));
    createSongAndPlaylistTest();
    printSongsFromPlaylist();

    createLibrarytest();

}