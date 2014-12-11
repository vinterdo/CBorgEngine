#version 120
#define MAXLIGHTS 25

// Interpolated values from the vertex shaders
varying vec2 UV;
varying vec3 Position_worldspace;
varying vec3 Normal_cameraspace;
varying vec3 EyeDirection_cameraspace;
varying vec3 LightDirections_camspace[MAXLIGHTS];

// Values that stay constant for the whole mesh.
uniform sampler2D mainTex;
uniform mat4 M;
uniform mat4 V;
uniform vec3 pointLPos[MAXLIGHTS];
uniform vec3 pointLCol[MAXLIGHTS];
uniform float pointLPow[MAXLIGHTS];

void main()
{
	mat4 MV = M * V;
	
	vec3 MaterialDiffuseColor = texture2D( mainTex, UV ).rgb;
	vec3 MaterialAmbientColor = vec3(0.4,0.4,0.4) * MaterialDiffuseColor;
	vec3 MaterialSpecularColor = vec3(0.8,0.1,0.1);
	
	gl_FragColor.rgb = MaterialAmbientColor;

	for(int i =0; i < MAXLIGHTS; i++)
	{
		float distance = length( pointLPos[i] - Position_worldspace );

		vec3 n = normalize( Normal_cameraspace );
		vec3 l = normalize( LightDirections_camspace[i] );
		float cosTheta = clamp( dot( n,l ), 0,1 );
	
		vec3 E = normalize(EyeDirection_cameraspace);
		vec3 R = reflect(-l,n);
		float cosAlpha = clamp( dot( E,R ), 0,1 );

		gl_FragColor.rgb += MaterialDiffuseColor * pointLCol[i] * pointLPow[i] * cosTheta / (distance*distance) + 
							MaterialSpecularColor * pointLCol[i] * pointLPow[i] * pow(cosAlpha,70) / (distance*distance);
	}
}