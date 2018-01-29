#include "SSDL.h"


int main()
{
    SSDL::init();
    
    while (SSDL::running)
    {
    	//This one's pretty boring, actually... :P
    	SSDL::drawLine(SSDL::RED, 250, 250, 250+50, 250);//Top left to top right
    	SSDL::drawLine(SSDL::BLUE, 250+50, 250, 250+50, 250+50);//Top right to bottom right
    	SSDL::drawLine(SSDL::GREEN, 250+50, 250+50, 250, 250+50);//Bottom right to bottom left
    	SSDL::drawLine(SSDL::YELLOW, 250, 250+50, 250, 250);//Bottom left to top left
        
        SSDL::render();
        
        if (SSDL::isPressed(SDLK_ESCAPE)) SSDL::running = false;
    }
}