#include <graphics.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 100, y = 100, i=50; // starting position of the ball
    int r = 20; // radius of the ball
    int vx = 5, vy = 5; // velocities of the ball
    int maxx = getmaxx(), maxy = getmaxy(); // maximum coordinates of the screen
   
    while (1) { // infinite loop to keep the animation running
        cleardevice(); // clear the screen before drawing the new frame
         outtextxy(getmaxx() / 2 -50,getmaxy() / 2 -80,"Press 'Space' to stop");
         outtextxy(getmaxx() / 2 -50,getmaxy() / 2 -60,"Press 'U' to speed up");
         outtextxy(getmaxx() / 2 -50,getmaxy() / 2 -40,"Press 'D' to speed down");
        // draw the ball at its current position
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(x, y, r);
        floodfill(x, y, YELLOW);

        // update the position of the ball based on its velocity
        x += vx;
        y += vy;

        // check if the ball has hit the boundaries of the screen
        if (x - r <= 0 || x + r >= maxx) {
            vx = -vx; // reverse the x-velocity
        }
        if (y - r <= 0 || y + r >= maxy) {
            vy = -vy; // reverse the y-velocity
        }

        if(kbhit())
        {
            char input=getch();
            if(input==32)
            {
                while(1)
                {
                char  ip=getch();
                if(ip==32)
                    break;
                }
            }
            else
            {
                if(input=='u')
                {
                 i-=10;
                 if(i<0)
                     {
                        i=0;
                     }
                }
                else if (input=='d')
                {
                    i+=10;
                    if(i>80)
                    {i=80;}
                }
            }
        }

        delay(i); // pause for 10 milliseconds before drawing the next frame
    }

    closegraph();
    return 0;
}
