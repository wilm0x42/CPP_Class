#include "SSDL.h"

#define SPEED 5


int main()
{
    int x = 250-32;
    int y = 250-32;

    SSDL::init(); //Initialize the library
    
    while (SSDL::running) //Main loop
    {
        //Move the block when the A D W or S keys are pressed
        if (SSDL::isPressed(SDLK_a)) x -= SPEED;
        if (SSDL::isPressed(SDLK_d)) x += SPEED;
        if (SSDL::isPressed(SDLK_w)) y -= SPEED;
        if (SSDL::isPressed(SDLK_s)) y += SPEED;
    
        //Draw some images
        SSDL::drawImg("BG.bmp", 0, 0);
        SSDL::drawImg("block.bmp", x, y);
        
        //Draw some lines
        SSDL::drawLine(SSDL::RED, 0, 0, x, y);
        SSDL::drawLine(SSDL::GREEN, 500-1, 500-1, x+64-1, y+64-1);
        
        //Put the stuff we drew onto the screen
        SSDL::render();
        
        //Exit program when the escape key is pressed
        if (SSDL::isPressed(SDLK_ESCAPE)) SSDL::running = false;
    }
}