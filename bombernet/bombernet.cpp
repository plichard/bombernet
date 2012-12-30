// bombernet.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "input.h"
 
int main(int argc, char *argv[])
{
	Input::Init();
    SDL_Init(SDL_INIT_VIDEO);
 
    SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Bomberman", NULL);

	while(!Input::key[SDLK_ESCAPE] && !Input::quit)
	{
		Input::UpdateEvents();
	}

    SDL_Quit();
 
    return 0;
}
