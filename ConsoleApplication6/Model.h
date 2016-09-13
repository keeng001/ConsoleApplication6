#pragma once
#include <GL\glew.h>
#include <glm.hpp>
#include <string>

class Model
{
private:
	GLuint vao, vbo, ebo;
	//glm::vec3 pos;
	//glm::vec3 rot;

public:
	Model();
	Model(std::string filepath);
	~Model();
};

