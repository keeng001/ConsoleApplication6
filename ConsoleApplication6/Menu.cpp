#include "Menu.h"



Menu::Menu()
{
	glfwInit();


	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL 


	window = glfwCreateWindow(480, 320, "Menu", NULL, NULL);
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) std::cout << "GLEW FAILED" << std::endl;



	glfwSetCursorPosCallback(window, this->cursor_position_callback);
	glfwSetWindowUserPointer(window, this);
	//glfwSetMouseButtonCallback(window, this->mouse_button_callback);








	







	//buttons.push_back(b1);
    //buttons.push_back(b2);
	 

} 

void Menu::loop() {


}

Menu::~Menu()
{
}

void Menu::cursor_position_callback(GLFWwindow * window, double xpos, double ypos) {

	Menu * menu = reinterpret_cast<Menu *>(glfwGetWindowUserPointer(window));

	//std::cout << "x: " << xpos << " y: " << ypos << std::endl;
	menu->x = xpos;
	menu->y = ypos;

}
