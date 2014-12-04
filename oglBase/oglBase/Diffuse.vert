#version 120

attribute vec3 vertexPosition_modelspace;
attribute vec2 vertexUV;

varying vec2 UV;

uniform mat4 MVP;

void main()
{
	gl_Position =  MVP * vec4(vertexPosition_modelspace,1);
	UV = vertexUV;
}

