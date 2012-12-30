#include "stdafx.h"
#include "input.h"

namespace Input
{
	char key[SDLK_LAST];
	int mousex,mousey;
	int mousexrel,mouseyrel;
	char mousebuttons[8];
	char quit;

	int Init()
	{
		memset(key,0,SDLK_LAST);
		mousex = 0; mousey = 0;
		mousexrel = 0; mouseyrel = 0;
		memset(mousebuttons,0,8);
		quit = 0;
		return 0;
	}
	void UpdateEvents()
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				key[event.key.keysym.sym]=1;
				break;
			case SDL_KEYUP:
				key[event.key.keysym.sym]=0;
				break;
			case SDL_MOUSEMOTION:
				mousex=event.motion.x;
				mousey=event.motion.y;
				mousexrel=event.motion.xrel;
				mouseyrel=event.motion.yrel;
				break;
			case SDL_MOUSEBUTTONDOWN:
				mousebuttons[event.button.button]=1;
				break;
			case SDL_MOUSEBUTTONUP:
				mousebuttons[event.button.button]=0;
				break;
			case SDL_QUIT:
				quit = 1;
				break;
			default:
				break;
			}
		}
	}
}