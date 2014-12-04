#version 120

varying vec2 UV;
uniform sampler2D mainTex;

void main()
{
	gl_FragColor = texture2D( mainTex, UV );
}