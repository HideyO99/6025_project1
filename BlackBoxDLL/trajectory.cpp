#include "include/trajectory.h"
#include <cmath>
#include "pch.h"
#include <iostream>

//////////////////////////////////////////////////////////
//Time of Flight										//
// -----------------------------------------------------//
// Calculate time when particle start trajectory from	//
// same ground level as formular						//
// Vf = Vi + A*T --> T = 2*Vi/A							//
// -----------------------------------------------------//
// Input :												//
// Vinit = Initial velocity								//
// AngleDegree = Angle in degree						//
//														//
// Output:												//
// result = Time of flight								//
//////////////////////////////////////////////////////////
float TimeOfFlight(float Vinit, float AngleDegree)
{
	float result = 0.0f;
	float AngleRadian = DegreeToRadian(AngleDegree);

	result = (2.0f * Vinit * sin(AngleRadian)) / GForce;

	return result;
}

//////////////////////////////////////////////////////////
//Max Height											//
// -----------------------------------------------------//
// Calculate max vertical distance as formular			//
// Vf^2 = Vi^2 + 2A*S --> S = Vi^2/2A					//
// -----------------------------------------------------//
// Input :												//
// Vinit = Initial velocity								//
// AngleDegree = Angle in degree						//
//														//
// Output:												//
// Height = Max Height									//
//////////////////////////////////////////////////////////
float MaxHeight(float Vinit, float AngleDegree)
{
	float AngleRadian = DegreeToRadian(AngleDegree);
	float Height = 0;
	float Vy = Vinit * sin(AngleRadian);

	Height = (Vy * Vy) / (2.0f * GForce);

	return Height;
}

//////////////////////////////////////////////////////////
//Max Distance											//
// -----------------------------------------------------//
// Calculate max horizontal distance as formular		//
// S=Vi*T												//
// -----------------------------------------------------//
// Input :												//
// Vinit = Initial velocity								//
// AngleDegree = Angle in degree						//
//														//
// Output:												//
// Distance												//
//////////////////////////////////////////////////////////
float MaxDistance(float Vinit, float AngleDegree)
{
	float AngleRadian = DegreeToRadian(AngleDegree);
	float Vx = Vinit * cos(AngleRadian);
	float Distance = Vx * TimeOfFlight(Vinit, AngleDegree);
	
	return Distance;
}

//////////////////////////////////////////////////////////
//Degree to Radian										//
// -----------------------------------------------------//
// Convert angle in degree to angle in radian			//
// Rad = Deg * Pi /180									//
// -----------------------------------------------------//
// Input :												//
// AngleDegree = Angle in degree						//
//														//
// Output:												//
// Angle in radian										//
//////////////////////////////////////////////////////////
float DegreeToRadian(float AngleDegree)
{
	return AngleDegree * PI / 180.0f;
}

//////////////////////////////////////////////////////////////////////////
//Vertical Position														//
// ---------------------------------------------------------------------//
// Calculate vertical position of trajectory while given				//
// horizontal distance, angle and initial velocity						//
// Reference:															//		
// https://www.softschools.com/formulas/physics/trajectory_formula/162/ //
// ---------------------------------------------------------------------//
// Input :																//
// Vinit = Initial velocity												//
// HorizonPos = Horizontal Position										//
// AngleDegree = Angle in degree										//
//																		//
// Output:																//
// Angle in radian														//
//////////////////////////////////////////////////////////////////////////
float VerticalPos(float Vinit, float HorizonPos, float AngleDegree)
{
	float AngleRadian = DegreeToRadian(AngleDegree);
	float CosValue = cos(AngleRadian);
	float VPos = 0;

	if (Vinit != 0 || CosValue != 0)
	{
		VPos = HorizonPos * tan(AngleRadian) - ((GForce * HorizonPos * HorizonPos) / (2 * Vinit * Vinit * CosValue * CosValue));
	}
	else 
	{
		std::cout << "error"<<std::endl;
	}
		
	
	
	return VPos;
}
