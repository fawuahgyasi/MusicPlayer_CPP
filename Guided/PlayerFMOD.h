//PlayFMOD interface 
#ifndef PLAYERFMOD_H
#define PLAYERFMOD_H


#include "../inc/fmod.hpp"
#include "../common/wincompat.h"
#include "../inc/fmod_errors.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Playlist.h"
#include "GenericPlayer.h" 

using namespace std;

class PlayerFMOD: public GenericPlayer
{
      public:
      
      void ERRCHECK(FMOD_RESULT result);
      virtual void load();
      virtual void play();
      virtual void setPlayerDefault();
      virtual void updatePlayer();
      virtual void controlPlayer();
      virtual void checkNplayNext();
      ~PlayerFMOD();
      PlayerFMOD();

   private:

    FMOD::System     *system;
    FMOD::Sound      *sound1,*playlist;
    FMOD::Channel    *channel;
    FMOD_TAG          tag;
    FMOD_RESULT       result;
    FMOD_SOUND_TYPE   soundtype;
    bool              isplaylist,muted;
    int              count;
    char              *title;
    char             *file;
    char             key;
    float            volume;
   // Playlist*        playList;

};


#endif
