#include "Map.h"



Map::Map()
{

	GLfloat vertices[64 * 64][3]; 

	GLuint indices[63 * 63 * 6];

	GLfloat texcoord[] = {
		1
	};

	int k = 0;
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 64; j++) {
			vertices[k][0] = (GLfloat)i * 10; 
			if (i < 6 || i > 57) {
				vertices[k][1] = 40.0f;
			}
			else {

				vertices[k][1] = 10.0f;
			}
			
			vertices[k++][2] = (GLfloat)j * 10;
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


			/*indices[k++] = l;
			indices[k++] = m;
			indices[k++] = n;
			indices[k++] = o;*/
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


Map::~Map()
{
}

void Map::render() {
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 64 * 64 * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}