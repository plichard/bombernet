#pragma once
#include "stdafx.h"

class GameEvent
{
public:
	GameEvent(void);
	virtual ~GameEvent(void);
	uint frame; //when did the event happen?  (keep it synchro between the pcs)
};

