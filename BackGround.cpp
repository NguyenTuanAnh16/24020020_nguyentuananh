#include "BackGround.h"

extern Image Image;
Music Music;

void BackGround::StartBackGround(){
     bool Check=true;
     Mix_Music* MusicBackGround=Music.LoadMusic("Music/musicbackground.mp3");
     SDL_Texture* BackGroundHello=Image.ImageTransfer("Image/background.jpg");
     Mix_PlayMusic(MusicBackGround, -1);
     Image.RenderCopy(BackGroundHello);
     Image.RenderPresent();
     Image.EvenMouse(Check);
     Mix_PauseMusic();
     if(Check==false)  exit(0);;
     Image.RenderClear();
     Image.FreePhoto(BackGroundHello);}


// MoveBackGround cuon anh
//SDL_Texture* BackGroundMove1=Image.ImageTransfer("khoichay.jpg");
void BackGround::MoveBackGround(SDL_Rect &Size1,SDL_Rect &Size2){
          Size1.x=Size1.x-Speed;
          Size2.x=Size2.x-Speed;
          if(Size2.x<=0){Size2.x=Size2.w;Size1.x=0;}
}
