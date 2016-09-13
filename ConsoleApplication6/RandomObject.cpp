#include "RandomObject.h"




RandomObject::RandomObject()
{
	GLfloat vertices[8][3] = {
		{ 0.0f, 0.0f, 0.0f},
		{ 5.0f, 0.0f, 0.0f },
		{ 0.0f, 5.0f, 0.0f },
		{ 5.0f, 5.0f, 0.0f },

		{ 0.0f, 0.0f, 5.0f },
		{ 5.0f, 0.0f, 5.0f },
		{ 0.0f, 5.0f, 5.0f },
		{ 5.0f, 5.0f, 5.0f }
		
	};
	GLuint indices[] = {
		0, 1, 2,
		1, 2, 3,

		4, 5, 6,
		5, 6, 7,

		0, 1, 4,
		1, 4, 5,

		0, 2, 4,
		2, 4, 6,

		2, 3, 6, 
		3, 6, 7,

		1, 3, 5, 
		3, 5, 7	
	};

	position = glm::vec3(100, 100, 20);

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
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, )

	glBindVertexArray(0);
	position = glm::vec3(100.0f, 80.f, 100.f);
}

void RandomObject::render(Camera * cam, Shader * s) {
	glBindVertexArray(vao);
	glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
	glm::mat4 view = cam->getCamera();
	glm::mat4 perspective = glm::perspective(45.f, (float)1280 / (float)720, 0.1f, 1000.f);

	glm::mat4 mvp = perspective * view * model;
	glUniformMatrix4fv(glGetUniformLocation(s->Program, "mvp"), 1, GL_FALSE, glm::value_ptr(mvp));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);


}


void RandomObject::move(glm::vec3 pos) {

	position = pos;
}


RandomObject::~RandomObject()
{
}
