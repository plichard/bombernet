#include "stdafx.h"
#include "world.h"

namespace World
{
	int w = 0;
	int h = 0;
	GameTile* tiles = NULL;

	SDL_Surface* i_wall = NULL, *i_grass = NULL, *screen = NULL;

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
		printf("display\n");
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

		SDL_Flip(screen);
	}
}