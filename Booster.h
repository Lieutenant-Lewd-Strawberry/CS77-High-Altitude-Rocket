#pragma once

#include <glm.hpp>

#include "Gauge.h"
#include "Mesh.h"
#include "Readout.h"

class Booster
{
	private:

		Mesh *BoosterTitle;
		Mesh *BoosterPlate;

		Mesh *BoosterSpeedTitle;
		Mesh *BoosterSpeedUnit;
		Gauge *BoosterSpeed;
		Mesh *BoosterSpeedPlate;
		Mesh **SpeedNumbers;
		float Speed;
		Readout *BoosterSpeedReadout;

		Mesh *BoosterAccelerationTitle;
		Mesh *BoosterAccelerationUnit;
		Gauge *BoosterAcceleration;
		Mesh *BoosterAccelerationPlate;
		float Acceleration;
		Readout* BoosterAccelerationReadout;

		Mesh *BoosterAltitudeTitle;
		Mesh *BoosterAltitudeUnit;
		Mesh *BoosterAltitudePlate;
		float Altitude;
		Readout* BoosterAltitudeReadout;

		Mesh* BoosterLatitudeTitle;
		Mesh* BoosterLatitudePlate;
		float Latitude;
		Readout* BoosterLatitudeReadout;

		Mesh* BoosterLongitudeTitle;
		Mesh* BoosterLongitudePlate;
		float Longitude;
		Readout* BoosterLongitudeReadout;

	public:

		Booster( )
		{
			this->BoosterTitle = new Mesh( "Bootsie.obj", glm::vec3( 157.5f, 858.0f, -10.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 50.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
			this->BoosterPlate = new Mesh( "Readout.obj", glm::vec3( 157.5f, 858.0f, -40.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 35.0f, 35.0f, 35.0f ) );

			this->BoosterSpeedTitle = new Mesh( "Speed.obj", glm::vec3( 145.0f, 490.0f, -10.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 20.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
			this->BoosterSpeedUnit = new Mesh( "FTS.obj", glm::vec3( 190.0f, 493.0f, -10.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 12.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
			this->BoosterSpeed = new Gauge( glm::vec3( 160, 660, -20.0f ), 0, 1200 );
			this->BoosterSpeedPlate = new Mesh( "Readout.obj", glm::vec3( 157.5f, 510.0f, -40.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 35.0f, 35.0f, 35.0f ) );
			this->Speed = 115.4224;
			this->BoosterSpeedReadout = new Readout( this->Speed, 157.5f, 510.0f, -40.0f );

			this->BoosterAccelerationTitle = new Mesh( "Acceleration.obj", glm::vec3( 142.0f, 140.0f, -10.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 20.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
			this->BoosterAccelerationUnit = new Mesh( "FTS2.obj", glm::vec3( 220.0f, 143.0f, -10.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 12.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
			this->BoosterAcceleration = new Gauge( glm::vec3( 160, 310, -20.0f ), 0, 400 );
			this->BoosterAccelerationPlate = new Mesh( "Readout.obj", glm::vec3( 157.5f, 160.0f, -40.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 35.0f, 35.0f, 35.0f ) );
			this->Acceleration = 355.5;
			this->BoosterAccelerationReadout = new Readout(this->Acceleration, 157.5f, 160.0f, -40.0f);

			this->BoosterAltitudeTitle = new Mesh( "Altitude.obj", glm::vec3( 150.0f, 40.0f, -10.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 20.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
			this->BoosterAltitudeUnit = new Mesh( "FT.obj", glm::vec3( 200, 43.0f, -10.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 12.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
			this->BoosterAltitudePlate = new Mesh( "Readout.obj", glm::vec3( 157.5f, 60.0f, -40.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 35.0f, 35.0f, 35.0f ) );
			this->Altitude = 2323;
			this->BoosterAltitudeReadout = new Readout(this->Speed, 157.5f, 60.0f, -40.0f);

			this->BoosterLatitudeTitle = new Mesh( "Latitude.obj", glm::vec3( 460.0f, 140.0f, -10.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 20.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
			this->BoosterLatitudePlate = new Mesh( "Readout.obj", glm::vec3( 457.5f, 160.0f, -40.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 35.0f, 35.0f, 35.0f ) );
			this->Latitude = 100203.0402;
			this->BoosterLatitudeReadout = new Readout(this->Speed, 457.5f, 160.0f, -40.0f);

			this->BoosterLongitudeTitle = new Mesh( "Longitude.obj", glm::vec3( 460.0f, 40.0f, -10.0f ), glm::vec3( 90.0f, 0.0f, 0.0f), glm::vec3( 20.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) );
			this->BoosterLongitudePlate = new Mesh( "Readout.obj", glm::vec3( 457.5f, 60.0f, -40.0f ), glm::vec3( 90.0f, 0.0f, 0.0f), glm::vec3( 35.0f, 35.0f, 35.0f ) );
			this->Longitude = 400203.0402;
			this->BoosterLongitudeReadout = new Readout(this->Speed, 457.5f, 60.0f, -40.0f);

			this->Update( );
		}

		~Booster( )
		{
			delete this->BoosterTitle;
			delete this->BoosterSpeed;
		}

		void Update( )
		{
			this->BoosterSpeed->Update( this->Speed );
			this->Speed += .01;
			this->BoosterSpeedReadout->Update( this->Speed );

			this->BoosterAcceleration->Update( this->Acceleration);
			this->Acceleration += .03;
			this->BoosterAccelerationReadout->Update( this->Acceleration);

			this->Altitude += 100;
			this->BoosterAltitudeReadout->Update( this->Altitude );

			this->Latitude += 0.3;
			this->BoosterLatitudeReadout->Update( this->Latitude );

			this->Longitude += 0.1;
			this->BoosterLongitudeReadout->Update( this->Longitude );
		}

		void Render( Shader *TextShader, Shader *PlateShader, Shader *GaugeShader, Shader *DialShader )
		{
			TextShader->Use( );
			BoosterTitle->Render( TextShader );
			TextShader->UnUse( );
			PlateShader->Use( );
			BoosterPlate->Render( PlateShader );
			PlateShader->UnUse( );

			TextShader->Use( );
			BoosterSpeedTitle->Render( TextShader );
			TextShader->UnUse( );
			TextShader->Use( );
			BoosterSpeedUnit->Render( TextShader );
			TextShader->UnUse( );
			BoosterSpeed->Render( TextShader, GaugeShader, DialShader );
			PlateShader->Use( );
			BoosterSpeedPlate->Render( PlateShader );
			PlateShader->UnUse( );
			TextShader->Use( );
			BoosterSpeedReadout->Render( TextShader );
			TextShader->UnUse( );

			TextShader->Use( );
			BoosterAccelerationTitle->Render( TextShader );
			TextShader->UnUse( );
			TextShader->Use( );
			BoosterAccelerationUnit->Render( TextShader );
			TextShader->UnUse( );
			BoosterAcceleration->Render( TextShader, GaugeShader, DialShader );
			PlateShader->Use( );
			BoosterAccelerationPlate->Render( PlateShader );
			PlateShader->UnUse( );
			TextShader->Use( );
			BoosterAccelerationReadout->Render( TextShader );
			TextShader->UnUse( );

			TextShader->Use( );
			BoosterAltitudeTitle->Render( TextShader );
			TextShader->UnUse( );
			TextShader->Use( );
			BoosterAltitudeUnit->Render( TextShader );
			TextShader->UnUse( );
			PlateShader->Use( );
			BoosterAltitudePlate->Render( PlateShader );
			PlateShader->UnUse( );
			TextShader->Use( );
			BoosterAltitudeReadout->Render( TextShader );
			TextShader->UnUse( );

			TextShader->Use( );
			BoosterLatitudeTitle->Render( TextShader );
			TextShader->UnUse( );
			PlateShader->Use( );
			BoosterLatitudePlate->Render( PlateShader );
			PlateShader->UnUse ( );
			TextShader->Use( );
			BoosterLatitudeReadout->Render( TextShader );
			TextShader->UnUse( );

			TextShader->Use( );
			BoosterLongitudeTitle->Render( TextShader );
			TextShader->UnUse( );
			PlateShader->Use( );
			BoosterLongitudePlate->Render( PlateShader );
			PlateShader->UnUse( );
			TextShader->Use( );
			BoosterLongitudeReadout->Render( TextShader );
			TextShader->UnUse( );
		}
};