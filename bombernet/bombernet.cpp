// bombernet.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "input.h"
#include "server.h"
#include "client.h"
#include "world.h"
 
int main(int argc, char *argv[])
{
	Input::Init();
	World::Init(10,10);

    SDL_Init(SDL_INIT_VIDEO);
 
	SDL_Surface* scr = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
	World::SetScreen(scr);
    SDL_WM_SetCaption("Bomberman", NULL);


	while(!Input::key[SDLK_ESCAPE] && !Input::quit)
	{
		World::Display();
		SDL_Delay(30);
		Input::UpdateEvents();
		if(Input::key[SDLK_s]) //server start-stop
		{
			Input::key[SDLK_s] = 0;
			Server::Init();
			Server::Start();
		}
		
		if(Input::key[SDLK_c]) //client connect-disconnect
		{
			Input::key[SDLK_c] = 0;
			Client::Init();
			Client::Connect();
		}
	}

    SDL_Quit();
 
    return 0;
}
