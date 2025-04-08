#ifndef Column_H
#define Column_H
#include "image.h"
#include "Music.h"

struct Column{
void InitOne();
void Init();
void MoveColumn(SDL_Rect BirdPosition,bool &Check,int &Point);
void ColumnLocation(int rand,int Point);
void RenderColumn();
};


#endif
