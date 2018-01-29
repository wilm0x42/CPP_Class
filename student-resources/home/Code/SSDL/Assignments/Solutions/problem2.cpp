#include "SSDL.h"


int main()
{
    SSDL::init();
    
    bool goingRight = true;
    int x = 0;
    
    while (SSDL::running)
    {
    	if (goingRight == true)
    	{
    		x += 10;
    	}
    	else
    	{
    		x -= 10;
    	}
    	
    	if (x > 500) goingRight = false;
    	if (x < 0) goingRight = true;
    	
    	SSDL::drawImg("block.bmp", x, 0);
    	SSDL::drawLine(SSDL::RED, 0, 500, x, 0);
        
        SSDL::render();
        
        if (SSDL::isPressed(SDLK_ESCAPE)) SSDL::running = false;
    }
}