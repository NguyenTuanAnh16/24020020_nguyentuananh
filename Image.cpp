#include "image.h"

SDL_Window*     Window;
SDL_Renderer*   Renderer;
void Image::init() {
     Window=SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,WIDTH, HEIGHT, SDL_RENDERER_PRESENTVSYNC);
   Renderer= SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED);
}


// renderCopy copy file anh texture len cua so
void Image::RenderCopy(SDL_Texture* Image){
    SDL_RenderCopy(Renderer,Image,NULL,NULL);
}




// render texture : in anh tai mot vi tri
void Image::RenderTexture(SDL_Texture *Image,SDL_Rect Size){
    SDL_RenderCopy(Renderer,Image,NULL,&Size);
}




// RenderPresent cap nhap noi dung hien thi cua renderer len man hinh
void Image::RenderPresent(){SDL_RenderPresent(Renderer);}



// vong lap

void Image::EvenMouse(bool &Check){
    SDL_Event event;
    while (true) {
           SDL_PollEvent(&event);
           if(event.type==SDL_QUIT){Check=false;return ;}
           if(event.type==SDL_MOUSEBUTTONDOWN &&(505<=event.button.x && event.button.x<=750)&&(495<=event.button.y && event.button.y<=600)) return ;
           SDL_Delay(10);}
}


// free photo giai phong anh
void Image::FreePhoto(SDL_Texture* Image){
    SDL_DestroyTexture(Image);
    Image=NULL;
}



// image transfer : chuyen anh thanh file texture
SDL_Texture* Image::ImageTransfer(const char *FileName)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", FileName);
    SDL_Texture *Image = IMG_LoadTexture(Renderer, FileName);
    if (Image == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

    return Image;
}


void Image::RenderClear(){SDL_RenderClear(Renderer);}

void Image::RenderCopy1(SDL_Texture* Image,SDL_Rect Size1,SDL_Rect Size2){
      SDL_RenderCopy(Renderer,Image,&Size1,&Size2);

}
void Image::RenderCopyEx(SDL_Texture* ImageBird,SDL_Rect BirdPosition,int Degree){
  SDL_RenderCopyEx(Renderer,ImageBird,NULL,&BirdPosition, Degree, NULL, SDL_FLIP_NONE);
};

// imagesize tinh kich co anh dua anh ve giua
SDL_Rect Image::ImageSize(SDL_Texture *Image,int Size){
    SDL_Rect SizeImage;
    SDL_QueryTexture(Image,NULL,NULL,&SizeImage.w,&SizeImage.h);
    SizeImage.w=SizeImage.w/Size; SizeImage.h=SizeImage.h/Size;
    SizeImage.x=(WIDTH-SizeImage.w)/2;
    SizeImage.y=(HEIGHT-SizeImage.h)/2;
    return SizeImage;
}

