#pragma once
#ifndef _OVERLAY_H
#define _OVERLAY_H

#include <GL\glew.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#include <map>

#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtc\matrix_transform.hpp>

#include "Shader.h"
#include <string>

class Overlay
{
protected:
	FT_Library ft;
	FT_Face face;


	struct Character {
		GLuint     TextureID;  // ID handle of the glyph texture
		glm::ivec2 Size;       // Size of glyph
		glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
		GLuint     Advance;    // Offset to advance to next glyph
	};

	std::map<GLchar, Character> Characters;

	GLuint vao, vbo;
	
	
public:
	Overlay();
	~Overlay();

	Shader textprogram;
	void  RenderText(Shader &s, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
};

#endif