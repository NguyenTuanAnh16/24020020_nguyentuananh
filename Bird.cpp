#include "Bird.h"

extern Image Image;
SDL_Texture* BirdTexture[4];

void Bird::Init(){
BirdTexture[0]=Image.ImageTransfer("Image/bird1.png");
BirdTexture[1]=Image.ImageTransfer("Image/bird2.png");
BirdTexture[2]=Image.ImageTransfer("Image/bird3.png");
BirdTexture[3]=Image.ImageTransfer("Image/bird4.png");
}


//birdrepeat lap chim
SDL_Rect  Bird::BirdPosition(){return Image.ImageSize(BirdTexture[1],9);}
int Speed1=1;
SDL_Texture* Bird::BirdRepeat(Uint32 Time,Uint32 &Intermediary){
    if(Time-Intermediary>=80){
           Speed1=Speed1+1;
           if(Speed1>3) Speed1=0;
           Intermediary=Time;}
    return BirdTexture[Speed1];
}


// do roi chim
void Bird::update(SDL_Rect &Weight,int &BirdJump,int &Angle,int &Location){
        if (BirdJump == 0){
                    Location = Weight.y;
                    Angle = -20;}
        else if (Angle < 70&& BirdJump>30) Angle += 4;
        if (BirdJump >= 0)
        {
            Weight.y = Location + BirdJump * BirdJump * 0.18 - BirdJump * 7.5;
            BirdJump++;
        }
    }

