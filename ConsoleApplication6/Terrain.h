#pragma once
#include <GL\glew.h>

class Terrain
{
private:
	struct Mappart {
		bool bBlocked;
		
	};

	
	GLuint vao, vbo, ebo;
	GLuint tex;


public:
	Terrain();
	~Terrain();

	void render();
};

