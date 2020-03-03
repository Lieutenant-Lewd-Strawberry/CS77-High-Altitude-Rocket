#pragma once

#include <iostream>
#include <string>

#include <glew.h>
#include <glfw3.h>

class Texture
{
	private:

		GLuint ID;
		int Width;
		int Height;
		unsigned int Type;

	public:

		Texture( const char *Filename, GLenum Type )
		{
			this->Type = Type;

			stbi_set_flip_vertically_on_load( true );
			unsigned char *TextureData = stbi_load( Filename, &this->Width, &this->Height, NULL, STBI_rgb_alpha );

			glGenTextures( 1, &this->ID );
			glBindTexture( Type, this->ID );

			glTexParameteri( Type, GL_TEXTURE_WRAP_S, GL_REPEAT );
			glTexParameteri( Type, GL_TEXTURE_WRAP_T, GL_REPEAT );
			glTexParameteri( Type, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR );
			glTexParameteri( Type, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

			if ( TextureData )
			{
				glTexImage2D( Type, 0, GL_RGBA, this->Width, this->Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, TextureData );
				glGenerateMipmap( Type );
			}
			else
			{
				std::cout << "Error loading texture data from " << Filename << "!" << std::endl;
			}

			glActiveTexture( 0 );
			glBindTexture( Type, 0 );
			stbi_image_free( TextureData );
		}

		~Texture( )
		{
			glDeleteTextures( 1, &this->ID );
		}

		inline GLuint GetID( ) const
		{
			return this->ID;
		}

		void Bind( const GLint TextureUnit )
		{
			glActiveTexture( GL_TEXTURE0 + TextureUnit );
			glBindTexture( this->Type, this->ID );
		}

		void UnBind( )
		{
			glActiveTexture( 0 );
			glBindTexture( this->Type, 0 );
		}

		void LoadFromFile( const char *Filename )
		{
			if ( this->ID )
			{
				glDeleteTextures( 1, &this->ID );
			}

			stbi_set_flip_vertically_on_load( true );
			unsigned char *TextureData = stbi_load( Filename, &this->Width, &this->Height, NULL, STBI_rgb_alpha );

			glGenTextures( 1, &this->ID );
			glBindTexture( this->Type, this->ID );

			glTexParameteri( this->Type, GL_TEXTURE_WRAP_S, GL_REPEAT );
			glTexParameteri( this->Type, GL_TEXTURE_WRAP_T, GL_REPEAT );
			glTexParameteri( this->Type, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR );
			glTexParameteri( this->Type, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

			if ( TextureData )
			{
				glTexImage2D( this->Type, 0, GL_RGBA, this->Width, this->Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, TextureData );
				glGenerateMipmap( this->Type );
			}
			else
			{
				std::cout << "Error loading texture data from " << Filename << "!" << std::endl;
			}

			glActiveTexture( 0 );
			glBindTexture( this->Type, 0 );
			stbi_image_free( TextureData );
		}
};