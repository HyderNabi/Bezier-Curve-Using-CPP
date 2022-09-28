//Modeling of Bezier Curves using CPP
#include<iostream>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
using namespace std;

 // DATE : 26 - August -  2021
 // Author : Hyder Nabi

//Procedure Bezier
float Bezier(float u,float x[])
{
    float BEZ = 0;
    int c;

    for(int i=0; i<4; i++)
    {
        if(i == 1 || i == 2)
            c = 3;
        else
            c = 1;
       BEZ += x[i] * (c * pow(u,i) * pow((1-u),3-i));

    }
    return BEZ;
}



//Main Program
int main()
{
    // init Graphics Drivers
    int gdriver=DETECT,gmode;
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

    //Control Points
    //There are 4 Control Points
    float px[4] = {50,150,300,300};
    float py[4] = {100,10,400,100};
    float x,y;

    //Draw Four Control Points
    for(int i=0; i<4; i++)
    {
        putpixel(px[i],py[i],15);
    }
    //Draw the Bezier Curve
    //The parameter 'u' ranges from 0 to 1 with increment of 0.0001
    for(float u=0; u<=1; u+=0.00001)
    {
        x = Bezier(u,px);
        y = Bezier(u,py);
        putpixel(x,y,15);

    }
    getche();
    closegraph();
    return 0;
}
