#include "Game.h"



Game::Game()
{
	//Renderer
	currentRenderer = new Renderer();
	//Physics
	//Network
	//Sound


	_world = new World();






	bRun = true;
}

void Game::loop() {

	while (bRun) {

		
		currentRenderer->loop();


		
		
	}
}


Game::~Game()
{
}
