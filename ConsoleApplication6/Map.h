#pragma once
#include <GL\glew.h>
#include "Shader.h"


class Map
{
	struct Mappart {
		bool bBlocked;
		
	};

	//Mappart mp[50][50];
	GLuint vao, vbo, ebo;
	

public:
	Map();
	~Map();

	void render();
};

