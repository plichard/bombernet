#pragma once
#include "stdafx.h"

enum EVENT_TYPE{OBSTACLE_CREATED, BOOST_CREATED, BOMB_CREATED, BOOST_TAKEN};

class GameEvent
{
public:
	GameEvent( int _id, int _x, int _y);
	virtual ~GameEvent(void);
	uint frame; //when did the event happen?  (keep it synchro between the pcs)
	uint type;
	int x,y;
	int id;
};

