#version 120
#define MAXLIGHTS 12

attribute vec3 vertexPosition_modelspace;
attribute vec2 vertexUV;
attribute vec3 normals;

varying vec2 UV;
varying vec3 Position_worldspace;
varying vec3 Normal_cameraspace;
varying vec3 EyeDirection_cameraspace;
varying vec3 LightDirections_camspace[MAXLIGHTS];

uniform mat4 MVP;
uniform mat4 V;
uniform mat4 M;
uniform vec3 pointLPos[MAXLIGHTS];
uniform vec3 pointLCol[MAXLIGHTS];
uniform float pointLPow[MAXLIGHTS];

void main()
{
	gl_Position =  MVP * vec4(vertexPosition_modelspace,1);
	
	Position_worldspace = (M * vec4(vertexPosition_modelspace,1)).xyz;
	
	vec3 vertexPosition_cameraspace = ( V * M * vec4(vertexPosition_modelspace,1)).xyz;
	EyeDirection_cameraspace = vec3(0,0,0) - vertexPosition_cameraspace;

	for(int i =0; i < MAXLIGHTS; i++)
	{
		vec3 LightPosition_cameraspace = ( V * vec4(pointLPos[i],1)).xyz;
		LightDirections_camspace[i] = LightPosition_cameraspace + EyeDirection_cameraspace;
	}
	
	Normal_cameraspace = ( V * M * vec4(normals,0)).xyz; // Only correct if ModelMatrix does not scale the model ! Use its inverse transpose if not.
	
	UV = vertexUV;
}

