#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "GenericPlayer.h"
#include <iostream>
#include <string>
using namespace std;

/*
This Class Creates the list of songs in a file called playlist.m3u(a file formate for music players)
*/
class Playlist{
	
	private:
	
	//An instantiation of of the genericPlayer.
	 GenericPlayer* player;
	 
	public:
	
	      void load(char*);//this is for creating  the playlist and loading songs
	      void playsong();// this calls the player from another class mainly for playing songs
	
	      Playlist(GenericPlayer *);//Constructor
};

#endif