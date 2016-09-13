#pragma once


#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>

#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#include <GLFW\glfw3native.h>

#include <Windows.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

#include "renderObjects.h"
#include "Overlay.h"
#include "Button.h"
#include "Map.h"
#include "RandomObject.h"
#include "Camera.h"

#include "Shader.h"
#include "AntTweakBar.h"

#ifndef _RENDERER_H
#define _RENDERER_H

class Renderer
{
private:

	GLFWwindow * win;

	int windowsizeX, windowsizeY;

	renderObjects * obj;
	Overlay * overlay;
	Button * b;
	HWND hwnd;
	HMENU hMenu;
	Map * map;
	Shader * s;
	RandomObject * r;
	GLfloat campos[3];
	glm::mat4 perspective;
	glm::mat4 view;
	TwBar *bar;
	Camera * cam;
	

public:
	Renderer();
	~Renderer();

	bool loop();
	void render();
	



};

#endif