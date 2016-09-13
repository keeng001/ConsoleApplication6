#include "Camera.h"



Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::setCamera(glm::vec3 newPos, glm::vec3 newTarget, glm::vec3 newUp) {
	position = newPos;
	target = newTarget;
	up = newUp;
}

glm::mat4 Camera::getCamera() {
	return glm::lookAt(position, position + target, up);
}