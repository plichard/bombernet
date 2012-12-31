#pragma once


class Player
{
public:
	Player(int,int,int,int);
	~Player(void);
	SDL_Rect& GetPos();
	SDL_Rect& GetScreenPos();
	void Update();

private:
	int m_speed;
	int m_bombs;
	SDL_Rect m_pos;
	SDL_Rect m_pos_screen;

	int up,down,left,right;
};

typedef std::vector<Player*> PlayerVec;