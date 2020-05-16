#pragma once

#include <iostream>
#include <vector>

#include "Vertex.h"
#include "Primitive.h"
#include "Shader.h"
#include "Texture.h"
#include "Material.h"


// Mesh class, primitive object that makes a 3D object and pushes it to the GPU, do not modify.
class Mesh
{
	private:

		unsigned VertexCount;
		unsigned IndexCount;

		GLuint VAO;
		GLuint VBO;
		GLuint EBO;

		glm::vec3 Position;
		glm::vec3 Rotation;
		glm::vec3 Scale;

		glm::mat4 ModelMatrix;

		void InitializeVAO( const std::string &Name, glm::vec3 InColor = glm::vec3( 1.0f ) )
		{
			const IndexedModel Model = OBJModel( Name ).ToIndexedModel( );

			this->VertexCount = Model.positions.size( );
			this->IndexCount = Model.indices.size( );

			Vertex *VertexList = ( Vertex * )malloc( sizeof( Vertex ) * this->VertexCount );
			GLuint *IndexList = ( GLuint * )malloc( sizeof( GLuint ) * this->IndexCount );

			for ( int i = 0; i < this->VertexCount; i++ )
			{
				VertexList[ i ].Position.x = Model.positions.at( i ).x;
				VertexList[ i ].Position.y = Model.positions.at( i ).y;
				VertexList[ i ].Position.z = Model.positions.at( i ).z;

				VertexList[ i ].Color = InColor;

				VertexList[ i ].Normal.x = Model.normals.at( i ).x;
				VertexList[ i ].Normal.y = Model.normals.at( i ).y;
				VertexList[i].Normal.z = Model.normals.at(i).z;

				VertexList[ i ].TextureCoordinates.x = Model.texCoords.at( i ).x;
				VertexList[ i ].TextureCoordinates.y = Model.texCoords.at( i ).y;
			}

			for ( int i = 0; i < IndexCount; i++ )
			{
				IndexList[ i ] = Model.indices.at( i );
			}

			glCreateVertexArrays( 1, &this->VAO );
			glBindVertexArray( this->VAO );

			glGenBuffers( 1, &this->VBO );
			glBindBuffer( GL_ARRAY_BUFFER, this->VBO );
			glBufferData( GL_ARRAY_BUFFER, this->VertexCount * sizeof( Vertex ), VertexList, GL_STATIC_DRAW );

			glGenBuffers( 1, &this->EBO );
			glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, this->EBO );
			glBufferData( GL_ELEMENT_ARRAY_BUFFER, this->IndexCount * sizeof( GLuint ), IndexList, GL_STATIC_DRAW );

			glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )offsetof( Vertex, Position ) );
			glEnableVertexAttribArray( 0 );
			glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )offsetof( Vertex, Color ) );
			glEnableVertexAttribArray( 1 );
			glVertexAttribPointer( 2, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )offsetof( Vertex, Normal ) );
			glEnableVertexAttribArray( 2 );
			glVertexAttribPointer( 3, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )offsetof( Vertex, TextureCoordinates ) );
			glEnableVertexAttribArray( 3 );
			
			glBindVertexArray( 0 );
		}

		void InitializeVAO( Primitive *Primitive )
		{
			this->VertexCount = Primitive->GetVertexCount( );
			this->IndexCount = Primitive->GetIndexCount( );

			glCreateVertexArrays( 1, &this->VAO );
			glBindVertexArray( this->VAO );

			glGenBuffers( 1, &this->VBO );
			glBindBuffer( GL_ARRAY_BUFFER, this->VBO );
			glBufferData( GL_ARRAY_BUFFER, this->VertexCount * sizeof( Vertex ), Primitive->GetVertices( ), GL_STATIC_DRAW );

			glGenBuffers( 1, &this->EBO );
			glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, this->EBO );
			glBufferData( GL_ELEMENT_ARRAY_BUFFER, this->IndexCount * sizeof( GLuint ), Primitive->GetIndices( ), GL_STATIC_DRAW );

			glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )offsetof( Vertex, Position ) );
			glEnableVertexAttribArray( 0 );
			glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )offsetof( Vertex, Color ) );
			glEnableVertexAttribArray( 1 );
			glVertexAttribPointer( 2, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )offsetof( Vertex, Normal ) );
			glEnableVertexAttribArray( 2 );
			glVertexAttribPointer( 3, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )offsetof( Vertex, TextureCoordinates ) );
			glEnableVertexAttribArray( 3 );

			glBindVertexArray( 0 );
		}

		void InitializeVAO( Vertex *VertexList, const unsigned &VertexCount, GLuint *IndexList, const unsigned &IndexCount )
		{
			this->VertexCount = VertexCount;
			this->IndexCount = IndexCount;

			glCreateVertexArrays( 1, &this->VAO );
			glBindVertexArray( this->VAO );

			glGenBuffers( 1, &this->VBO );
			glBindBuffer( GL_ARRAY_BUFFER, this->VBO );
			glBufferData( GL_ARRAY_BUFFER, this->VertexCount * sizeof( Vertex ), VertexList, GL_STATIC_DRAW );

			glGenBuffers( 1, &this->EBO );
			glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, this->EBO );
			glBufferData( GL_ELEMENT_ARRAY_BUFFER, this->IndexCount * sizeof( GLuint ), IndexList, GL_STATIC_DRAW );

			glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )offsetof( Vertex, Position ) );
			glEnableVertexAttribArray( 0 );
			glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )offsetof( Vertex, Color ) );
			glEnableVertexAttribArray( 1 );
			glVertexAttribPointer( 2, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )offsetof( Vertex, Normal ) );
			glEnableVertexAttribArray( 2 );
			glVertexAttribPointer( 3, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), ( GLvoid * )offsetof( Vertex, TextureCoordinates ) );
			glEnableVertexAttribArray( 3 );

			glBindVertexArray( 0 );
		}

		void UpdateUniforms( Shader *Shader )
		{
			Shader->SetMatrix4fv( this->ModelMatrix, "ModelMatrix", GL_FALSE );
		}

		void UpdateModelMatrix( )
		{
			this->ModelMatrix = glm::mat4( 1.0f );
			this->ModelMatrix = glm::translate( this->ModelMatrix, this->Position );
			this->ModelMatrix = glm::rotate( this->ModelMatrix, glm::radians( this->Rotation.x ), glm::vec3( 1.0f, 0.0f, 0.0f ) );
			this->ModelMatrix = glm::rotate( this->ModelMatrix, glm::radians( this->Rotation.y ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
			this->ModelMatrix = glm::rotate( this->ModelMatrix, glm::radians( this->Rotation.z ), glm::vec3( 0.0f, 0.0f, 1.0f ) );
			this->ModelMatrix = glm::scale( this->ModelMatrix, this->Scale );
		}

	public:

		Mesh( )
		{

		}

		Mesh( const std::string &Name, glm::vec3 Position = glm::vec3( 0.0f ), glm::vec3 Rotation = glm::vec3( 0.0f ), glm::vec3 Scale = glm::vec3( 1.0f ), glm::vec3 InColor = glm::vec3( 1.0f ) )
		{
			this->Position = Position;
			this->Rotation = Rotation;
			this->Scale = Scale;

			this->InitializeVAO( Name, InColor );
			this->UpdateModelMatrix( );
		}

		Mesh( Primitive *Primitive, glm::vec3 Position = glm::vec3( 0.0f ), glm::vec3 Rotation = glm::vec3( 0.0f ), glm::vec3 Scale = glm::vec3( 1.0f ) )
		{
			this->Position = Position;
			this->Rotation = Rotation;
			this->Scale = Scale;

			this->InitializeVAO( Primitive );
			this->UpdateModelMatrix( );
		}

		Mesh( Vertex *VertexList, const unsigned &VertexCount, GLuint *IndexList, const unsigned &IndexCount, glm::vec3 Position = glm::vec3( 0.0f ), glm::vec3 Rotation = glm::vec3( 0.0f ), glm::vec3 Scale = glm::vec3( 1.0f ) )
		{
			this->Position = Position;
			this->Rotation = Rotation;
			this->Scale = Scale;

			this->InitializeVAO( VertexList, VertexCount, IndexList, IndexCount );
			this->UpdateModelMatrix( );
		}

		~Mesh( )
		{
			glDeleteVertexArrays( 1, &this->VAO );
			glDeleteBuffers( 1, &this->VBO );
			glDeleteBuffers( 1, &this->EBO );
		}

		void SetPosition( const glm::vec3 Position )
		{
			this->Position = Position;
		}

		void SetRotation( const glm::vec3 Rotation )
		{
			this->Rotation = Rotation;
		}

		void SetScale( const glm::vec3 Scale )
		{
			this->Scale = Scale;
		}

		void Move( const glm::vec3 Position )
		{
			this->Position += Position;
		}

		void Rotate( const glm::vec3 Rotation )
		{
			this->Rotation += Rotation;
		}

		void ScaleUp( const glm::vec3 Scale )
		{
			this->Scale += Scale;
		}

		void Update(  )
		{

		}

		void Render( Shader *Shader )
		{
			this->UpdateModelMatrix( );
			this->UpdateUniforms( Shader );
			Shader->Use( );

			glBindVertexArray( this->VAO );

			glDrawElements( GL_TRIANGLES, this->IndexCount, GL_UNSIGNED_INT, 0 );

			glBindVertexArray( 0 );
		}
};