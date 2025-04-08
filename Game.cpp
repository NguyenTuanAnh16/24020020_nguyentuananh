#include "imagesize.h"
#include <cstdlib>
#include <ctime>
#include "Point.h"
#include "BackGround.h"
#include "Bird.h"
#include "Column.h"
using namespace std;

bool Check=true;
int Point=0;
Uint32 TimeBird,Time;
int BirdJump; // so nhay chim
SDL_Event Control; // chuot
SDL_Texture* ImageBird;
SDL_Texture* BackGroundMove; // boi canh di chuyen
SDL_Texture* BackGroundGuide; // huong dan chs game
SDL_Rect LocationBackGround1,LocationBackGround2; // vi tri de chay background
SDL_Texture* GameOver;
SDL_Rect GameOverSize;
int Angle;
int Location;
SDL_Rect SizeBackGroundMove,LocationBackGroundMove1,LocationBackGroundMove2;
int main(int argc, char *argv[])
{
srand(time(0));
Image Image;
BackGround BackGround;
Bird Bird;
Column Column;
PointGame PointGame;
Music Music;
Image.init();
Music.Init();
Bird.Init();
Column.InitOne();

Mix_Music* MusicGameOver=Music.LoadMusic("Music/GameOver.mp3");
Mix_Chunk* MusicBird=Mix_LoadWAV("Music/MusicBird.WAV");
Mix_VolumeChunk(MusicBird, 128); // volume: từ 0 đến 128

BackGround.StartBackGround(); // background chao mung

// vi tri cua chim
SDL_Rect  BirdPosition=Bird.BirdPosition();

// anh so
SDL_Texture* NumberTexture=Image.ImageTransfer("Image/Number.png");

// anh game over
GameOver=Image.ImageTransfer("Image/gameover.jpg");
GameOverSize= Image.ImageSize(GameOver,4);

// anh game over va anh background2
BackGroundMove=Image.ImageTransfer("Image/BackGroundMove.jpg");
//

SizeBackGroundMove=Image.ImageSize(BackGroundMove,1);
SizeBackGroundMove={0,640,1280,153};
LocationBackGroundMove1=Image.ImageSize(BackGroundMove,1);
LocationBackGroundMove2=Image.ImageSize(BackGroundMove,1);

BackGroundGuide=Image.ImageTransfer("Image/BackGroundGuide.png");
while(true){
    Check=true;
    BirdPosition.x=250;
    BirdPosition.y=328;
    Point=0;
    BirdJump=0; // so nhay chim
    Column.Init();
    Angle=-20;
    Location=328;
    LocationBackGroundMove2={0,604,1280,173};
    LocationBackGroundMove1={0,604,1280,173};
    LocationBackGround1=Image.ImageSize(BackGroundMove,1);
    LocationBackGround2=Image.ImageSize(BackGroundMove,1);
    LocationBackGround2.x=LocationBackGround2.w;
    Mix_PlayChannel(1,MusicBird,-1); // hieu ung chim
    while(Check){
                 Image.RenderTexture(BackGroundGuide,LocationBackGround1); // tai background
                 Time=SDL_GetTicks();// ham xac dinh thoi gian
                 ImageBird=Bird.BirdRepeat(Time,TimeBird);  // tao hieu ung chim'
                 Image.RenderTexture(ImageBird,BirdPosition); // tai anh bird
                 Image.RenderCopy1(BackGroundMove,SizeBackGroundMove,LocationBackGroundMove1); // anh backgornd2
                 Image.RenderPresent();
                 if (SDL_PollEvent(&Control) != 0 && (Control.key.keysym.sym == SDLK_UP || Control.key.keysym.sym==SDLK_SPACE )&& Control.type == SDL_KEYDOWN){Check=0;}
                 if ( SDL_PollEvent(&Control) != 0 && Control.type==SDL_QUIT)  return 0 ;}
    Mix_PauseMusic();
    Image.RenderClear();

     Check=true;
     while (Check) {

           BackGround.MoveBackGround(LocationBackGround1,LocationBackGround2); // giup di chuyen background2
           Image.RenderTexture(BackGroundMove,LocationBackGround1);
           Image.RenderTexture(BackGroundMove,LocationBackGround2);

           Time=SDL_GetTicks();// ham xac dinh thoi gian
           ImageBird=Bird.BirdRepeat(Time,TimeBird);  // tao hieu ung chim
           if ((Control.key.keysym.sym == SDLK_UP || Control.key.keysym.sym==SDLK_SPACE )&& Control.type == SDL_KEYDOWN){BirdJump=0;Mix_PlayChannel(1,MusicBird,0);}  // di chuyen chim
           Bird.update(BirdPosition,BirdJump,Angle,Location); // trong luong va anh chim
           Image.RenderCopyEx(ImageBird,BirdPosition,Angle); // tai anh chim
           if(BirdPosition.y>=665-60 ) Check=0; // kiem tra chim roi chua

           Column.ColumnLocation(rand(),Point); // vi tri cot
           Column.RenderColumn(); // rendder cot

        BackGround.MoveBackGround(LocationBackGroundMove1,LocationBackGroundMove2);
        Image.RenderCopy1(BackGroundMove,SizeBackGroundMove,LocationBackGroundMove1);
        Image.RenderCopy1(BackGroundMove,SizeBackGroundMove,LocationBackGroundMove2);

         Column.MoveColumn(BirdPosition,Check,Point);
         PointGame.Number(NumberTexture,Point,true);
         Image.RenderPresent();
         Image.RenderClear();
         SDL_Delay(16);
         if ( SDL_PollEvent(&Control) != 0 && Control.type==SDL_QUIT)  return 0 ;
}

Mix_PlayMusic(MusicGameOver,-1);
while(true){
         BackGround.MoveBackGround(LocationBackGround1,LocationBackGround2);
         Image.RenderTexture(BackGroundMove,LocationBackGround1);
         Image.RenderTexture(BackGroundMove,LocationBackGround2);
         Time=SDL_GetTicks();
         BirdPosition.x=BirdPosition.x-3;
         ImageBird=Bird.BirdRepeat(Time,TimeBird);
         Image.RenderTexture(ImageBird,BirdPosition);
         Column.RenderColumn();
         BackGround.MoveBackGround(LocationBackGroundMove1,LocationBackGroundMove2);
        Image.RenderCopy1(BackGroundMove,SizeBackGroundMove,LocationBackGroundMove1);
        Image.RenderCopy1(BackGroundMove,SizeBackGroundMove,LocationBackGroundMove2);
         Image.RenderTexture(GameOver,GameOverSize);
         PointGame.Number(NumberTexture,Point,false);
         Image.RenderPresent();
         SDL_Delay(16);
         if ( SDL_PollEvent(&Control) != 0 && Control.type==SDL_QUIT)  return 0 ;
         if(Control.type==SDL_MOUSEBUTTONDOWN &&(595<=Control.button.x && Control.button.x<=687)&&(447<=Control.button.y && Control.button.y<=538)) return 0;
         if(Control.type==SDL_MOUSEBUTTONDOWN &&(795<=Control.button.x && Control.button.x<=887)&&(447<=Control.button.y && Control.button.y<=538)) break;
         }  Mix_PauseMusic();

}
}
