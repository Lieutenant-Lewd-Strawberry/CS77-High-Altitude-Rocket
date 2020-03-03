#pragma once

#include <glew.h>
#include <glfw3.h>

#include <glm.hpp>
#include <vec2.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <mat4x4.hpp>
#include <gtc/type_ptr.hpp>

#include "Mesh.h"

class Readout
{
	private:

		float ReadoutValue;
		float OriginX;
		float OriginY;
		float OriginZ;

		std::string Number;
		Mesh **Numbers;

	public:

		Readout( float Value, float x, float y, float z )
		{
			this->ReadoutValue = Value;
			this->OriginX = x;
			this->OriginY = y + 5;
			this->OriginZ = z + 20;
			
			this->Number = std::to_string( this->ReadoutValue );

			Numbers = new Mesh *[ 11 ];
			for ( int i = 0; i < 11; i++ )
			{
				std::string Object = std::to_string( i );
				Object += ".obj";
				if ( i == 10 )
				{
					Object = "Decimal.obj";
				}
				this->Numbers[ i ] = new Mesh( Object, glm::vec3( this->OriginX, this->OriginY, this->OriginZ ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 20.0f ), glm::vec3( 1.0f ) );
			}

			Update( this->ReadoutValue );
		}

		~Readout( )
		{

		}

		void Update( float Value )
		{
			this->ReadoutValue = Value;
			Number = std::to_string( this->ReadoutValue );
		}

		void Render( Shader* TextShader )
		{
			int Offset = (( 12 * Number.length( ) ) / 2) * -1;
			for ( int i = 0; i < Number.length( ); i++ )
			{
				TextShader->Use( );
				if ( Number.at( i ) == '0' )
				{
					this->Numbers[0]->SetPosition(glm::vec3(this->OriginX + Offset, this->OriginY, this->OriginZ));
					this->Numbers[0]->Render(TextShader);
				}
				if (Number.at(i) == '1')
				{
					this->Numbers[1]->SetPosition(glm::vec3(this->OriginX + Offset, this->OriginY, this->OriginZ));
					this->Numbers[1]->Render(TextShader);
				}
				if (Number.at(i) == '2')
				{
					this->Numbers[2]->SetPosition(glm::vec3(this->OriginX + Offset, this->OriginY, this->OriginZ));
					this->Numbers[2]->Render(TextShader);
				}
				if (Number.at(i) == '3')
				{
					this->Numbers[3]->SetPosition(glm::vec3(this->OriginX + Offset, this->OriginY, this->OriginZ));
					this->Numbers[3]->Render(TextShader);
				}
				if (Number.at(i) == '4')
				{
					this->Numbers[4]->SetPosition(glm::vec3(this->OriginX + Offset, this->OriginY, this->OriginZ));
					this->Numbers[4]->Render(TextShader);
				}
				if (Number.at(i) == '5')
				{
					this->Numbers[5]->SetPosition(glm::vec3(this->OriginX + Offset, this->OriginY, this->OriginZ));
					this->Numbers[5]->Render(TextShader);
				}
				if (Number.at(i) == '6')
				{
					this->Numbers[6]->SetPosition(glm::vec3(this->OriginX + Offset, this->OriginY, this->OriginZ));
					this->Numbers[6]->Render(TextShader);
				}
				if (Number.at(i) == '7')
				{
					this->Numbers[7]->SetPosition(glm::vec3(this->OriginX + Offset, this->OriginY, this->OriginZ));
					this->Numbers[7]->Render(TextShader);
				}
				if (Number.at(i) == '8')
				{
					this->Numbers[8]->SetPosition(glm::vec3(this->OriginX + Offset, this->OriginY, this->OriginZ));
					this->Numbers[8]->Render(TextShader);
				}
				if (Number.at(i) == '9')
				{
					this->Numbers[9]->SetPosition(glm::vec3(this->OriginX + Offset, this->OriginY, this->OriginZ));
					this->Numbers[9]->Render(TextShader);
				}
				if (Number.at(i) == '.')
				{
					this->Numbers[10]->SetPosition(glm::vec3(this->OriginX + Offset + 4, this->OriginY, this->OriginZ));
					this->Numbers[10]->Render(TextShader);
				}
				TextShader->UnUse( );
				Offset += 12;
			}
		}
};