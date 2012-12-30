#pragma once
#include "stdafx.h"
#include "Player.h"

enum BONUS_TYPE
{
	BOMB,
	POWER
};

typedef struct GameBonus
{
	GameBonus(int t)
	{
		type = t;
	}
	int type;
}GameBonus;

typedef struct GameTile
{
	GameTile()
	{
		wall = false;
		player = NULL;
		bonus = NULL;
	}
	bool wall;
	Player* player;
	GameBonus* bonus;

}GameTile;

namespace World
{
	void SetScreen(SDL_Surface* surf);
	void Init(int w, int h);
	int GetW();
	int GetH();
	GameTile& GetTile(int x, int y);
	void Display();
}