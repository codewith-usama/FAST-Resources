//Analog Clock Program

//#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>

void main()
{
int gd=DETECT,gm;
int x=320,y=240,r=200,i,h,m,s,thetamin,thetasec;
struct  time t;
char n[12][3]={"3","2","1","12","11","10","9","8","7","6","5","4"};
initgraph(&gd,&gm,"f:\arun\tc");\put the directory which contains
egavga.bgi
circle(x,y,210);
setcolor(4);
settextstyle(4,0,5);
for(i=0;i<12;i++)
{
if(i!=3)
outtextxy(x+(r-14)*cos(M_PI/6*i)-10,y-(r-14)*sin(M_PI/6*i)-26,n[i]);
else
outtextxy(x+(r-14)*cos(M_PI/6*i)-20,y-(r-14)*sin(M_PI/6*i)-26,n[i]);
}
gettime(&t);
printf("The current time is: %2d:%02d:%02d.%02d
",t.ti_hour, t.ti_min,
t.ti_sec, t.ti_hund);
while(!kbhit())
{
setcolor(5);
setfillstyle(1,5);
circle(x,y,10);
floodfill(x,y,5);
gettime(&t);
if(t.ti_min!=m)
{
setcolor(0);
line(x,y,x+(r-60)*cos(thetamin*(M_PI/180)),y-(r-60)*sin(thetamin*(M_PI/180
)));
circle(x+(r-80)*cos(thetamin*(M_PI/180)),y-(r-80)*sin(thetamin*(M_PI/180))
,10);
line(x,y,x+(r-110)*cos(M_PI/6*h-((m/2)*(M_PI/180))),y-(r-110)*sin(M_PI/6*h
-((m/2)*(M_PI/180))));
circle(x+(r-130)*cos(M_PI/6*h-((m/2)*(M_PI/180))),y-(r-130)*sin(M_PI/6*h-(
(m/2)*(M_PI/180))),10);
}
if(t.ti_hour>12)
t.ti_hour=t.ti_hour-12;
if(t.ti_hour<4)
h=abs(t.ti_hour-3);
else
h=15-t.ti_hour;
m=t.ti_min;
if(t.ti_min<=15)
thetamin=(15-t.ti_min)*6;
else
thetamin=450-t.ti_min*6;
if(t.ti_sec<=15)
thetasec=(15-t.ti_sec)*6;
else
thetasec=450-t.ti_sec*6;
setcolor(4);
line(x,y,x+(r-110)*cos(M_PI/6*h-((m/2)*(M_PI/180))),y-(r-110)*sin(M_PI/6*h
-((m/2)*(M_PI/180))));
circle(x+(r-130)*cos(M_PI/6*h-((m/2)*(M_PI/180))),y-(r-130)*sin(M_PI/6*h-(
(m/2)*(M_PI/180))),10);
line(x,y,x+(r-60)*cos(thetamin*(M_PI/180)),y-(r-60)*sin(thetamin*(M_PI/180
)));
circle(x+(r-80)*cos(thetamin*(M_PI/180)),y-(r-80)*sin(thetamin*(M_PI/180))
,10);
setcolor(15);
line(x,y,x+(r-70)*cos(thetasec*(M_PI/180)),y-(r-70)*sin(thetasec*(M_PI/180
)));
delay(1000);
setcolor(0);
line(x,y,x+(r-70)*cos(thetasec*(M_PI/180)),y-(r-70)*sin(thetasec*(M_PI/180
)));
}
}

