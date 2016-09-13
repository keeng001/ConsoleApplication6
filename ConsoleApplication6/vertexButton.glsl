#version 330 core
layout (location = 0) in vec2 vertex; // <vec2 pos, vec2 tex>

out vec4 vertexColor;

uniform mat4 projection;

void main()
{
    gl_Position = projection * vec4(vertex, 0.0f, 1.0f);
    vertexColor = vec4(0.5f, 0.0f, 0.0f, 0.2f); // Set the output variable to a dark-red color
}  