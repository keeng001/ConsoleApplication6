#include "Button.h"



Button::Button()
{
}

Button::Button(float x, float y, float sizex, float sizey, std::string text) {

	this->x = x;
	this->y = y;
	this->width = sizex;
	this->height = sizey;
	this->text = text;

	GLfloat vertices[4][3] = {

		{ x, y, 0.0f },
		{ x + width, y, 0.0f},
		{ x , y + height, 0.0f },
		{ x + width, y + height, 0.0f},
	
	};

	GLuint indices[] = {

		0, 1, 2,
		1, 2, 3
	};

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);				

	textprogram = Shader("vertexButton.glsl", "fragmentButton.glsl");

	std::cout << textprogram.Program << std::endl;
	

}



void Button::render() {

	textprogram.Use();

	glm::mat4 projection = glm::ortho(0.0f, 1280.f, 0.0f, 720.f);

	glUniformMatrix4fv(glGetUniformLocation(textprogram.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}


Button::~Button()
{
}
