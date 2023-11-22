#include<iostream>
#include<graphics.h>
typedef unsigned int outcode;
enum{TOP=0x1,BOTTOM=0x2,RIGHT=0x4,LEFT=0x8};
using namespace std;
outcode CompOutCode(double ,double ,double ,double ,double ,double );
void CSLCAD(double x0,double y0,double x1,double y1,double xmin,double xmax,double ymin,double ymax)
{
 outcode outcode0,outcode1,outcodeout;
 boolean accept=FALSE, done=FALSE;
 outcode0=CompOutCode(x0,y0,xmin,xmax,ymin,ymax);
 outcode1=CompOutCode(x1,y1,xmin,xmax,ymin,ymax);
 cout<<"outcode0="<<outcode0<<endl;
 cout<<"outcode1="<<outcode1<<endl;
 do
 {
 if(outcode0==0 && outcode1==0)
 {
 accept=TRUE;
 done=TRUE;
 }
 else if(outcode0 & outcode1)
 {
 done=TRUE;
 }
 else
 {
 double x,y;
 int ocd=outcode0 ? outcode0:outcode1;
 if(ocd & TOP)
 {
 x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
 y=ymax;
 }
 else if(ocd & BOTTOM)
 {
 x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
 y=ymin;
 }
 else if(ocd & LEFT)
 {
 y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
 x=xmin;
 }
 else
 {
 y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
 x=xmax;
 }
 if(ocd==outcode0)
 {
 x0=x;
y0=y;
outcode0=CompOutCode(x0,y0,xmin,xmax,ymin,ymax);
 }
 else
 {
 x1=x;
y1=y;
outcode1=CompOutCode(x1,y1,xmin,xmax,ymin,ymax);
 }
 }
 }while(done==FALSE);
 if(accept==TRUE)
 {
 line(x0,y0,x1,y1);
 }
}
outcode CompOutCode(double x,double y,double xmin,double xmax,double ymin,double ymax)
{
 outcode code=0;
 if(y>ymax)
 code|=TOP;
 if(y<ymin)
 code|=BOTTOM;
 if(x>xmax)
 code|=RIGHT;
 if(x<xmin)
 code|=LEFT;
 return code;
}
int main()
{
 string ch;
 double xmin,xmax,ymin,ymax,x0,y0,x1,y1;
 initwindow(500,600);
 cout<<"Enter the bottom co-ordinates of window:";
cin>>xmin;
cout<<"Enter the left coordinates of the window:";
cin>>ymin;
cout<<"Enter the right coordinates of the window:";
cin>>xmax;
cout<<"Enter the top coordinates of the window:";
cin>>ymax;
rectangle(xmin,ymin,xmax,ymax);
cout<<"Enter the coordinates(Terminal Points) of the line: ";
cin>>x0>>y0;
cin>>x1>>y1;
line(x0,y0,x1,y1);
 delay(5000);
 cleardevice();
 CSLCAD(x0,y0,x1,y1,xmin,xmax,ymin,ymax);
 rectangle(xmin,ymin,xmax,ymax);
 delay(50000);
 closegraph();
}
