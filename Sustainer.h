#pragma once

#include <glm.hpp>

#include "Gauge.h"
#include "Mesh.h"


// Class made for sustainer management. Do not modify unless rocket team request now GUI object for sustainer stage.
class Sustainer
{
	private:

		Mesh *SustainerTitle;
		Mesh* RedSustainerTitle;
		Mesh *SustainerPlate;
		bool RedAlert;

		Mesh *SustainerSpeedTitle;
		Mesh* SustainerSpeedUnit;
		Mesh* RedSustainerSpeedTitle;
		Mesh* RedSustainerSpeedUnit;
		Gauge *SustainerSpeed;
		Mesh *SustainerSpeedPlate;
		Mesh **SpeedNumbers;
		float Speed;
		Readout *SustainerSpeedReadout;
		bool SpeedRedAlert;

		Mesh *SustainerAccelerationTitle;
		Mesh *SustainerAccelerationUnit;
		Mesh* RedSustainerAccelerationTitle;
		Mesh* RedSustainerAccelerationUnit;
		Gauge *SustainerAcceleration;
		Mesh *SustainerAccelerationPlate;
		float Acceleration;
		Readout* SustainerAccelerationReadout;
		bool AccelerationRedAlert;

		Mesh *SustainerAltitudeTitle;
		Mesh *SustainerAltitudeUnit;
		Mesh *SustainerAltitudePlate;
		float Altitude;
		Readout* SustainerAltitudeReadout;

		Mesh *SustainerLatitudeTitle;
		Mesh *SustainerLatitudePlate;
		float Latitude;
		Readout* SustainerLatitudeReadout;

		Mesh *SustainerLongitudeTitle;
		Mesh *SustainerLongitudePlate;
		float Longitude;
		Readout* SustainerLongitudeReadout;

		Mesh* SustainerMachTitle;
		Mesh* SustainerMachPlate;
		float Mach;
		Readout* SustainerMachReadout;

		Mesh* SustainerMaxSpeedTitle;
		Mesh* SustainerMaxSpeedPlate;
		float MaxSpeed;
		Readout* SustainerMaxSpeedReadout;

		Mesh* SustainerApogeeTitle;
		Mesh* SustainerApogeePlate;
		Readout* SustainerApogeeReadout;
		float Apogee;

		Mesh* SustainerAngleTitle;
		Mesh* SustainerAnglePlate;
		Mesh* AngleLineHorizontal;
		Mesh* AngleLineVertical;
		Mesh* AngleLineVariable;
		Readout* SustainerAngleReadout;
		float Angle;

	public:

		// All objects are constructed with parameters for object file path, position vector, rotation vector, scale vector, base rgb color vector in case object does not have texture.
		// Do not modify this implementation unless told to. Initial values provided for testing purposes.
		Sustainer( )
		{
			this->SustainerTitle = new Mesh("Sustainer.obj", glm::vec3(1443.5f, 840.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(50.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			this->RedSustainerTitle = new Mesh("Sustainer.obj", glm::vec3(1443.5f, 840.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(50.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			this->SustainerPlate = new Mesh("Readout.obj", glm::vec3(1443.5f, 858.0f, -40.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(35.0f, 35.0f, 35.0f));
			this->RedAlert = false;

			this->SustainerSpeedTitle = new Mesh("Speed.obj", glm::vec3(1425.0f, 490.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			this->SustainerSpeedUnit = new Mesh("FTS.obj", glm::vec3(1470.0f, 493.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(12.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			this->RedSustainerSpeedTitle = new Mesh("Speed.obj", glm::vec3(1425.0f, 490.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(20.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			this->RedSustainerSpeedUnit = new Mesh("FTS.obj", glm::vec3(1470.0f, 493.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(12.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			this->SustainerSpeed = new Gauge(glm::vec3(1440, 660, -20.0f), 0, 1000);
			this->SustainerSpeedPlate = new Mesh("Readout.obj", glm::vec3(1442.5f, 510.0f, -40.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(35.0f, 35.0f, 35.0f));
			this->Speed = 253.4224;
			this->SustainerSpeedReadout = new Readout(this->Speed, 1442.5f, 510.0f, -40.0f);
			this->SpeedRedAlert = false;

			this->SustainerAccelerationTitle = new Mesh("Acceleration.obj", glm::vec3(1424.0f, 140.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			this->SustainerAccelerationUnit = new Mesh("FTS2.obj", glm::vec3(1502.0f, 143.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(12.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			this->RedSustainerAccelerationTitle = new Mesh("Acceleration.obj", glm::vec3(1424.0f, 140.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(20.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			this->RedSustainerAccelerationUnit = new Mesh("FTS2.obj", glm::vec3(1502.0f, 143.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(12.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			this->SustainerAcceleration = new Gauge(glm::vec3(1440, 310, -20.0f), 0, 900);
			this->SustainerAccelerationPlate = new Mesh("Readout.obj", glm::vec3(1442.5f, 160.0f, -40.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(35.0f, 35.0f, 35.0f));
			this->Acceleration = 257.45;
			this->SustainerAccelerationReadout = new Readout(this->Speed, 1442.5f, 160.0f, -40.0f);
			this->AccelerationRedAlert = false;

			this->SustainerAltitudeTitle = new Mesh("Altitude.obj", glm::vec3(1435.0f, 40.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			this->SustainerAltitudeUnit = new Mesh("FT.obj", glm::vec3(1485, 43.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(12.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			this->SustainerAltitudePlate = new Mesh("Readout.obj", glm::vec3(1442.5f, 60.0f, -40.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(35.0f, 35.0f, 35.0f));
			this->Altitude = 3425;
			this->SustainerAltitudeReadout = new Readout(this->Speed, 1442.5f, 60.0f, -40.0f);

			this->SustainerLatitudeTitle = new Mesh("Latitude.obj", glm::vec3(1142.0f, 140.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			this->SustainerLatitudePlate = new Mesh("Readout.obj", glm::vec3(1142.5f, 160.0f, -40.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(35.0f, 35.0f, 35.0f));
			this->Latitude = 764.46;
			this->SustainerLatitudeReadout = new Readout(this->Speed, 1142.5f, 160.0f, -40.0f);

			this->SustainerLongitudeTitle = new Mesh("Longitude.obj", glm::vec3(1142.0f, 40.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			this->SustainerLongitudePlate = new Mesh("Readout.obj", glm::vec3(1142.5f, 60.0f, -40.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(35.0f, 35.0f, 35.0f));
			this->Longitude = 4661.67;
			this->SustainerLongitudeReadout = new Readout(this->Speed, 1142.5f, 60.0f, -40.0f);

			this->SustainerMachTitle = new Mesh("Mach.obj", glm::vec3(475.0f, 819.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			this->SustainerMachPlate = new Mesh("Readout.obj", glm::vec3(475.0f, 843.0f, -40.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(35.0f, 35.0f, 35.0f));
			this->Mach = 0.0f;
			this->SustainerMachReadout = new Readout(this->Mach, 475.0f, 843.0f, -40.0);

			this->SustainerMaxSpeedTitle = new Mesh("MaxSpeed.obj", glm::vec3(1125.0f, 819.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			this->SustainerMaxSpeedPlate = new Mesh("Readout.obj", glm::vec3(1125.0f, 843.0f, -40.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(35.0f, 35.0f, 35.0f));
			this->MaxSpeed = 0.0f;
			this->SustainerMaxSpeedReadout = new Readout(this->Mach, 1125.0f, 843.0f, -40.0);

			this->SustainerApogeeTitle = new Mesh("Apogee.obj", glm::vec3(800, 819.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			this->SustainerApogeePlate = new Mesh("Readout.obj", glm::vec3(800.0f, 843.0f, -40.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(35.0f, 35.0f, 35.0f));
			Apogee = 0.0f;
			this->SustainerApogeeReadout = new Readout(this->Apogee, 800.0f, 843.0f, -40.0);

			this->SustainerAngleTitle = new Mesh("Angle.obj", glm::vec3(860.0f, 50.0f, -10.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(20.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			this->SustainerAnglePlate = new Mesh("Readout.obj", glm::vec3(800.0f, 105.0f, -40.0f), glm::vec3(90.0f, 0.0f, 0.0f), glm::vec3(50.0f, 50.0f, 90.0f));
			this->AngleLineHorizontal = new Mesh( "AngleLine.obj", glm::vec3( 800.0f, 80.0f, -10.0f ), glm::vec3( 90.0f, 0.0f, 0.0f ), glm::vec3( 75.0f, 75.0f, 55.0f ), glm::vec3(1.0f, 0.3f, 0.3f));
			this->AngleLineVertical = new Mesh( "AngleLine.obj", glm::vec3( 800.0f, 125.0f, -10.0f ), glm::vec3( 90.0f, 90.0f, 0.0f ), glm::vec3( 22.0f, 22.0f, 55.0f ), glm::vec3(1.0f, 0.3f, 0.3f));
			this->AngleLineVariable = new Mesh( "AngleLineVariable.obj", glm::vec3( 800.0f, 80.0f, -10.0f ), glm::vec3( 90.0f, 90.0f, 0.0f ), glm::vec3( 22.0f, 22.0f, 22.0f ), glm::vec3(1.0f, 0.3f, 0.3f));
			Angle = 0.0f;
			this->SustainerAngleReadout = new Readout(this->Angle, 760.0f, 45.0f, -40.0);

			this->Update( );
		}

		~Sustainer( )
		{
			delete this->SustainerTitle;
			delete this->SustainerSpeed;
		}

		void Update( )
		{
			this->SustainerSpeed->Update(this->Speed);
			this->Speed += 0.1;
			this->SustainerSpeedReadout->Update(this->Speed);
			SpeedRedAlert = this->SustainerSpeed->GetAlert();

			this->SustainerAcceleration->Update(this->Acceleration);
			this->Acceleration += 0.03;
			this->SustainerAccelerationReadout->Update(this->Acceleration);
			AccelerationRedAlert = this->SustainerAcceleration->GetAlert( );

			this->Altitude += 100;
			this->SustainerAltitudeReadout->Update(this->Altitude);

			this->Latitude += 0.3;
			this->SustainerLatitudeReadout->Update(this->Latitude);

			this->Longitude += 0.1;
			this->SustainerLongitudeReadout->Update(this->Longitude);

			this->Mach += 0.01;
			this->SustainerMachReadout->Update(this->Mach);

			if (SpeedRedAlert || AccelerationRedAlert)
			{
				this->RedAlert = true;
			}

			if ( this->Speed > this->MaxSpeed )
			{
				this->MaxSpeed = this->Speed;
				this->SustainerMaxSpeedReadout->Update(this->MaxSpeed);
			}

			if (this->Altitude > this->Apogee)
			{
				this->Apogee = this->Altitude;
				this->SustainerApogeeReadout->Update(this->Apogee);
			}

			this->Angle += 0.001;
			this->SustainerAngleReadout->Update(this->Angle);
			this->AngleLineVariable->Rotate(glm::vec3(0.0f, 0.001, 0.0f));
		}

		void Render( Shader *TextShader, Shader* RedTextShader, Shader *PlateShader, Shader *GaugeShader, Shader *DialShader )
		{
			if ( RedAlert )
			{
				TextShader->Use();
				RedSustainerTitle->Render(TextShader);
				TextShader->UnUse();
				PlateShader->Use();
				SustainerPlate->Render(PlateShader);
				PlateShader->UnUse();
			}
			else
			{
				TextShader->Use();
				SustainerTitle->Render(TextShader);
				TextShader->UnUse();
				PlateShader->Use();
				SustainerPlate->Render(PlateShader);
				PlateShader->UnUse();
			}

			if (SpeedRedAlert)
			{
				TextShader->Use( );
				RedSustainerSpeedTitle->Render( TextShader );
				TextShader->UnUse( );
				TextShader->Use( );
				RedSustainerSpeedUnit->Render( TextShader );
				TextShader->UnUse( );
				SustainerSpeed->Render( TextShader, GaugeShader, DialShader );
				PlateShader->Use( );
				SustainerSpeedPlate->Render( PlateShader );
				PlateShader->UnUse( );
				TextShader->Use( );
				SustainerSpeedReadout->Render( TextShader );
				TextShader->UnUse( );
			}
			else
			{
				TextShader->Use();
				SustainerSpeedTitle->Render(TextShader);
				TextShader->UnUse();
				TextShader->Use();
				SustainerSpeedUnit->Render(TextShader);
				TextShader->UnUse();
				SustainerSpeed->Render(TextShader, GaugeShader, DialShader);
				PlateShader->Use();
				SustainerSpeedPlate->Render(PlateShader);
				PlateShader->UnUse();
				TextShader->Use();
				SustainerSpeedReadout->Render(TextShader);
				TextShader->UnUse();
			}


			
			if (AccelerationRedAlert)
			{
				TextShader->Use();
				RedSustainerAccelerationTitle->Render(TextShader);
				TextShader->UnUse();
				TextShader->Use();
				RedSustainerAccelerationUnit->Render(TextShader);
				TextShader->UnUse();
				SustainerAcceleration->Render(TextShader, GaugeShader, DialShader);
				PlateShader->Use();
				SustainerAccelerationPlate->Render(PlateShader);
				PlateShader->UnUse();
				TextShader->Use();
				SustainerAccelerationReadout->Render(TextShader);
				TextShader->UnUse();
			}
			else
			{
				TextShader->Use();
				SustainerAccelerationTitle->Render(TextShader);
				TextShader->UnUse();
				TextShader->Use();
				SustainerAccelerationUnit->Render(TextShader);
				TextShader->UnUse();
				SustainerAcceleration->Render(TextShader, GaugeShader, DialShader);
				PlateShader->Use();
				SustainerAccelerationPlate->Render(PlateShader);
				PlateShader->UnUse();
				TextShader->Use();
				SustainerAccelerationReadout->Render(TextShader);
				TextShader->UnUse();
			}

			TextShader->Use( );
			SustainerAltitudeTitle->Render( TextShader );
			TextShader->UnUse( );
			TextShader->Use( );
			SustainerAltitudeUnit->Render( TextShader );
			TextShader->UnUse( );
			PlateShader->Use( );
			SustainerAltitudePlate->Render( PlateShader );
			PlateShader->UnUse( );
			TextShader->Use( );
			SustainerAltitudeReadout->Render( TextShader );
			TextShader->UnUse( );

			TextShader->Use( );
			SustainerLatitudeTitle->Render( TextShader );
			TextShader->UnUse( );
			PlateShader->Use( );
			SustainerLatitudePlate->Render( PlateShader );
			PlateShader->UnUse( );
			TextShader->Use( );
			SustainerLatitudeReadout->Render( TextShader );
			TextShader->UnUse( );

			TextShader->Use( );
			SustainerLongitudeTitle->Render( TextShader );
			TextShader->UnUse( );
			PlateShader->Use( );
			SustainerLongitudePlate->Render( PlateShader );
			PlateShader->UnUse( );
			TextShader->Use( );
			SustainerLongitudeReadout->Render( TextShader );
			TextShader->UnUse( );

			TextShader->Use();
			SustainerMachTitle->Render(TextShader);
			TextShader->UnUse();
			PlateShader->Use();
			SustainerMachPlate->Render(PlateShader);
			PlateShader->UnUse();
			TextShader->Use();
			SustainerMachReadout->Render(TextShader);
			TextShader->UnUse();

			TextShader->Use();
			SustainerMaxSpeedTitle->Render(TextShader);
			TextShader->UnUse();
			PlateShader->Use();
			SustainerMaxSpeedPlate->Render(PlateShader);
			PlateShader->UnUse();
			TextShader->Use();
			SustainerMaxSpeedReadout->Render(TextShader);
			TextShader->UnUse();

			TextShader->Use();
			SustainerApogeeTitle->Render(TextShader);
			TextShader->UnUse();
			TextShader->Use();
			SustainerApogeePlate->Render(PlateShader);
			TextShader->UnUse();
			TextShader->Use();
			SustainerApogeeReadout->Render(TextShader);
			TextShader->UnUse();

			TextShader->Use();
			SustainerAngleTitle->Render(TextShader);
			TextShader->UnUse();
			TextShader->Use();
			SustainerAnglePlate->Render(PlateShader);
			TextShader->UnUse();
			TextShader->Use();
			AngleLineHorizontal->Render(TextShader);
			TextShader->UnUse();
			TextShader->Use();
			AngleLineVertical->Render(TextShader);
			TextShader->UnUse();
			TextShader->Use();
			AngleLineVariable->Render(TextShader);
			TextShader->UnUse();
			TextShader->Use();
			SustainerAngleReadout->Render(TextShader);
			TextShader->UnUse();
		}
};