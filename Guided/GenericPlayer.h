#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H
/* 

the Abstract player class

*/
class GenericPlayer
      {
	public:
	      virtual void play()=0;//pure virtual method play 
	      virtual void load()=0;//pure virtual method load
       	      virtual void setPlayerDefault() = 0;
       	      virtual void updatePlayer() = 0;
       	      virtual void controlPlayer() = 0;
       	      virtual void checkNplayNext() = 0;
	      
};
#endif
