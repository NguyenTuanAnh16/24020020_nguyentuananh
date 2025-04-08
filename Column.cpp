#include "Column.h"

extern Image Image;

SDL_Texture* ColumnOne;
SDL_Texture* ColumnTwo;
SDL_Rect ColumnPosition[4][2];
Mix_Chunk* MusicPoint;
void Column::InitOne(){
ColumnOne=Image.ImageTransfer("Image/Column.jpg");
ColumnTwo=Image.ImageTransfer("Image/Column1.jpg");
MusicPoint=Mix_LoadWAV("Music/MusicPoint.WAV");
}
void Column::Init(){
ColumnPosition[0][0]= {1290, -206, 80, 492};
ColumnPosition[0][1]= {1290, -206+ColumnSpacing, 80, 492};
ColumnPosition[1][0]= {1640, -206, 80, 492};
ColumnPosition[1][1]= {1640, -206+ColumnSpacing, 80, 492};
ColumnPosition[2][0]= {1990, -435, 80, 492};
ColumnPosition[2][1]= {1990, -435+ColumnSpacing, 80, 492};
ColumnPosition[3][0]= {2340, -100, 80, 492};
ColumnPosition[3][1]= {2340, -100+ColumnSpacing, 80, 492};
}



int RandomNumber;
void Column::ColumnLocation(int rand,int Point){
// lap lai cot
          RandomNumber = rand % 336 + 1;
          for(int i=0;i<=3;i++){
                if(ColumnPosition[i][0].x<=-80){ColumnPosition[i][0].x=1290;
                ColumnPosition[i][1].x=1290;
                ColumnPosition[i][0].y=RandomNumber-436;
                ColumnPosition[i][1].y=ColumnPosition[i][0].y+ColumnSpacing;}}
          // lam cot len xuong
          if((Point>2 && Point%2==0) || (Point>10 && Point%1==0) || Point>15){
                for(int i=0;i<=3;i++){
                if(ColumnPosition[i][0].x<=800 && ColumnPosition[i][0].x>=300){
                if(i==0) i=4;
                if(ColumnPosition[i-1][0].y<=-167 &&  ColumnPosition[i][0].y<-100){
                                ColumnPosition[i][0].y=ColumnPosition[i][0].y+3;
                                ColumnPosition[i][1].y=ColumnPosition[i][1].y+3;}
                if(ColumnPosition[i-1][0].y>-167 && ColumnPosition[i][1].y>217){
                                ColumnPosition[i][0].y=ColumnPosition[i][0].y-3;
                                ColumnPosition[i][1].y=ColumnPosition[i][1].y-3;}}
                                     }
                                                                              }

}


void Column::RenderColumn(){
    // di chuyen cot
          for(int i=0;i<=3;i++){
             for(int j=0;j<=1;j++) ColumnPosition[i][j].x=ColumnPosition[i][j].x-3;}
    // tai anh cot
         for(int i=0;i<=3;i++){
                Image.RenderTexture(ColumnOne,ColumnPosition[i][0]);
                Image.RenderTexture(ColumnTwo,ColumnPosition[i][1]);}
}


void Column::MoveColumn(SDL_Rect BirdPosition,bool &Check,int &Point){


         // tinh diem, xu li va cham
         for(int i=0;i<=3;i++){
                if((ColumnPosition[i][0].x<=323 && ColumnPosition[i][0].x>=206)&&( BirdPosition.y<=ColumnPosition[i][0].y+483 || BirdPosition.y>=ColumnPosition[i][1].y-53)) Check=0;
                if((ColumnPosition[i][0].x<=286 && ColumnPosition[i][0].x>=190)&&( BirdPosition.y<=ColumnPosition[i][0].y+468 || BirdPosition.y>=ColumnPosition[i][1].y-51)) Check=0;
                if((ColumnPosition[i][0].x<=270 && ColumnPosition[i][0].x>=174)&&( BirdPosition.y<=ColumnPosition[i][0].y+466 || BirdPosition.y>=ColumnPosition[i][1].y-42)) Check=0;
                if(ColumnPosition[i][0].x<=180 && ColumnPosition[i][0].x>=178){Point++;Mix_PlayChannel(2,MusicPoint,0);}}


}

