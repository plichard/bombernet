#include "stdafx.h"
#include "world.h"
#include "Player.h"

namespace World
{
	int w = 0;
	int h = 0;
	GameTile* tiles = NULL;
	PlayerVec players;

	SDL_Surface* i_wall = NULL,
		*i_grass = NULL,
		*screen = NULL,
		*i_player = NULL;

	void SetScreen(SDL_Surface* surf)
	{
		screen = surf;
	}

	void Init(int _w, int _h)
	{
		w = _w;
		h = _h;
		tiles = new GameTile[w*h];
		i_wall = SDL_LoadBMP("images/wall.bmp"); if(!i_wall){printf("[world] could not load wall.bmp");}
		i_grass = SDL_LoadBMP("images/grass.bmp"); if(!i_grass){printf("[world] could not load grass.bmp");}
		i_player = SDL_LoadBMP("images/player.bmp");if(!i_player){printf("[world] could not load player.bmp");}
			SDL_SetColorKey(i_player,SDL_SRCCOLORKEY,SDL_MapRGB(i_player->format,255,0,255));


			players.push_back(new Player(SDLK_UP,SDLK_DOWN,SDLK_LEFT,SDLK_RIGHT));
			players.push_back(new Player(SDLK_w,SDLK_s,SDLK_a,SDLK_d));
	}

	int GetW()
	{
		return w;
	}

	int GetH()
	{
		return h;
	}

	GameTile& GetTile(int x, int y)
	{
		return tiles[y*w + h];
	}

	void Display()
	{
		SDL_Rect t_pos;
		t_pos.w = TILE_SIZE;
		t_pos.h = TILE_SIZE;
		for(t_pos.x = 0; t_pos.x < w*TILE_SIZE; t_pos.x+=TILE_SIZE)
		{
			for(t_pos.y = 0; t_pos.y < h*TILE_SIZE; t_pos.y+=TILE_SIZE)
			{
				if(GetTile(t_pos.x/TILE_SIZE,t_pos.y/TILE_SIZE).wall)
				{
					SDL_BlitSurface(i_wall,NULL,screen,&t_pos);
				}
				else
				{
					SDL_BlitSurface(i_grass,NULL,screen,&t_pos);
				}
			}
		}

		//display players
		for(int i = 0; i < players.size(); i++)
		{
			SDL_BlitSurface(i_player,NULL,screen,&players[i]->GetScreenPos());
		}

		SDL_Flip(screen);
	}

	void Update()
	{
		for(int i = 0; i < players.size(); i++)
		{
			players[i]->Update();
		}
	}
}