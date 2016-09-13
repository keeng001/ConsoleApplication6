#pragma once

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>


class Camera
{
	glm::vec3 position;
	glm::vec3 target;
	glm::vec3 up;
public:

	Camera();
	~Camera();


	glm::mat4 getCamera();

	void setCamera(glm::vec3 newPos, glm::vec3 newTarget, glm::vec3 newUp);
		
};

