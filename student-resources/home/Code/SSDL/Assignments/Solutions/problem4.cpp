#include "SSDL.h"


int main()
{
    SSDL::init();
    
    int size = 50;
    
    while (SSDL::running)
    {
    	//This one's pretty boring, actually... :P
    	SSDL::drawLine(SSDL::RED, 250, 250, 250+size, 250);//Top left to top right
    	SSDL::drawLine(SSDL::BLUE, 250+size, 250, 250+size, 250+size);//Top right to bottom right
    	SSDL::drawLine(SSDL::GREEN, 250+size, 250+size, 250, 250+size);//Bottom right to bottom left
    	SSDL::drawLine(SSDL::YELLOW, 250, 250+size, 250, 250);//Bottom left to top left
    	
    	if (SSDL::isPressed(SDLK_SPACE)) size++;
        
        SSDL::render();
        
        if (SSDL::isPressed(SDLK_ESCAPE)) SSDL::running = false;
    }
}