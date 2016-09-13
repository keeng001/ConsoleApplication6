#pragma once
#include <GL\glew.h>
class GUIelemente
{
protected:
	GLuint vao, vbo;
public:
	GUIelemente();
	~GUIelemente();

	virtual void render() = 0;
};

class Textfield : public GUIelemente {


public:
	Textfield();
	~Textfield();

	void render();

};