#ifndef _SSDL_H_
#define _SSDL_H_

#include <SDL2/SDL.h>


namespace SSDL
{
    enum Color
    {
        RED,
        GREEN,
        BLUE,
        YELLOW,
        WHITE,
        BLACK
    };

	SDL_Window* window;
	SDL_Renderer* renderer;
	
	bool running = true;

	void init()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		
		window = SDL_CreateWindow("SSDL", 0, 0, 500, 500, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	}
	
	bool isPressed(SDL_Keycode key)
	{
		const Uint8* state = SDL_GetKeyboardState(NULL);
		return state[SDL_GetScancodeFromKey(key)];
	}
	
	void render()
	{
		SDL_Event e;
	
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		
		while (SDL_PollEvent(&e))
		{
			switch(e.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			}
		}
	}
	
	void drawImg(const char* filename, int x, int y)
	{
        SDL_Surface* surf = SDL_LoadBMP(filename);
        if (!surf)
        {
            printf("Error: Could not find file \"%s\"\n", filename);
            return;
        }
        
        SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
        if (tex)
        {
            SDL_Rect rect = {x, y, surf->w, surf->h};
            SDL_RenderCopy(renderer, tex, NULL, &rect);
            
            SDL_DestroyTexture(tex);
        }
        
        SDL_FreeSurface(surf);
	}

    void drawLine(Color c, int x1, int y1, int x2, int y2)
    {
        switch (c)
        {
            case RED:
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                break;
            case GREEN:
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                break;
            case BLUE:
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                break;
            case YELLOW:
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            case WHITE:
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                break;
            case BLACK:
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                break;
            default:
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                break;
        }
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
}

#endif