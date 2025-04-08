#ifndef BackGround_H
#define BackGround_H
#include "image.h"
#include "Music.h"
#include "Configuration.h"

struct BackGround{
void StartBackGround(); // chay background chao mung
void MoveBackGround(SDL_Rect &Size1,SDL_Rect &Size2);// cuon anh background
};


#endif
