#include <graphics.h>
#include <dos.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int speed=5;
    int paddleWidth = 60, paddleHeight = 10;
    int paddle1X = 300, paddle2X = 100;
    int paddleY = getmaxy() - 50;
    int ballX = getmaxx() / 2, ballY = getmaxy() / 2;
    int ballRadius = 10;
    int ballDX = speed, ballDY = speed;

    while (1)
    {
        // Draw the paddles
        setcolor(WHITE);
        setfillstyle(LTSLASH_FILL, WHITE);
        rectangle(paddle1X, paddleY, paddle1X + paddleWidth, paddleY + paddleHeight);
        floodfill(paddle1X + 1, paddleY + 1, WHITE);
        rectangle(paddle2X, 40, paddle2X + paddleWidth, 40 + paddleHeight);
        floodfill(paddle2X + 1, 41, WHITE);

        // Draw the ball
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(ballX, ballY, ballRadius);
        floodfill(ballX, ballY, YELLOW);

        delay(50);
        cleardevice();

        // Move the ball
        ballX += ballDX;
        ballY += ballDY;

        // Bounce the ball off the walls
        if (ballX + ballRadius > getmaxx() || ballX - ballRadius < 0)
            ballDX = -ballDX;

        // Check for collision with the paddles
        if (ballY + ballRadius >= paddleY && ballY + ballRadius <= paddleY + paddleHeight && ballX >= paddle1X && ballX <= paddle1X + paddleWidth)
            ballDY = -ballDY;
        if (ballY - ballRadius <= 40 + paddleHeight && ballY - ballRadius >= 40 && ballX >= paddle2X && ballX <= paddle2X + paddleWidth)
            ballDY = -ballDY;

        // Move the paddles
        if (kbhit())
        {
            char ch = getch();
            if (ch == 'a')
                paddle1X -= 10;
            if (ch == 'd')
                paddle1X += 10;
            if (ch == 'j')
                paddle2X -= 10;
            if (ch == 'l')
                paddle2X += 10;
        }

        // Keep the paddles inside the screen
        if (paddle1X < 0)
            paddle1X = 0;
        if (paddle1X + paddleWidth > getmaxx())
            paddle1X = getmaxx() - paddleWidth;
        if (paddle2X < 0)
            paddle2X = 0;
        if (paddle2X + paddleWidth > getmaxx())
            paddle2X = getmaxx() - paddleWidth;

         //End the game if the ball goes out of bounds
        if ((ballY + ballRadius > getmaxy()) || (ballY - ballRadius < 0))
        {   setcolor(WHITE);
            settextstyle(9,0,2);
            outtextxy(getmaxx() / 2 -100,getmaxy() / 2 -40,"Game Over");
            
        }
    }
}
       
