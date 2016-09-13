#pragma once
#include "Renderer.h"
#include "World.h"

#ifndef _GAME_H
#define _GAME_H

class Game
{
private:
	bool bRun;
	Renderer * currentRenderer;
	World * _world;
	
	

public:
	Game();
	~Game();


	void loop();
};
#endif