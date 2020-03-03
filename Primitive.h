#pragma once

#include <glew.h>
#include <glfw3.h>

#include <vector>

#include "Vertex.h"

class Primitive
{
	private:

		std::vector< Vertex > Vertices;
		std::vector< GLuint > Indices;

	public:

		Primitive( )
		{

		}

		virtual ~Primitive( )
		{

		}

		void Set( const Vertex *VertexList, const unsigned VertexCount, const GLuint *IndexList, const unsigned IndexCount )
		{
			for ( size_t i = 0; i < VertexCount; i++ )
			{
				this->Vertices.push_back( VertexList[ i ] );
			}

			for ( size_t i = 0; i < IndexCount; i++ )
			{
				this->Indices.push_back( IndexList[ i ] );
			}
		}

		inline Vertex *GetVertices( )
		{
			return this->Vertices.data( );
		}

		inline GLuint *GetIndices( )
		{
			return this->Indices.data( );
		}

		inline const unsigned GetVertexCount( )
		{
			return this->Vertices.size( );
		}

		inline const unsigned GetIndexCount( )
		{
			return this->Indices.size( );
		}
};

class Triangle : public Primitive
{
	public:

		Triangle( ) : Primitive( )
		{
			Vertex VertexList[ ] =
			{
				glm::vec3( 0.0f, 0.5f, 0.0f ), glm::vec3( 1.0f, 1.0f, 1.0f ), glm::vec3( 0.0f, 0.0f, 1.0f ), glm::vec2( 0.0f, 1.0f ),
				glm::vec3( -0.5f, -0.5f, 0.0f ), glm::vec3( 1.0f, 1.0f, 1.0f ), glm::vec3( 0.0f, 0.0f, 1.0f ), glm::vec2( 0.0f, 0.0f ),
				glm::vec3( 0.5f, -0.5f, 0.0f ), glm::vec3( 1.0f, 1.0f, 1.0f ), glm::vec3( 0.0f, 0.0f, 1.0f ), glm::vec2( 1.0f, 0.0f ),
			};
			unsigned VertexCount = ( sizeof( VertexList ) / sizeof( Vertex ) );

			GLuint IndexList[ ] =
			{
				0, 1, 2
			};
			unsigned IndexCount = ( sizeof( IndexList ) / sizeof( GLuint ) );

			this->Set( VertexList, VertexCount, IndexList, IndexCount );
		}
};

class Quad : public Primitive
{
	public:

		Quad( ) : Primitive( )
		{
			Vertex VertexList[ ] =
			{
				glm::vec3( -0.5f, 0.5f, 0.0f ), glm::vec3( 1.0f, 1.0f, 1.0f ), glm::vec3( 0.0f, 0.0f, 1.0f ), glm::vec2( 0.0f, 1.0f ),
				glm::vec3( -0.5f, -0.5f, 0.0f ), glm::vec3( 1.0f, 1.0f, 1.0f ), glm::vec3( 0.0f, 0.0f, 1.0f ), glm::vec2( 0.0f, 0.0f ),
				glm::vec3( 0.5f, -0.5f, 0.0f ), glm::vec3( 1.0f, 1.0f, 1.0f ), glm::vec3( 0.0f, 0.0f, 1.0f ), glm::vec2( 1.0f, 0.0f ),
				glm::vec3( 0.5f, 0.5f, 0.0f ), glm::vec3( 1.0f, 1.0f, 1.0f ), glm::vec3( 0.0f, 0.0f, 1.0f ), glm::vec2( 1.0f, 1.0f )
			};
			unsigned VertexCount = ( sizeof( VertexList ) / sizeof( Vertex ) );

			GLuint IndexList[ ] =
			{
				0, 1, 2,
				0, 2, 3
			};
			unsigned IndexCount = ( sizeof( IndexList ) / sizeof( GLuint ) );

			this->Set( VertexList, VertexCount, IndexList, IndexCount );
		}
};