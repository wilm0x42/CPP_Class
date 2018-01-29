#include "SSDL.h"

#define SPEED 5


int main()
{
    SSDL::init();
    
    int x = 250;
    int y = 250;
    
    while (SSDL::running)
    {
    	if (SSDL::isPressed(SDLK_w)) y -= SPEED;
    	if (SSDL::isPressed(SDLK_a)) x -= SPEED;
    	if (SSDL::isPressed(SDLK_s)) y += SPEED;
    	if (SSDL::isPressed(SDLK_d)) x += SPEED;
    	
    	SSDL::drawImg("block.bmp", x, y);
        
        SSDL::render();
        
        if (SSDL::isPressed(SDLK_ESCAPE)) SSDL::running = false;
    }
}