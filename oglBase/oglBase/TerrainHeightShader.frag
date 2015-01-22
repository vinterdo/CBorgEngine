#version 120
in vec3 fragmentColor;

void main()
{
	gl_FragColor = vec4(fragmentColor, 1);
}