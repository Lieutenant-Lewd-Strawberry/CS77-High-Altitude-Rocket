#version 460

layout ( location = 0 ) in vec3 Position;
layout ( location = 1 ) in vec3 Color;
layout ( location = 2 ) in vec3 Normal;
layout ( location = 3 ) in vec2 TextureCoordinates;

out vec3 vPosition;
out vec3 vColor;
out vec3 vNormal;
out vec2 vTextureCoordinates;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

void main( )
{
	vPosition = vec4( ModelMatrix * vec4( Position, 1.0f ) ).xyz;
	vColor = Color;
	vNormal = mat3( ModelMatrix ) * Normal;
	vTextureCoordinates = vec2( TextureCoordinates.x, TextureCoordinates.y );

	gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * vec4( Position, 1.0f );
}