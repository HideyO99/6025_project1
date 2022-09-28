#pragma once

#ifdef BLACKBOXDLL_EXPORTS
#define TRAJECTORY_API __declspec(dllexport)
#else
#define TRAJECTORY_API __declspec(dllimport)
#endif // BLACKBOXDLL_EXPORTS


#define GForce	9.8f
#define PI		3.14159f

extern "C"
{
	TRAJECTORY_API float TimeOfFlight(float Vinit, float AngleDegree);
	TRAJECTORY_API float MaxHeight(float Vinit, float AngleDegree);
	TRAJECTORY_API float MaxDistance(float Vinit, float AngleDegree);
	TRAJECTORY_API float DegreeToRadian(float AngleDegree);
	TRAJECTORY_API float VerticalPos(float Vinit,float HorizonPos, float AngleDegree);
}
