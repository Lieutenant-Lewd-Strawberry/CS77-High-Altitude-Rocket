#pragma once

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>
#include <gtc/type_ptr.hpp>

#include "Shader.h"

class Material
{
	private:

		glm::vec3 Ambient;
		glm::vec3 Diffuse;
		glm::vec3 Specular;
		GLint DiffuseTexture;
		GLint SpecularTexture;

	public:

		Material( glm::vec3 Ambient, glm::vec3 Diffuse, glm::vec3 Specular, GLint DiffuseTexture, GLint SpecularTexture )
		{
			this->Ambient = Ambient;
			this->Diffuse = Diffuse;
			this->Specular = Specular;
			this->DiffuseTexture = DiffuseTexture;
			this->SpecularTexture = SpecularTexture;
		}

		~Material( )
		{

		}

		void SendToShader( Shader &ID )
		{
			ID.SetVector3fv( this->Ambient, "MaterialInfo.Ambient" );
			ID.SetVector3fv( this->Diffuse, "MaterialInfo.Diffuse" );
			ID.SetVector3fv( this->Specular, "MaterialInfo.Specular" );
			ID.SetInteger1i( this->DiffuseTexture, "MaterialInfo.DiffuseTexture" );
			ID.SetInteger1i( this->SpecularTexture, "MaterialInfo.SpecularTexture" );
		}
};