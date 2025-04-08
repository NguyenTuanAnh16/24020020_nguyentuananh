#ifndef Bird_H
#define Bird_H
#include "image.h"
#include "Music.h"
struct Bird{

 void Init();
 SDL_Texture* BirdRepeat(Uint32 Time,Uint32 &Intermediary); // lap anh chim
 SDL_Rect  BirdPosition(); // kich thuoc chim
 void update(SDL_Rect &Weight,int &BirdJump,int &Angle,int &Location); // do roi chim
};

#endif
