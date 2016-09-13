#include "Terrain.h"



Terrain::Terrain()
{
	int size = 64;
	int count = size * size;
	GLfloat * vertices = new GLfloat[count * 3];
	GLfloat * normals = new GLfloat[count * 3];
	GLfloat * textureCoords = new GLfloat[count * 2];

	GLuint * indices = new GLuint[6 * (size - 1) * (size - 1)];

	

	int k = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			vertices[k * 3] = (float)j / ((float)size - 1) * 64;
			vertices[k * 3 + 1] = 10.0f;
			vertices[k * 3 + 2] = (float)i / ((float)size - 1) * 64;;

			normals[k * 3] = 0;
			normals[k * 3 + 1] = 1;
			normals[k * 3 + 2] = 0;
			textureCoords[k * 2] = (float)j / ((float)size - 1);
			textureCoords[k * 2 + 1] = (float)i / ((float)size - 1);
			k++;
		}
	}

	k = 0;

	for (int i = 0; i < 63; i++) {
		for (int j = 0; j < 63; j++) {
			int l = (i * 64) + j;
			int m = l + 1;
			int n = ((i + 1) * 64) + j;
			int o = n + 1;
			indices[k++] = l;
			indices[k++] = n;
			indices[k++] = m;
			indices[k++] = m;
			indices[k++] = n;
			indices[k++] = o;

		}
	}



	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);


	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}


Terrain::~Terrain()
{
}

void Terrain::render() {
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 64 * 64 * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}