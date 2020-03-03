#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>
#include <gtc/type_ptr.hpp>

class Shader
{
	private:

		GLuint ID;
		const int Major;
		const int Minor;

		std::string LoadShaderSource( const char *Filename )
		{
			std::string Buffer = "";
			std::string Source = "";
			std::ifstream InFile;

			InFile.open( Filename );
			if ( InFile.is_open( ) )
			{
				while ( std::getline( InFile, Buffer ) )
				{
					Source += Buffer + "\n";
				}
			}
			else
			{
				std::cout << "Error: Failed to import " << Filename << "!" << std::endl;
			}
			InFile.close( );

			std::string Version = std::to_string( this->Major ) + std::to_string( this->Minor ) + "0";
			Source.replace( Source.find( "#version" ), 12, ( "#version " + Version ) );

			return Source;
		}

		GLuint LoadShader( GLenum Type, const char *Filename )
		{
			GLint Success;
			char Logger[ 512 ];

			GLuint Shader = glCreateShader( Type );
			std::string ShaderSource = this->LoadShaderSource( Filename );
			const GLchar *Source = ShaderSource.c_str( );
			glShaderSource( Shader, 1, &Source, NULL );
			glCompileShader( Shader );

			glGetShaderiv( Shader, GL_COMPILE_STATUS, &Success );
			if ( !Success )
			{
				glGetShaderInfoLog( Shader, 512, NULL, Logger );
				std::cout << "Error: Failed to compile " << Filename << "!" << std::endl;
				std::cout << Logger << "\n";
			}

			return Shader;
		}

		void LinkShader( GLuint VertexShader, GLuint TessellationControlShader, GLuint TessellationEvaluationShader, GLuint GeometryShader, GLuint FragmentShader )
		{
			GLint Success;
			char Logger[ 512 ];

			this->ID = glCreateProgram( );

			glAttachShader( this->ID, VertexShader );

			if ( TessellationControlShader )
			{
				glAttachShader( this->ID, TessellationControlShader );
			}
			if ( TessellationEvaluationShader )
			{
				glAttachShader( this->ID, TessellationEvaluationShader );
			}
			if ( GeometryShader )
			{
				glAttachShader( this->ID, GeometryShader );
			}

			glAttachShader( this->ID, FragmentShader );

			glLinkProgram( this->ID );

			glGetProgramiv( this->ID, GL_LINK_STATUS, &Success );
			if ( !Success )
			{
				glGetProgramInfoLog( this->ID, 512, NULL, Logger );
				std::cout << "Error: Failed to link shaders!" << std::endl;
				std::cout << Logger << "\n";
			}

			glUseProgram( 0 );
		}

	public:

		Shader( const int Major, const int Minor, const char *VertexFile, const char *TessellationControlFile, const char* TessellationEvaluationFile, const char *GeometryFile, const char *FragmentFile ) : Major( Major ), Minor( Minor )
		{
			GLuint VertexShader = 0;
			GLuint TessellationControlShader = 0;
			GLuint TessellationEvaluationShader = 0;
			GLuint GeometryShader = 0;
			GLuint FragmentShader = 0;

			VertexShader = LoadShader( GL_VERTEX_SHADER, VertexFile );

			if ( TessellationControlFile != "" )
			{
				TessellationControlShader = LoadShader( GL_TESS_CONTROL_SHADER, TessellationControlFile );
			}
			if ( TessellationEvaluationFile != "" )
			{
				TessellationEvaluationShader = LoadShader( GL_TESS_EVALUATION_SHADER, TessellationEvaluationFile );
			}
			if ( GeometryFile != "" )
			{
				GeometryShader = LoadShader( GL_GEOMETRY_SHADER, GeometryFile );
			}

			FragmentShader = LoadShader( GL_FRAGMENT_SHADER, FragmentFile );

			this->LinkShader( VertexShader, TessellationControlShader, TessellationEvaluationShader, GeometryShader, FragmentShader );

			glDeleteShader( VertexShader );
			glDeleteShader( TessellationControlShader );
			glDeleteShader( TessellationEvaluationShader );
			glDeleteShader( GeometryShader );
			glDeleteShader( FragmentShader );
		}

		~Shader( )
		{
			glDeleteProgram( this->ID );
		}

		void Use(  )
		{
			glUseProgram( this->ID );
		}

		void UnUse( )
		{
			glUseProgram( 0 );
		}

		void SetInteger1i( GLint Value, const GLchar *Name )
		{
			this->Use( );

			glUniform1i( glGetUniformLocation( this->ID, Name ), Value );

			this->UnUse( );
		}

		void SetFloat1f( GLfloat Value, const GLchar *Name )
		{
			this->Use( );

			glUniform1f( glGetUniformLocation( this->ID, Name ), Value );

			this->UnUse( );
		}

		void SetVector2fv( glm::fvec2 Value, const GLchar *Name )
		{
			this->Use( );

			glUniform2fv( glGetUniformLocation( this->ID, Name ), 1, glm::value_ptr( Value ) );

			this->UnUse( );
		}

		void SetVector3fv( glm::fvec3 Value, const GLchar *Name )
		{
			this->Use( );

			glUniform3fv( glGetUniformLocation( this->ID, Name ), 1, glm::value_ptr( Value ) );

			this->UnUse( );
		}

		void SetVector4fv( glm::fvec4 Value, const GLchar *Name )
		{
			this->Use( );

			glUniform4fv( glGetUniformLocation( this->ID, Name ), 1, glm::value_ptr( Value ) );

			this->UnUse( );
		}

		void SetMatrix3fv( glm::mat3 Value, const GLchar *Name, GLboolean Transpose )
		{
			this->Use( );

			glUniformMatrix3fv( glGetUniformLocation( this->ID, Name ), 1, Transpose, glm::value_ptr( Value ) );

			this->UnUse( );
		}

		void SetMatrix4fv( glm::mat4 Value, const GLchar *Name, GLboolean Transpose )
		{
			this->Use( );

			glUniformMatrix4fv( glGetUniformLocation( this->ID, Name ), 1, Transpose, glm::value_ptr( Value ) );

			this->UnUse( );
		}
};