#version 120
uniform vec3 color;

void main()
{
	gl_FragColor = vec4(color,1);
	gl_FragColor = vec4(0,1,0,1);
}