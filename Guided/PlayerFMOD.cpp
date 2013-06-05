
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include "../inc/fmod.hpp"
#include "../common/wincompat.h"
#include "../inc/fmod_errors.h"

#include "PlayerFMOD.h"
/*
An error checking method 

*/
void PlayerFMOD::ERRCHECK(FMOD_RESULT result)

{
    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        exit(-1);
    }
}

/*
the load method using an Object of the playlist class makes the list for play.
*/
void PlayerFMOD::load()
{

setPlayerDefault();
if (isplaylist)
    {
        printf("PLAYLIST loaded....Music Plays soon\n");
        
        
            cout<<"    *********************DeaconPlayer************************* \n";
            cout<<"8                 *   *   *   *    *                           8\n";
            cout<<"8                   *   *   *   *    *    *                    8\n";
            cout<<"8             <<<<<<<<<<<<CONTROLS>>>>>>>>>>>>>>>>>            8\n";
            cout<<"8                                                              8\n";
            cout<<"8 *Pause(space)-*Shuffle(s)-*Mute(m)-*Next/Prev(n/b)-*Reset(r) 8\n";
            cout<<"8              VOLUME:*Up(u)- *Down(j)                         8\n";
            cout<<"8                       QUIT(q)                                8\n";
            cout<<"8______________________________________________________________8\n";
        /*
            Get the first song in the playlist, create the sound and then play it.
        */
        result = playlist->getTag("FILE", count, &tag);
        ERRCHECK(result);

        sprintf(file,"tracks/%s", (char *)tag.data);
        result = system->createSound(file, FMOD_DEFAULT, 0, &sound1);
        ERRCHECK(result);
      
        result = system->playSound(FMOD_CHANNEL_FREE, sound1, false, &channel);
        ERRCHECK(result);

        playlist->getTag("TITLE", count, &tag);
        title = (char *)tag.data;

        count++;
    }
    
}
/*
The Play method : makes use of the Load,update,settings and the playlist class

*/
void PlayerFMOD::play()
{
load();

    /*
        Main loop.
    */
    do
    {
        
         checkNplayNext();
          controlPlayer();
           updatePlayer();

        Sleep(10);

    } while (key != 27);
     
    printf("\n");


}
//Set the player up for playlist
void PlayerFMOD::setPlayerDefault(){
	
/*
        Global Settings
    */
    result = FMOD::System_Create(&system);
   ERRCHECK(result);

    result = system->init(32, FMOD_INIT_NORMAL, NULL);
    ERRCHECK(result);

    result = system->createSound("tracks/playlist.m3u", FMOD_DEFAULT, 0, &playlist);
    ERRCHECK(result);
 result = playlist->getFormat(&soundtype, 0, 0, 0);  
    ERRCHECK(result);
isplaylist = (soundtype == FMOD_SOUND_TYPE_PLAYLIST);


}
/*
This funtion updates the user with the current state of the player whiles play is in session.

*/
 void PlayerFMOD::updatePlayer(){
 system->update();

        {
            unsigned int ms = 0;
            unsigned int lenms = 0;
            bool         paused = 0;

            if (channel)
            {
                if (sound1)
                {
                    result = sound1->getLength(&lenms, FMOD_TIMEUNIT_MS);
                    if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE) && (result != FMOD_ERR_CHANNEL_STOLEN))
                    {
                        ERRCHECK(result);
                    }
                }

                result = channel->getPaused(&paused);
                if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE) && (result != FMOD_ERR_CHANNEL_STOLEN))
                {
                    ERRCHECK(result);
                }

                result = channel->getPosition(&ms, FMOD_TIMEUNIT_MS);
                if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE) && (result != FMOD_ERR_CHANNEL_STOLEN))
                {
                    ERRCHECK(result);
                }
            }
            
            printf("\rTime %02d:%02d:%02d/%02d:%02d:%02d : %s : %s", ms / 1000 / 60, ms / 1000 % 60, ms / 10 % 100, lenms / 1000 / 60, lenms / 1000 % 60, lenms / 10 % 100, paused ? "Paused " : "Playing ", title);
            fflush(stdout);

        }
 }
 
 
 /*
 
 This method does the control of the player
 pause(space),Reset(r),NextSong(n),Shuffle(s),Volumecontrols-up(u) down(j).
 previous(p),mute(m),quit(q)
 
 */

void PlayerFMOD::controlPlayer()
{
	
	
	if (kbhit())
        {
            key = getch();

            switch (key)
            {
                case 'n' :
                {
                    /*
                        Play the next song in the playlist
                    */
                    if (channel && isplaylist)
                    {
                        channel->stop();
                    }

                    break;
                }
                case 'r' :
                {
                    /*
                        Reset Play 
                    */
                    if (channel && isplaylist)
                    {
                        channel->stop();
                    }
                    count--;
                    break;
                }
                case 's' :
                {
                    /*
                        Shuffle Play 
                    */
                    if (channel && isplaylist)
                    {
                        channel->stop();
                    }
                    srand(time(NULL));
                  
                    count=count-count%rand();
                    break;
                }
                case 'b' :
                {
                    /*
                        Play the previous song in the playlist
                    */
                    if (channel && isplaylist)
                    {
                        channel->stop();
                    }
                    count=count-2;
                    break;
                }
                
                case 'm' ://mute song
                {
                    bool isplaying;
                    channel->isPlaying(&isplaying);
                    if(isplaying)
                    {
                        bool mute;
                        
                        channel->getMute(&mute);
                     
                        channel->setMute(!mute);
                        break;
                    }
                }
                
                case 'u'://Increase volume
                {
                    bool isplaying;
                    channel->isPlaying(&isplaying);
                    if(isplaying)
                    {
                        float volume;
                        
                        channel->getVolume(&volume);
                     
                        channel->setVolume((volume+0.1f));
                        break;
                    }
                }
                case 'q' :
                {
                    /*
                        QUIT 
                    */
                    
                    exit(0);
                    break;
                }
                
                
                case 'j'://Decrease volume
                {
                    bool isplaying;
                    channel->isPlaying(&isplaying);
                    if(isplaying)
                    {
                        float volume;
                        
                        channel->getVolume(&volume);
                        channel->setVolume((volume-0.1f));
                        break;
                    }
                }
                
                 case ' ' ://Pause
                {
                    if (channel)
                    {
                        bool paused;

                        channel->getPaused(&paused);
                        channel->setPaused(!paused);
                    }
                }
            }
        }
}
/*
This method checks the for the end of the track and move to the next

*/
void PlayerFMOD::checkNplayNext()

{
	bool  isplaying = false;
	if (channel && isplaylist)
        {
            /*
                When sound has finished playing, play the next sound in the playlist
            */

            channel->isPlaying(&isplaying);
            if (!isplaying)
            {
                if (sound1)
                {
                    sound1->release();

                    sound1 = NULL;
                }

                result = playlist->getTag("FILE", count, &tag);
                if (result != FMOD_OK)
                {
                    count = 0;
                }
                else
                {
                    printf("\nplaying next song in playlist...\n");
                    sprintf(file,"tracks/%s", (char *)tag.data);
                    result = system->createSound(file, FMOD_DEFAULT, 0, &sound1);
                    ERRCHECK(result);

                    result = system->playSound(FMOD_CHANNEL_FREE, sound1, false, &channel);
                    ERRCHECK(result);

                    playlist->getTag("TITLE", count, &tag);
                    title = (char *)tag.data;

                    count++;
                }
        
            }
        }
}



//constructor
PlayerFMOD::PlayerFMOD(){
           system=0;
           channel = 0;
           playlist=0;
           sound1=0;
           isplaylist=false;
           count=0;
           title=NULL;
           file= new char [128];
           volume=0.0;
           muted=false;
           }
           
           /*
           Destructor
           
           */
           
PlayerFMOD::~PlayerFMOD(){
            
result = playlist->release();
        
 result = system->close();
 result = system->release();

   }
