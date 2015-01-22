#version 120

attribute vec3 vertexPosition_modelspace;
uniform mat4 MVP;
varying vec3 fragmentColor;

void main()
{
	// Output position of the vertex, in clip space : MVP * position
	gl_Position =  MVP * vec4(vertexPosition_modelspace,1);

	float ht = vertexPosition_modelspace.y * 15;

	if      (ht < 0  )   fragmentColor = vec3(0.,       0.,        1.); //blue
    else if (ht < 500)   fragmentColor = vec3(0.,       ht/500,    0.); //->green
    else if (ht < 1000)  fragmentColor = vec3(ht/500-1, 1.,        0.); //->yellow
    else if (ht < 2000)  fragmentColor = vec3(1.,       2.-ht/1000,0.); //->red
    else                 fragmentColor = vec3(1.,1.,1.);                //white

}

