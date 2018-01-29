#include "SSDL.h"


int main()
{
    SSDL::init();
    
    int xValues[] = {0, 5, 10, 30, 31, 50, 55, 100, 200, 220, 330, 490, 495, 500};
    
    while (SSDL::running)
    {
    	for (int n = 0; n < 14; n++)
    	{
    		SSDL::drawLine(SSDL::RED, 250, 500, xValues[n], 0);
    	}
        
        SSDL::render();
        
        if (SSDL::isPressed(SDLK_ESCAPE)) SSDL::running = false;
    }
}