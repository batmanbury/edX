/**
 * breakout.c
 *
 * Matthew T. Banbury
 * matbanbury@gmail.com
 *
 * CS50x
 * Problem Set 4
 *
 * Implementation of the game Breakout
 */

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// width of paddle in pixels
#define PAD_WIDTH 60

// height of paddle in pixels
#define PAD_HEIGHT 5

// offset of paddle from bottom edge
#define PAD_OFFSET HEIGHT - 25

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points, int lives);
GObject detectCollision(GWindow window, GOval ball);


int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);
    
    // set initial x,y velocities
    double velocityX = drand48();
    double velocityY = 0.5;

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // click to start
    waitForClick();

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // get the ball moving
        // move ball along each axis
        move(ball, velocityX, velocityY);

        // bounce off right edge of window
        if (getX(ball) + getWidth(ball) >= getWidth(window))
        {
            velocityX = -velocityX;
        }

        // bounce off left edge of window
        if (getX(ball) <= 0)
        {
            velocityX = -velocityX;
        }
        
        // bounce off top edge of window
        if (getY(ball) <= 0)
        {
            velocityY = -velocityY;
        }
        
        // lose a life when ball hits bottom edge, reset ball, velocityX
        if (getY(ball) >= HEIGHT)
        {
            lives -= 1;
            srand48(time(NULL));
            velocityX = drand48();
            setLocation(ball, WIDTH/2 - RADIUS, HEIGHT/2 - RADIUS);
            setLocation(paddle, WIDTH/2 - PAD_WIDTH/2, PAD_OFFSET);
            waitForClick();
        }
        
        // remember what the ball collides with
        GObject object = detectCollision(window, ball);
        
        // if a collision occurs
        if (object != NULL)
        {
            // detect ball collision with paddle
            if (object == paddle)
            {
                velocityY = -velocityY;
            }
        
            // detect ball collision with brick
            else if (strcmp(getType(object), "GRect") == 0)
            {
                velocityY = -velocityY;
                
                // remove brick
                removeGWindow(window, object);
                bricks -= 1;
                points += 1;
                
                // update scoreboard
                updateScoreboard(window, label, points, lives);
            }
        }
        
        // paddle movement
        // check for mouse event
        GEvent event = getNextEvent(MOUSE_EVENT);

        // if we heard one
        if (event != NULL)
        {
            // if the event was movement
            if (getEventType(event) == MOUSE_MOVED)
            {
                // remember mouse X coordinate
                double x = getX(event) - PAD_WIDTH / 2;
                
                // restrict paddle to inside window edges
                if (x > 0 && x < WIDTH - PAD_WIDTH)
                {
                    // move the paddle with the mouse X coordinate
                    setLocation(paddle, x, PAD_OFFSET);
                }
            }
        }
    }

    // wait for click before exiting
    updateScoreboard(window, label, points, lives);
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // iterable brick colors
    string colors[] = {"RED", "ORANGE", "YELLOW", "GREEN", "BLUE"};
    
    // brick buffers for left edge (x) and top edge (y)
    int x = 2;
    int y = 40;
    
    // brick width, height
    int brickW = 35;
    int brickH = 10;
    
    // space between bricks
    int brickGap = 5;
    
    // spacing increments for bricks' x,y coordinates
    int nextX = brickW + brickGap;  
    int nextY = brickH + brickGap; 
    
    // instantiate bricks
    for (int c = 0; c < ROWS; c++)
    {
        for (int r = 0; r < COLS; r++)
        {
            // add a brick
            GRect brick = newGRect(x, y, brickW, brickH);
            setFilled(brick, true);
            setColor(brick, colors[c]);
            add(window, brick);
            
            // shift right to the next COLUMN
            x += nextX;
        }
        
        // shift down to the next ROW
        y += nextY;
        
        // reset left buffer 
        x = 2;
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval(WIDTH/2 - RADIUS, HEIGHT/2 - RADIUS, RADIUS*2, RADIUS*2);
    setFilled(ball, true);
    setColor(ball, "MAGENTA");
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    GRect paddle = newGRect(WIDTH/2 - PAD_WIDTH/2, PAD_OFFSET, PAD_WIDTH, PAD_HEIGHT);
    setFilled(paddle, true);
    setColor(paddle, "BLACK");
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    GLabel label = newGLabel("0");
    setFont(label, "SansSerif-36");
    setColor(label, "LIGHT_GRAY");
    add(window, label);
    
    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
    
    return label;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points, int lives)
{
    // update label    
    if (lives > 0 && points < ROWS * COLS)
    {
        char s[12];
        sprintf(s, "%i", points);
        
        // if lives and bricks remain
        setLabel(label, s);
    }
    else if (lives <= 0)
    {
        // if no lives remain
        setLabel(label, "Game Over");
    }
    else if (points >= ROWS * COLS)
    {
        // if no bricks remain
        setLabel(label, "You Win!");
    }

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
