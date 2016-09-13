#pragma once
#include <GL\glew.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
#include "Camera.h"
#include "Shader.h"

class RandomObject
{
private:
	GLuint vao, vbo, ebo;
	glm::vec3 position;

public:
	RandomObject();
	~RandomObject();

	void render(Camera * cam, Shader * s);
	void move(glm::vec3 pos);
};

