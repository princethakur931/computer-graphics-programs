#include<graphics.h>

class walkingman
{
int rhx,rhy;
public:
void draw(int,int);
void draw(int);
};
void walkingman::draw(int i)
{
line(20,380,580,380);
if(i%2)
{
line(25+i,380,35+i,340);
line(45+i,380,35+i,340);
line(35+i,310,25+i,330);
delay(20);
}
else
{
line(35+i,340,35+i,310);
line(35+i,310,40+i,330);
delay(20);
}
line(35+i,340,35+i,310);
circle(35+i,300,10);
line(35+i,310,50+i,330);
line(50+i,330,50+i,280);
line(15+i,280,85+i,280);
arc(50+i,280,0,180,35);
arc(55+i,330,180,360,5);
}
void walkingman::draw(int x,int y)
{
int j;
rhx=x;
rhy=y;
for
(j=0;j<100;j++)
{
outtextxy(rand()%rhx,rand()%(rhy-50),"|");
setcolor(WHITE);
}
}
int main()
{
int gd=DETECT,gm;
int rhx,rhy,j,i;
walkingman obj;
initgraph(&gd,&gm,"");
for(i=0;i<500;i++)
{
obj.draw(i);
rhx=getmaxx();
rhy=getmaxy();
obj.draw(rhx,rhy);
delay(150);
cleardevice();
}
getch();
} 
