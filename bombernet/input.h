#pragma once
#include "stdafx.h"

namespace Input
{
	extern char key[SDLK_LAST];
	extern int mousex,mousey;
	extern int mousexrel,mouseyrel;
	extern char mousebuttons[8];
    extern char quit;
	void UpdateEvents();
	int Init();
}