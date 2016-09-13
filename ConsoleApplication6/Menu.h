#pragma once
#include "Renderer.h"


class Menu : public Renderer
{
private:
	

	GLFWwindow * window;
	//std::vector<Button> buttons;

	double x, y;

	GLuint * program; //
	GLuint vertex_shader_id, fragment_shader_id;



public:
	Menu();
	~Menu();

	void loop();
	static void cursor_position_callback(GLFWwindow * window, double xpos, double ypos);
	//static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    




};

