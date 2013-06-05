/*

Implementation of the Playlist class. The only function available now is the load funtions 
for creating the playlist.
*/



#include <iostream>
#include "Playlist.h"
#include <stdio.h>
#include <fstream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <dirent.h>
#include <string>

using namespace std;

/*
the method takes the directory and loads the 
file names into a playlist
only mp3 formate are accepted


*/
void Playlist::load(char* dirn)
{
	
        DIR *dir = NULL;
        struct dirent *drnt = NULL;
        ofstream outfile;
        
        dir=opendir(dirn);
        if(dir)
        {
            
                printf("LOADED:\n");
                while(drnt = readdir(dir))
                {
                        
	 
	 outfile.open("tracks/playlist.m3u",ios::app);
	 if(!outfile)
	 {
	 
	 cerr<< "Error: Playlist.m3u could not open";
	 }
	 string name;
	 name= (string)dirn + "/" + drnt->d_name;
	 
	 if(name.substr(name.find_last_of(".") + 1) == "mp3")
	 {
	 outfile<<"\n#EXT3U\n"<<"#EXTF:0,NewTrack\n"<<name<<endl;
	 }
	 outfile.close();
                }
                closedir(dir);
        }
        else
        {
                printf("Can not open directory '%s'\n", dirn);
        }

}


Playlist::Playlist(GenericPlayer *p)
{
	
	player=p;
}

void Playlist::playsong() {
	player -> play();
}

//================================================


/*
void Playerlist::addToPlaylist(string songDirectory)
{
	ofstream outfile;
	string tempDirectory;
	 tempDirectory=songDirectory;
	 
	 outfile.open("tracks/playlist.m3u",ios::app);
	 if(!outfile)
	 {
	 
	 cerr<< "Error: Playlist.m3u could not open";
	 }
	 
	 outfile<<"\n#EXT3U\n"<<"#EXTF:0,NewTrack\n"<<tempDirectory<<endl;
	 
	 outfile.close();
	
	
}

//================================================

void Playerlist::createNewList(string songDirectory)
{
	ofstream outfile;
	string tempDirectory;
	 tempDirectory=songDirectory;
	 
	 outfile.open("tracks/playlist.m3u");
	 if(!outfile)
	 {
	 
	 cerr<< "Error: Playlist.m3u could not open";
	 }
	 
	 outfile<<"\n#EXT3U\n"<<"#EXTF:0,NewTrack\n"<<tempDirectory<<endl;
	 
	 outfile.close();
	
	
}*/
