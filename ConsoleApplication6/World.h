#pragma once
#include "Terrain.h"  
#ifndef _WORLD_H
#define _WORLD_H

class World
{
private:
	Terrain * tiles[4][4];
public:
	World();
	~World();

	void render();


};
#endif

