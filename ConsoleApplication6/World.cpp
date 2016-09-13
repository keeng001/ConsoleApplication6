#include "World.h"



World::World()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			tiles[i][j] = new Terrain();
		}
	}
}

void World::render() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			tiles[i][j]->render();
		}
	}
}



World::~World()
{
}
