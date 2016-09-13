
#include "Renderer.h"
#include <ostream>

inline void TwEventMouseButtonGLFW3(GLFWwindow* window, int button, int action, int mods)
{
	TwEventMouseButtonGLFW(button, action);
}
inline void TwEventMousePosGLFW3(GLFWwindow* window, double xpos, double ypos)
{
	TwMouseMotion(int(xpos), int(ypos));
}
inline void TwEventMouseWheelGLFW3(GLFWwindow* window, double xoffset, double yoffset)
{
	TwEventMouseWheelGLFW(yoffset);
}
inline void TwEventKeyGLFW3(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	TwEventKeyGLFW(key, action);
}
inline void TwEventCharGLFW3(GLFWwindow* window, int codepoint)
{
	TwEventCharGLFW(codepoint, GLFW_PRESS);
}
inline void TwWindowSizeGLFW3(GLFWwindow* window, int width, int height)
{
	TwWindowSize(width, height);
}


Renderer::Renderer()
{
	windowsizeX = 1280, windowsizeY = 720;
	glfwInit();

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL 

	win = glfwCreateWindow(1280, 720, "Tower Defense", NULL, NULL);
	glfwMakeContextCurrent(win);


	TwInit(TW_OPENGL_CORE, NULL);

	// Create a tweak bar
	bar = TwNewBar("TweakBar");
	TwWindowSize(1280, 720);

	campos[0] = 320.0f;
	campos[1] = 300.0f;
	campos[2] = 320.0f;

	cam = new Camera();
	cam->setCamera(glm::vec3(320.0f, 300.0f, 320.0f), glm::vec3(320, -10, 310), glm::vec3(0.0f, 1.0f, 0.0f));

	TwDefine(" GLOBAL help='This example shows how to integrate AntTweakBar with GLFW and OpenGL.' "); // Message added to the help bar.
																									   // Add 'wire' to 'bar': it is a modifable variable of type TW_TYPE_BOOL32 (32 bits boolean). Its key shortcut is [w].
	// Add 'bgColor' to 'bar': it is a modifable variable of type TW_TYPE_COLOR3F (3 floats color)
	TwAddVarRW(bar, "bgColor1", TW_TYPE_FLOAT, &campos[0], " label='Cam Pos x' ");
	TwAddVarRW(bar, "bgColor2", TW_TYPE_FLOAT, &campos[1], " label='Cam Pos y' ");
	TwAddVarRW(bar, "bgColor3", TW_TYPE_FLOAT, &campos[2], " label='Cam Pos z' ");


	glfwSetWindowSizeCallback(win, (GLFWwindowposfun)TwWindowSizeGLFW3);

	glfwSetMouseButtonCallback(win, (GLFWmousebuttonfun)TwEventMouseButtonGLFW3);
	glfwSetCursorPosCallback(win, (GLFWcursorposfun)TwEventMousePosGLFW3);
	glfwSetScrollCallback(win, (GLFWscrollfun)TwEventMouseWheelGLFW3);
	glfwSetKeyCallback(win, (GLFWkeyfun)TwEventKeyGLFW3);
	glfwSetCharCallback(win, (GLFWcharfun)TwEventCharGLFW3);
	


	
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) std::cout << "GLEW FAILED" << std::endl;


	overlay = new Overlay();

	b = new Button(0, 0, 1280, 200, "Verbinden");
	map = new Map();

	s = new Shader("mainVertexShader.glsl", "mainFragmentShader.glsl");
	r = new RandomObject();
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}


bool Renderer::loop() {

	double lastTime = glfwGetTime();
	int nbFrames = 0;
	
	glm::vec3 position = glm::vec3(campos[0], campos[1], campos[2]);
	glm::vec3 direction = position + glm::vec3(320, -10, 310);


	//camera = glm::perspective(45.0f, (float)1280 / (float)720, 0.1f, 1000.0f);
	//look = cam->getCamera();

	


	//while (!glfwWindowShouldClose(win)) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		cam->setCamera(glm::vec3(campos[0], campos[1], campos[2]), glm::vec3(0, -50, 50), glm::vec3(0.0f, 1.0f, 0.0f));

		perspective = glm::perspective(45.0f, (float)1280 / (float)720, 0.1f, 1000.0f);
		view = cam->getCamera();

		glm::mat4 mvp = perspective * view;
		
		s->Use();
		glUniformMatrix4fv(glGetUniformLocation(s->Program, "mvp"), 1, GL_FALSE, glm::value_ptr(mvp));
		//glUniformMatrix4fv(glGetUniformLocation(s->Program, "view"), 1, GL_FALSE, glm::value_ptr(look));
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		map->render();
		r->render(cam, s);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		//overlay->RenderText(overlay->textprogram, "FPS:" + fps, 1100.f, 700.f, 0.5f, glm::vec3(0.3f, 0.8f, 0.2f));
		overlay->RenderText(overlay->textprogram, "Hallo", 100.f, 50.f, 1.f, glm::vec3(0.3f, 0.8f, 0.2f));
	
		b->render();
		TwDraw();

		glfwPollEvents();
		glfwSwapBuffers(win);

	//}

	return true;
}


Renderer::~Renderer()
{
}


