#ifndef IMAGE_H
#define IMAGE_H
#include "Configuration.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

struct Image{
       void RenderCopyEx(SDL_Texture* ImageBird,SDL_Rect BirdPosition,int Degree); // anh xoay
       void init();
       void RenderCopy(SDL_Texture* Image);// copy anh
       void RenderTexture(SDL_Texture *Image,SDL_Rect Size);  // copy anh tai mot vi tri
       void RenderPresent(); // tai anh len cua so
       void EvenMouse(bool &Check); // vong lap
       void FreePhoto(SDL_Texture* Image); // giai phong anh
       SDL_Texture *ImageTransfer(const char *FileName);  //chuyen anh thanh file
       void RenderClear(); // xoa anh
       void RenderCopy1(SDL_Texture* Image,SDL_Rect SizeOne,SDL_Rect SizeTwo);
       SDL_Rect ImageSize(SDL_Texture *Image,int Size);  // imagesize tinh kich co anh dua anh ve giua
};
#endif // _DEFS_H
