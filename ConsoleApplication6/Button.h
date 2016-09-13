#pragma once
#ifndef _BUTTON_H
#define _BUTTON_H

#include <GL\glew.h>
#include <string>
#include "Shader.h"

#include "glm.hpp"
#include "gtc\matrix_transform.hpp"
#include "gtc\type_ptr.hpp"

class Button
{
private:
	GLfloat x, y;
	GLfloat width, height;
	std::string text;
	
	GLuint vao, vbo, ebo;
	Shader textprogram;

public:
	Button();
	Button(float x, float y, float sizex, float sizey, std::string text);
	void render();
	~Button();
};

#endif