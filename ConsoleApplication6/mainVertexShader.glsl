#version 330 core

layout (location = 0) in vec3 vertex;
in vec2 tex;
out vec4 outColor;
out vec3 height;

uniform mat4 mvp; //mvp multi view pers
uniform mat4 view;



void main(){
	height = vertex;
	gl_Position =  mvp * vec4(vertex, 1.0f);
	
	outColor = vec4(0.0f, 0.5f, 0.0f, 1.0f);

}