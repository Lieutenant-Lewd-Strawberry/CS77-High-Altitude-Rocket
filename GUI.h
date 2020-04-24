#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <stb_image.h>
#include "obj_loader.h"

#include "Vertex.h"
#include "Primitive.h"
#include "Shader.h"
#include "Texture.h"
#include "Material.h"
#include "Mesh.h"
#include "Booster.h"
#include "Sustainer.h"
#include "TelemString.h"
#include "TelemStringTypes/TelemSensorData.h"
#include "TelemStringTypes/TelemKalmanVoltage.h"
#include "TelemStringTypes/TelemGPS.h"
#include "TelemParser.h"

class GUI
{
	private:

		enum SHADERS { GAUGE_SHADER = 0, DIAL_SHADER = 1, TEXT_SHADER = 2, HART_SHADER = 3, PLATE_SHADER = 4, RED_TEXT_SHADER = 5};
		enum MESHES { GAUGE_MESH = 0, DIAL_MESH = 1, TEXT_MESH = 2 };
		enum TEXTURES { GAUGE_TEXTURE = 0, HART_TEXTURE = 1, PLATE_TEXTURE = 2 };
		enum MATERIALS { GAUGE_MATERIAL = 0, DIAL_MATERIAL = 1, TEXT_MATERIAL = 2, HART_MATERIAL = 3, PLATE_MATERIAL = 4, RED_TEXT_MATERIAL = 2 };
		enum LIGHTS { CENTER_LIGHT = 0 };

		const int Width;
		const int Height;
		int FrameBufferWidth;
		int FrameBufferHeight;
		int Major;
		int Minor;
		bool Resizable;
		double Time;
		GLFWwindow *Window;

		glm::vec3 Up;
		glm::vec3 Front;
		glm::vec3 Camera;
		glm::mat4 ViewMatrix;

		//bool ProjectionMode = false;
		float FieldOfView;
		float NearPlane;
		float FarPlane;
		glm::mat4 ProjectionMatrix;

		std::vector< Shader * > Shaders;
		std::vector< Mesh * > Meshes;
		std::vector< Texture * > Textures;
		std::vector< Material * > Materials;
		std::vector< glm::vec3 * > Lights;

		Booster *BoosterBox;
		Sustainer *SustainerBox;

		static void WindowKeyboardInput( GLFWwindow *Window, int Key, int ScanCode, int Action, int Mods )
		{
			if ( Key == GLFW_KEY_ESCAPE && Action == GLFW_PRESS )
			{
				glfwSetWindowShouldClose( Window, GLFW_TRUE );
			}
/*
			if ( Key == GLFW_KEY_W && Action == GLFW_PRESS )
			{
				Meshes[ GAUGE_MESH ]->Move( glm::vec3( 0.0f, 0.0001f, 0.0f ) );
			}
			if ( glfwGetKey( Window, GLFW_KEY_S ) == GLFW_PRESS )
			{
				Mesh.Move( glm::vec3( 0.0f, -0.0001f, 0.0f ) );
			}
			if ( glfwGetKey( Window, GLFW_KEY_A ) == GLFW_PRESS )
			{
				Mesh.Move( glm::vec3( -0.0001f, 0.0f, 0.0f ) );
			}
			if ( glfwGetKey( Window, GLFW_KEY_D ) == GLFW_PRESS )
			{
				Mesh.Move( glm::vec3( 0.0001f, 0.0f, 0.0f ) );
			}
			if ( glfwGetKey( Window, GLFW_KEY_Q ) == GLFW_PRESS )
			{
				Mesh.Rotate( glm::vec3(0.0f, -0.01f, 0.0f ) );
			}
			if ( glfwGetKey( Window, GLFW_KEY_E ) == GLFW_PRESS )
			{
				Mesh.Rotate( glm::vec3( 0.0f, 0.01f, 0.0f ) );
			}
			if ( glfwGetKey( Window, GLFW_KEY_R) == GLFW_PRESS )
			{
				Mesh.Rotate( glm::vec3( -0.01f, 0.0f, 0.0f ) );
			}
			if ( glfwGetKey( Window, GLFW_KEY_T ) == GLFW_PRESS )
			{
				Mesh.Rotate( glm::vec3( 0.01f, 0.0f, 0.0f ) );
			}
			if ( glfwGetKey( Window, GLFW_KEY_Z ) == GLFW_PRESS )
			{
				Mesh.ScaleUp( glm::vec3( 0.001f ) );
			}
			if ( glfwGetKey( Window, GLFW_KEY_X ) == GLFW_PRESS )
			{
				Mesh.ScaleUp( glm::vec3( -0.001f ) );
			}
			*/
		}
		
		void InitializeGLFW( )
		{
			if ( glfwInit( ) == GLFW_FALSE )
			{
				std::cout << "Error: Failed to initialize GLFW!" << std::endl;
				glfwTerminate( );
			}
		}

		static void WindowResizeCallback( GLFWwindow *Window, int FrameBufferWidth, int FrameBufferHeight )
		{
			glViewport( 0, 0, FrameBufferWidth, FrameBufferHeight );
		}

		void SetWindowShouldClose( )
		{
			glfwSetWindowShouldClose( this->Window, GLFW_TRUE );
		}


		void InitializeWindow( const char *Name, bool Resizable )
		{
			glfwWindowHint( GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE );
			glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, this->Major );
			glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, this->Minor ); 
			glfwWindowHint( GLFW_RESIZABLE, Resizable );

			this->Window = glfwCreateWindow( this->Width, this->Height, Name, NULL, NULL );

			int Width;
			int Height;
			unsigned char* TextureData = stbi_load( "HART.png", &Width, &Height, NULL, STBI_rgb_alpha );
			const GLFWimage Image{ Width, Height, TextureData };
			glfwSetWindowIcon( this->Window, 1, &Image ) ;

			if ( this->Window == nullptr )
			{
				std::cout << "Error: Failed to create Window!" << std::endl;
				glfwTerminate( );
			}

			glfwGetFramebufferSize( this->Window, &this->FrameBufferWidth, &this->FrameBufferHeight );
			glfwSetFramebufferSizeCallback( this->Window, this->WindowResizeCallback );
			glfwSetKeyCallback( this->Window, this->WindowKeyboardInput );

			glfwMakeContextCurrent( this->Window );
		}

		void InitializeGLEW( )
		{
			glewExperimental = GL_TRUE;

			if ( glewInit( ) != GLEW_OK )
			{
				std::cout << "Error: Failed to initialize GLEW!" << std::endl;
				glfwTerminate( );
			}
		}

		void InitializeOpenGL( )
		{
			glEnable( GL_DEPTH_TEST );

			//glEnable( GL_CULL_FACE );
			//glCullFace( GL_BACK );
			glFrontFace( GL_CCW );

			glEnable( GL_BLEND );
			glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

			glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
		}

		void InitializeMatrices( )
		{
			this->ViewMatrix = glm::mat4( 1.0f );
			this->ViewMatrix = glm::lookAt( this->Camera, this->Camera + this->Front, this->Up );

			this->ProjectionMatrix = glm::mat4( 1.0f );
			this->ProjectionMatrix = glm::ortho( 0.0f, ( float )( this->Width ), 0.0f, ( float )( this->Height ), -1.0f, 100.0f );//glm::perspective( glm::radians( this->FieldOfView ), static_cast< float >( this->FrameBufferWidth ) / this->FrameBufferHeight, this->NearPlane, this->FarPlane );
		}

		void InitializeShaders( )
		{
			this->Shaders.push_back( new Shader( this->Major, this->Minor, "GaugeVertex.glsl", "", "", "", "GaugeFragment.glsl" ) );
			this->Shaders.push_back( new Shader( this->Major, this->Minor, "DialVertex.glsl", "", "", "", "DialFragment.glsl" ) );
			this->Shaders.push_back( new Shader( this->Major, this->Minor, "TextVertex.glsl", "", "", "", "TextFragment.glsl" ) );
			this->Shaders.push_back( new Shader( this->Major, this->Minor, "GaugeVertex.glsl", "", "", "", "GaugeFragment.glsl" ) );
			this->Shaders.push_back( new Shader( this->Major, this->Minor, "GaugeVertex.glsl", "", "", "", "GaugeFragment.glsl" ) );
			this->Shaders.push_back( new Shader( this->Major, this->Minor, "TextVertex.glsl", "", "", "", "TextFragment.glsl" ) );
		}

		void InitializeMeshes( )
		{
			this->BoosterBox = new Booster( );
			this->SustainerBox = new Sustainer( );
			this->Meshes.push_back( new Mesh( &Quad( ), glm::vec3( this->Width / 2, this->Height / 2 + 50, -50 ), glm::vec3( 0.0f, 0.0f, 0.0f ), glm::vec3( 2000 ) ) );
			this->Meshes.push_back( new Mesh( "Readout.obj", glm::vec3( this->Width / 2, this->Height / 2 + 50, -25 ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 220.0f * 0.6f, 5, 450.0f * 0.6f ) ) );
			this->Meshes.push_back( new Mesh( "Apogee.obj", glm::vec3( Width / 2, 819.0f, -10.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 20.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) ) );
			this->Meshes.push_back( new Mesh( "Readout.obj", glm::vec3( Width / 2, 843.0f, -40.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 35.0f, 35.0f, 35.0f) ) );
			this->Meshes.push_back( new Mesh( "Angle.obj", glm::vec3( 860.0f, 50.0f, -10.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 20.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) ) );
			this->Meshes.push_back( new Mesh( "Readout.obj", glm::vec3( Width / 2, 105.0f, -40.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 50.0f, 50.0f, 90.0f ) ) );
		}

		void InitializeTextures( )
		{
			this->Textures.push_back( new Texture( "Gauge.png", GL_TEXTURE_2D ) );
			this->Textures.push_back( new Texture( "HART.png", GL_TEXTURE_2D ) );
			this->Textures.push_back( new Texture( "Readout.png", GL_TEXTURE_2D ) );
		}

		void InitializeMaterials( )
		{
			this->Materials.push_back( new Material( glm::vec3( 0.9f ), glm::vec3( 0.0f ), glm::vec3( 0.3f ), GAUGE_TEXTURE, GAUGE_TEXTURE ) );
			this->Materials.push_back( new Material( glm::vec3( 0.5f ), glm::vec3( 0.5f ), glm::vec3( 1.0f ), 0, 0 ) );
			this->Materials.push_back( new Material( glm::vec3( 0.5f ), glm::vec3( 1.0f ), glm::vec3( 1.0f ), 0, 0 ) );
			this->Materials.push_back( new Material( glm::vec3( 0.9f ), glm::vec3( 0.0f ), glm::vec3( 0.0f ), HART_TEXTURE, HART_TEXTURE ) );
			this->Materials.push_back( new Material( glm::vec3( 0.9f ), glm::vec3( 0.0f ), glm::vec3( 0.3f ), PLATE_TEXTURE, PLATE_TEXTURE ) );
			this->Materials.push_back( new Material( glm::vec3( 0.5f ), glm::vec3( 1.0f ), glm::vec3( 1.0f ), 0, 0 ) );
		}

		void InitializeLights( )
		{
			this->Lights.push_back( new glm::vec3( this->Width / 2.0f, this->Height / 2.0f, 1000.0f ) );
		}

		void InitializeUniforms( )
		{
			this->Shaders[ GAUGE_SHADER ]->SetMatrix4fv( this->ViewMatrix, "ViewMatrix", GL_FALSE );
			this->Shaders[ GAUGE_SHADER ]->SetMatrix4fv( this->ProjectionMatrix, "ProjectionMatrix", GL_FALSE );
			this->Shaders[ GAUGE_SHADER ]->SetVector3fv( *this->Lights[ CENTER_LIGHT ], "LightPosition1" );
			this->Shaders[ GAUGE_SHADER ]->SetVector3fv( this->Camera, "Camera" );

			this->Shaders[ DIAL_SHADER ]->SetMatrix4fv( this->ViewMatrix, "ViewMatrix", GL_FALSE );
			this->Shaders[ DIAL_SHADER ]->SetMatrix4fv( this->ProjectionMatrix, "ProjectionMatrix", GL_FALSE );
			this->Shaders[ DIAL_SHADER ]->SetVector3fv( *this->Lights[ CENTER_LIGHT ], "LightPosition1" );
			this->Shaders[ DIAL_SHADER ]->SetVector3fv( this->Camera, "Camera" );

			this->Shaders[ TEXT_SHADER ]->SetMatrix4fv( this->ViewMatrix, "ViewMatrix", GL_FALSE );
			this->Shaders[ TEXT_SHADER ]->SetMatrix4fv( this->ProjectionMatrix, "ProjectionMatrix", GL_FALSE );
			this->Shaders[ TEXT_SHADER ]->SetVector3fv( *this->Lights[ CENTER_LIGHT ], "LightPosition1" );
			this->Shaders[ TEXT_SHADER ]->SetVector3fv( this->Camera, "Camera" );

			this->Shaders[ HART_SHADER ]->SetMatrix4fv( this->ViewMatrix, "ViewMatrix", GL_FALSE );
			this->Shaders[ HART_SHADER ]->SetMatrix4fv( this->ProjectionMatrix, "ProjectionMatrix", GL_FALSE );
			this->Shaders[ HART_SHADER ]->SetVector3fv( *this->Lights[ CENTER_LIGHT ], "LightPosition1" );
			this->Shaders[ HART_SHADER ]->SetVector3fv( this->Camera, "Camera" );

			this->Shaders[ PLATE_SHADER ]->SetMatrix4fv( this->ViewMatrix, "ViewMatrix", GL_FALSE );
			this->Shaders[ PLATE_SHADER ]->SetMatrix4fv( this->ProjectionMatrix, "ProjectionMatrix", GL_FALSE );
			this->Shaders[ PLATE_SHADER ]->SetVector3fv( *this->Lights[CENTER_LIGHT], "LightPosition1" );
			this->Shaders[ PLATE_SHADER ]->SetVector3fv( this->Camera, "Camera" );

			this->Shaders[ RED_TEXT_SHADER ]->SetMatrix4fv( this->ViewMatrix, "ViewMatrix", GL_FALSE );
			this->Shaders[ RED_TEXT_SHADER ]->SetMatrix4fv( this->ProjectionMatrix, "ProjectionMatrix", GL_FALSE );
			this->Shaders[ RED_TEXT_SHADER ]->SetVector3fv( *this->Lights[ CENTER_LIGHT ], "LightPosition1" );
			this->Shaders[ RED_TEXT_SHADER ]->SetVector3fv( this->Camera, "Camera" );
		}

		void UpdateUniforms( )
		{
			glfwGetFramebufferSize( this->Window, &this->FrameBufferWidth, &this->FrameBufferHeight );

			ProjectionMatrix = glm::ortho( 0.0f, ( float )( this->Width ), 0.0f, ( float )( this->Height ), -1.0f, 100.0f );//glm::perspective( glm::radians( this->FieldOfView ), static_cast< float >( this->FrameBufferWidth ) / this->FrameBufferHeight, this->NearPlane, this->FarPlane );

			this->Shaders[ GAUGE_SHADER ]->SetMatrix4fv( ProjectionMatrix, "ProjectionMatrix", GL_FALSE );
			this->Shaders[ DIAL_SHADER ]->SetMatrix4fv( ProjectionMatrix, "ProjectionMatrix", GL_FALSE );
			this->Shaders[ TEXT_SHADER ]->SetMatrix4fv( ProjectionMatrix, "ProjectionMatrix", GL_FALSE );
			this->Shaders[ HART_SHADER ]->SetMatrix4fv( ProjectionMatrix, "ProjectionMatrix", GL_FALSE );
			this->Shaders[ PLATE_SHADER ]->SetMatrix4fv( ProjectionMatrix, "ProjectionMatrix", GL_FALSE );
			this->Shaders[ RED_TEXT_SHADER ]->SetMatrix4fv( ProjectionMatrix, "ProjectionMatrix", GL_FALSE );
		}

		void InitializeVariables( )
		{
			this->Time = glfwGetTime( );
		}

	public:

		GUI( const char *Name, const int Width, const int Height, int Major, int Minor, bool Resizable ) : Width( Width ), Height( Height ), Major( Major ), Minor( Minor )
		{
			this->Window = nullptr;
			this->FrameBufferWidth = this->Width;
			this->FrameBufferHeight = this->Height;

			this->Up = glm::vec3( 0.0f, 1.0f, 0.0f );
			this->Front = glm::vec3( 0.0f, 0.0f, -1.0f );
			this->Camera = glm::vec3( 0.0f, 0.0f, 1.0f );

			this->FieldOfView = 90.0f;
			this->NearPlane = 0.1f;
			this->FarPlane = 1000.0f;

			this->InitializeGLFW( );
			this->InitializeWindow( Name, Resizable );
			this->InitializeGLEW( );
			this->InitializeOpenGL( );
			this->InitializeMatrices( );
			this->InitializeShaders( );
			this->InitializeMeshes( );
			this->InitializeTextures( );
			this->InitializeMaterials( );
			this->InitializeLights( );
			this->InitializeUniforms( );
			this->InitializeVariables( );
		}

		~GUI( )
		{
			glfwDestroyWindow( this->Window );
			glfwTerminate( );

			for ( size_t i = 0; i < this->Shaders.size( ); i++ )
			{
				delete this->Shaders[ i ];
			}
			for ( size_t i = 0; i < this->Meshes.size( ); i++ )
			{
				delete this->Meshes[ i ];
			} 
			for ( size_t i = 0; i < this->Textures.size( ); i++ )
			{
				delete this->Textures[ i ];
			}
			for ( size_t i = 0; i < this->Materials.size( ); i++ )
			{
				delete this->Materials[ i ];
			}
			for ( size_t i = 0; i < this->Lights.size( ); i++ )
			{
				delete this->Lights[ i ];
			}
			delete this->BoosterBox;
		}

		int GetWindowShouldClose( )
		{
			return glfwWindowShouldClose( this->Window );
		}

		void Update( )
		{
			glfwPollEvents( );

			this->BoosterBox->Update( );
			this->SustainerBox->Update( );

			this->Materials[ GAUGE_MATERIAL ]->SendToShader( *this->Shaders[ GAUGE_SHADER ] );
			this->Textures[ GAUGE_TEXTURE ]->Bind( GAUGE_TEXTURE );
			this->Shaders[ GAUGE_SHADER ]->Use( );

			this->Materials[ DIAL_MATERIAL ]->SendToShader( *this->Shaders[ DIAL_SHADER ] );
			this->Shaders[ DIAL_SHADER]->Use( );

			this->Materials[ TEXT_MATERIAL ]->SendToShader( *this->Shaders[ TEXT_SHADER ] );
			this->Shaders[ TEXT_SHADER ]->Use( );

			this->Materials[ HART_MATERIAL ]->SendToShader( *this->Shaders[ HART_SHADER ] );
			this->Textures[ HART_TEXTURE ]->Bind( HART_TEXTURE );
			this->Shaders[ HART_SHADER ]->Use( );

			this->Materials[ PLATE_MATERIAL ]->SendToShader( *this->Shaders[ PLATE_SHADER ] );
			this->Textures[ PLATE_TEXTURE]->Bind( PLATE_TEXTURE );
			this->Shaders[ PLATE_SHADER]->Use( );
		}
		
		void Render( )
		{
			//WindowKeyboardInput( this->Window, *this->Meshes[ GAUGE_MESH ] );

			glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
			glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );

			this->Update( );

			while ( glfwGetTime( ) < this->Time + 1.0f / 60 )
			{
				this->BoosterBox->Render( this->Shaders[ TEXT_SHADER ], this->Shaders[ RED_TEXT_SHADER ], this->Shaders[ PLATE_SHADER ], this->Shaders[ GAUGE_SHADER ], this->Shaders[ DIAL_SHADER ] );
				this->SustainerBox->Render( this->Shaders[ TEXT_SHADER ], this->Shaders[ RED_TEXT_SHADER ], this->Shaders[ PLATE_SHADER ], this->Shaders[ GAUGE_SHADER ], this->Shaders[ DIAL_SHADER ] );
				this->Meshes[ 0 ]->Render( this->Shaders[ HART_SHADER ] );
				this->Meshes[ 1 ]->Render( this->Shaders[ PLATE_SHADER ] ); 
				this->Meshes[ 2 ]->Render( this->Shaders[ TEXT_SHADER ] );
				this->Meshes[ 3 ]->Render( this->Shaders[ PLATE_SHADER ] );
				this->Meshes[ 4 ]->Render( this->Shaders[ TEXT_SHADER ] );
				this->Meshes[ 5 ]->Render( this->Shaders[ PLATE_SHADER ] );
			}
			this->Time += 1.0f / 60;

			glfwSwapBuffers( this->Window );
			glFlush( );

			glBindVertexArray( 0 );
			glUseProgram( 0 );
			glActiveTexture( 0 );
			glBindTexture( GL_TEXTURE_2D, 0 );
		}
};