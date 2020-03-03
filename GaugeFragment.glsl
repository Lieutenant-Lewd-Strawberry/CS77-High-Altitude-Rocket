#version 460

struct Material
{
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;
	sampler2D DiffuseTexture;
	sampler2D SpecularTexture;
};

in vec3 vPosition;
in vec3 vColor;
in vec3 vNormal;
in vec2 vTextureCoordinates;

out vec4 fColor;

uniform Material MaterialInfo;
uniform vec3 LightPosition1;
uniform vec3 Camera;

vec3 CalculateAmbient( Material Material1 )
{
	return Material1.Ambient;
}

vec3 CalculateDiffuse( Material Material1, vec3 vPosition, vec3 vNormal, vec3 LightPosition1 )
{
	vec3 PositionToLightDirection = normalize( LightPosition1 - vPosition );
	float Diffuse = clamp( dot( PositionToLightDirection, vNormal ), 0, 1 );
	vec3 FinalDiffuse = Material1.Diffuse * Diffuse;

	return FinalDiffuse;
}

vec3 CalculateSpecular( Material Material1, vec3 vPosition, vec3 vNormal, vec3 LightPosition1, vec3 Camera )
{
	vec3 LightToPositionDirection = normalize( vPosition - LightPosition1 );
	vec3 ReflectDirection = normalize( reflect( LightToPositionDirection, normalize( vNormal ) ) );
	vec3 PositionToViewDirection = normalize( Camera - vPosition );
	float Specular = pow( max( dot( PositionToViewDirection, ReflectDirection ), 0 ), 35 );
	vec3 FinalSpecular = Material1.Specular * Specular;

	return FinalSpecular;
}

void main( )
{
	vec3 FinalAmbient = CalculateAmbient( MaterialInfo );
	vec3 FinalDiffuse = CalculateDiffuse( MaterialInfo, vPosition, vNormal, LightPosition1 );
	vec3 FinalSpecular = CalculateSpecular( MaterialInfo, vPosition, vNormal, LightPosition1, Camera );

	fColor =  texture( MaterialInfo.DiffuseTexture, vTextureCoordinates ) * vec4( vColor, 1.0f ) * ( vec4( FinalAmbient, 1.0f ) + vec4( FinalDiffuse, 1.0f ) + vec4( FinalSpecular, 1.0f ) );
}