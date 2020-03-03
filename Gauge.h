#pragma once

#include <glm.hpp>

#include "Texture.h"
#include "Mesh.h"

class Gauge
{
	public:

		enum Numbers {  };

		glm::vec3 Position;
		float Min;
		float Max;
		float Change;

		double CurrentData;
		double PreviousData;
		double DeltaData;

		Mesh *GaugeMesh;
		Mesh *DialMesh;
//		Mesh NameMesh;
//		Mesh DataMesh;
		std::string NumberList[ 11 ];
		Mesh ***Numbers;

		Gauge( glm::vec3 Position, float Min, float Max )
		{
			this->Position = Position;
			this->Min = Min;
			this->Max = Max;
			this->Change = ( Max - Min ) / 300;
			
			int Step = Min;
			for ( int i = 0; i < 11; i++ )
			{
				NumberList[ i ] = std::to_string( Step );
				Step += ( Max - Min ) / 10;

			}

			this->CurrentData = 0;
			this->PreviousData = 0;
			this->DeltaData = 0;

			this->GaugeMesh = new Mesh( "Gauge.obj", Position, glm::vec3( 90.0f, -90.0f, 0.0f ), glm::vec3( 100.0f ) );
			this->DialMesh = new Mesh( "Dial.obj", glm::vec3( Position ), glm::vec3( 90.0f, 60.0f, 0.0f ), glm::vec3( 130.0f ), glm::vec3( 1.0f, 0.0f, 0.0f ) );

			Numbers = new Mesh **[ 11 ];
			for ( int i = 0; i < 11; i++ )
			{
				int Size = NumberList[ i ].length( );
				Numbers[ i ] = new Mesh*[ Size ];
				int Offset = 0;
				for ( int j = 0; j < NumberList[ i ].length( ); j++ )
				{
					std::string Object = "";
					Object.push_back( NumberList[ i ][ j ] ); 
					Object += ".obj";

					switch ( i )
					{
						case 0:
							this->Numbers[ i ][ j ] = new Mesh( Object, glm::vec3( Position.x - 50 + Offset, Position.y - 75, Position.z + 15 ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 15.0f ), glm::vec3( 1.0f ) );
							break;
						case 1:
							this->Numbers[ i ][ j ] = new Mesh( Object, glm::vec3( Position.x - 85 + Offset, Position.y - 45, Position.z + 15 ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 15.0f ), glm::vec3( 1.0f ) );
							break;
						case 2:
							this->Numbers[ i ][ j ] = new Mesh( Object, glm::vec3( Position.x - 100 + Offset, Position.y - 5, Position.z + 15 ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 15.0f ), glm::vec3( 1.0f ) );
							break;
						case 3:
							this->Numbers[ i ][ j ] = new Mesh( Object, glm::vec3( Position.x - 90 + Offset, Position.y + 35, Position.z + 15 ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 15.0f ), glm::vec3( 1.0f ) );
							break;
						case 4:
							this->Numbers[ i ][ j ] = new Mesh( Object, glm::vec3( Position.x - 58 + Offset, Position.y + 68, Position.z + 15 ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 15.0f ), glm::vec3( 1.0f ) );
							break;
						case 5:
							this->Numbers[ i ][ j ] = new Mesh( Object, glm::vec3( Position.x - 13 + Offset, Position.y + 80, Position.z + 15 ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 15.0f ), glm::vec3( 1.0f ) );
							break;
						case 6:
							this->Numbers[ i ][ j ] = new Mesh( Object, glm::vec3( Position.x + 30 + Offset, Position.y + 68, Position.z + 15 ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 15.0f ), glm::vec3( 1.0f ) );
							break;
						case 7:
							this->Numbers[ i ][ j ] = new Mesh( Object, glm::vec3( Position.x + 63 + Offset, Position.y + 35, Position.z + 15 ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 15.0f ), glm::vec3( 1.0f ) );
							break;
						case 8:
							this->Numbers[ i ][ j ] = new Mesh( Object, glm::vec3( Position.x + 74 + Offset, Position.y - 5, Position.z + 15 ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 15.0f ), glm::vec3( 1.0f ) );
							break;
						case 9:
							this->Numbers[ i ][ j ] = new Mesh( Object, glm::vec3( Position.x + 63 + Offset, Position.y - 45, Position.z + 15 ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 15.0f ), glm::vec3( 1.0f ) );
							break;
						case 10:
							this->Numbers[ i ][ j ] = new Mesh( Object, glm::vec3( Position.x + 25 + Offset, Position.y - 75, Position.z + 15 ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 15.0f ), glm::vec3( 1.0f ) );
							break;
					}
					Offset += 8;
					if ( Object == "1.obj" )
					{
						Offset -= 4;
					}
				}
			}
		}

		~Gauge( )
		{
			delete this->GaugeMesh;
			delete this->DialMesh;
		}

		int *GetValues( )
		{

		}

		void Update( float Data  )
		{ 


			this->CurrentData = Data;

			if ( this->CurrentData > this->Max && this->PreviousData < this->Max )
			{
				float Fix = this->Max - this->PreviousData;
				this->DialMesh->Rotate( glm::vec3( 0.0f, -( Fix ) / this->Change, 0.0f ) );
			}

			this->DeltaData = this->CurrentData - this->PreviousData;
			this->PreviousData = this->CurrentData;

			if ( this->CurrentData < this->Max )
			{
				this->DialMesh->Rotate( glm::vec3( 0.0f, -( this->DeltaData ) / this->Change, 0.0f ) );
			}
		}

		void Render( Shader *TextShader, Shader *GaugeShader, Shader *DialShader )
		{
			GaugeShader->Use( );
			this->GaugeMesh->Render( GaugeShader );
			GaugeShader->UnUse( );

			DialShader->Use( );
			this->DialMesh->Render( DialShader );
			DialShader->UnUse( );

			for ( int i = 0; i < 11; i++ )
			{
				for ( int j = 0; j < NumberList[ i ].length( ); j++ )
				{
					TextShader->Use( );
					this->Numbers[ i ][ j ]->Render( TextShader );
					TextShader->UnUse( );
				}
			}
		}
};