#define STB_IMAGE_IMPLEMENTATION

#include "GUI.h"

int main( int argc, char ** argv )
{
	GUI RocketGUI( "Rocket GUI", 1600, 900, 4, 6, GL_TRUE );

	while ( !RocketGUI.GetWindowShouldClose( ) )
	{
		RocketGUI.Update( );
		RocketGUI.Render( );
	}

	return 0;
}