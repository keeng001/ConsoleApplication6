#version 330 core

in vec4 outColor;
in vec3 height;

out vec4 color;
lowp float g;

void main(){

	g = float(height.y < 20.0f);
	color = vec4(0.7*g, 0.8*(1.0-g) + 0.1*g, 0.0f, 1.0);
	//color = outColor;
}