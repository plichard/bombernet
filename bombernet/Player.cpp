#include "StdAfx.h"
#include "Player.h"
#include "input.h"

Player::Player(int u,int d,int l ,int r)
{
	m_pos.x = 0;
	m_pos.y = 0;
	m_pos.w = TILE_SIZE;
	m_pos.h = TILE_SIZE;
	m_pos_screen.w = TILE_SIZE;
	m_pos_screen.h = TILE_SIZE;
	up = u;
	down = d;
	left = l;
	right = r;
}

SDL_Rect& Player::GetPos()
{
	return m_pos;
}

SDL_Rect& Player::GetScreenPos()
{
	return m_pos;
}

void Player::Update()
{
	if(Input::key[down])
	{
		//Input::key[SDLK_DOWN] = 0;
		m_pos.y++;
	}
	if(Input::key[up])
	{
		//Input::key[SDLK_UP] = 0;
		m_pos.y--;
	}
	if(Input::key[left])
	{
		//Input::key[SDLK_LEFT] = 0;
		m_pos.x--;
	}
	if(Input::key[right])
	{
		//Input::key[SDLK_RIGHT] = 0;
		m_pos.x++;
	}
}

Player::~Player(void)
{
}
