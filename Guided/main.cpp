/*

Name: Frederick Awuah-Gyasi
Music Player Assignment.

API Used: FMODEx

Supervisor: Prof. V P Pauca.


*/


#include <iostream>
#include "Playlist.h"
#include "PlayerFMOD.h" 
#include <string>
using namespace std;

/* 
 Main funtion
          */

int main()
{
	int num;
	char *dirc;
	
	//Player Object
	PlayerFMOD *MyPlayer=new PlayerFMOD();
	
	//Playlist Object
	Playlist  *MyPlaylist= new Playlist(MyPlayer);
	
	
 while(true)
 {
 
 
cout<<"***************DeaconPlayer*******************\n";
cout<<"8                Menu                        8\n";
cout<<"8                                            8\n";
cout<<"8 1.Load                                     8\n";
cout<<"8 .********************                     8\n";
cout<<"8 2.Play                                     8\n";
cout<<"8******************************************* 8\n";
cout<<"8 3.EXIT                                     8\n";  


 cin>>num;
 
     switch (num)
     {
     
    case 1:
     {
     
     
           cout<<"$mediaPlayer:";
	       cin>>dirc;
           MyPlaylist->load(dirc);
           break;
           }
           
       case 2:
      {
          //Calling the Player after loading
        MyPlaylist->playsong();
        break;
      }
      
      case 3:
      {
         exit(0);
      
      }
      
       
      default: break;
     }
 }
 
 
	
	cout<<"Bye!";
	return 0;
}

