#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void main(void) {
    int gdriver = DETECT, gmode;
    int x1 = 200, y1 = 200;
    int x2 = 300, y2 = 300;
    clrscr();
    
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
    line(x1, y1, x2, y2);
    getch();
    closegraph();
}
