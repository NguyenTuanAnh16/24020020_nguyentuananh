#include "Point.h"

Image Image;


//number so;
// displaynumber hien thi so
void PointGame::Number(SDL_Texture* ImageNumber,int Point,bool Check)
{
int a[10]; int Number=0; int Space;
SDL_Rect  cutnumber,displaynumber;
if(Check){  cutnumber={0,0,180,180};
            displaynumber={640,10,70,70};
          Space=30;
          }
else {
           cutnumber={0,0,180,180};
           displaynumber={415,469,50,50};
          Space=22;
}
if(Point==0) Image.RenderCopy1(ImageNumber,cutnumber,displaynumber);
while(Point>0){
    a[Number]=Point%10;
    Point=Point/10;
    Number++;
}
if(Check) displaynumber.x=displaynumber.x-Number*15;
for(int i=Number-1;i>=0;i--){
        if(a[i]==0){Image.RenderCopy1(ImageNumber,cutnumber,displaynumber);
                   displaynumber.x=displaynumber.x+Space;}
        if(a[i]==1){cutnumber.x=180;
                    Image.RenderCopy1(ImageNumber,cutnumber,displaynumber);
                    displaynumber.x=displaynumber.x+Space;}
        if(a[i]==2){cutnumber.x=360;
                    Image.RenderCopy1(ImageNumber,cutnumber,displaynumber);
                    displaynumber.x=displaynumber.x+Space;}
        if(a[i]==3){cutnumber.x=540;
                    Image.RenderCopy1(ImageNumber,cutnumber,displaynumber);
                    displaynumber.x=displaynumber.x+Space;}
        if(a[i]==4){cutnumber.x=720;
                    Image.RenderCopy1(ImageNumber,cutnumber,displaynumber);
                    displaynumber.x=displaynumber.x+Space;}
        if(a[i]==5){cutnumber.y=180;
                    Image.RenderCopy1(ImageNumber,cutnumber,displaynumber);
                    displaynumber.x=displaynumber.x+Space;}
        if(a[i]==6){cutnumber.x=180; cutnumber.y=180;
                    Image.RenderCopy1(ImageNumber,cutnumber,displaynumber);
                    displaynumber.x=displaynumber.x+Space;}
        if(a[i]==7){cutnumber.x=360; cutnumber.y=180;
                    Image.RenderCopy1(ImageNumber,cutnumber,displaynumber);
                    displaynumber.x=displaynumber.x+Space;}
        if(a[i]==8){cutnumber.x=540; cutnumber.y=180;
                    Image.RenderCopy1(ImageNumber,cutnumber,displaynumber);
                    displaynumber.x=displaynumber.x+Space;}
        if(a[i]==9){cutnumber.x=720; cutnumber.y=180;
                   Image.RenderCopy1(ImageNumber,cutnumber,displaynumber);
                   displaynumber.x=displaynumber.x+Space;}}
}
