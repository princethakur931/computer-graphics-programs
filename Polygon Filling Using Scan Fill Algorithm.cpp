#include<graphics.h>
#include<iostream>
using namespace std;
void FloodFill(int x, int y, int oldc,int newc)
{
 int current;
 current=getpixel(x,y);
 if(current==oldc)
 {
 putpixel(x,y,newc);
 delay(5);
 FloodFill(x+1,y,oldc,newc);
 FloodFill(x-1,y,oldc,newc);
 FloodFill(x,y+1,oldc,newc);
 FloodFill(x,y-1,oldc,newc);
 }
}
int main()
{
 int x,y,oldc=0,x1,y1,x2,y2;
 int gDriver=DETECT,gmode;
 initgraph(&gDriver,&gmode,NULL);

 cout<<"Enter number of co-ordinates\n";
 cin>>x1>>y1>>x2>>y2;
 setcolor(1);
 line(x1,y1,x2,y1);
 setcolor(2);
 line(x2,y1,x2,y2);
 setcolor(3);
 line(x2,y2,x1,y2);
 setcolor(5);
 line(x1,y2,x1,y1);

 x=(x1+x2)/2;
 y=(y1+y2)/2;

 FloodFill(x,y,oldc,4);
 delay(10000);
 closegraph();
 return 0;

}
