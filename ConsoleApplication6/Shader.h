#ifndef _SHADER_H
#define _SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


#include <GL/glew.h>

class Shader
{
public:
	GLuint Program;
	// Constructor generates the shader on the fly
	Shader(const char* vertexPath, const char* fragmentPath);

	// Uses the current shader
	void Use()
	{
		glUseProgram(this->Program);
	}

	Shader() {

	};
};

#endif