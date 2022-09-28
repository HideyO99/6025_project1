#include "include/basicFunction.h"

//////////////////////////////////////////////////////////
//Summation												//
// -----------------------------------------------------//
// Calculate summation from begin value to end value	//
// -----------------------------------------------------//
// Input :												//
// begin = start value									//
// end = end value										//
//														//
// Output:												//
// Sum value											//
//////////////////////////////////////////////////////////
int Sum(int begin, int end)
{
	int result = 0;
	for (int i = begin; i <= end; i++)
	{
		result += i;
	}
	return result;
}

//////////////////////////////////////////////////////////
//Celsius to Fahrenheit									//
// -----------------------------------------------------//
// Convert Temperature in Degree Celsius to Fahranheit 	//
// -----------------------------------------------------//
// Input :												//
// Tc = Temperature in Degree Celsius					//
//														//
// Output:												//
// Temperature in Fahrenheit							//
//////////////////////////////////////////////////////////
float CelsiusToFahrenheit(float Tc)
{
	return (Tc*9/5)+32;
}

//////////////////////////////////////////////////////////
//Fahrenheit to Celsius									//
// -----------------------------------------------------//
// Convert Temperature in Fahranheit to Degree Celsius	//
// -----------------------------------------------------//
// Input :												//
// Tf = Temperature in Fahrenheit						//
//														//
// Output:												//
// Temperature in Degree Celsius						//
//////////////////////////////////////////////////////////
float FahrenheitToCelsius(float Tf)
{
	return (Tf-32)*5/9;
}

//////////////////////////////////////////////////////////
//Hysterasis											//
// -----------------------------------------------------//
// Toggle state to true if input is greather than high	//
// threshold, and toggle to false if input lower than	//
// threshold, but remain the current state if input in	//
// between high and low threshold						//
// -----------------------------------------------------//
// Input :												//
// HThreshold = high threshold							//
// LThreshold = low threshold							//
// Input = input value									//
// CurState = current state								//
//														//
// Output:												//
// State												//
//////////////////////////////////////////////////////////
bool Hysterasis(float HThreshold, float LThreshold, float Input, bool CurState)
{
	bool result = CurState;
	if (Input > HThreshold)
	{
		result = true;
	}
	else if (Input < LThreshold)
	{
		result = false;
	}
	else
	{
		result = CurState;
	}

	return result;
}

//////////////////////////////////////////////////////////
//Area of Triangle										//
// -----------------------------------------------------//
// Calculate area of triangle							//
// -----------------------------------------------------//
// Input :												//
// Base = basis length									//
// Height = height length								//
//														//
// Output:												//
// Area of triangle										//
//////////////////////////////////////////////////////////
float AreaOfTriangle(float Base, float Height)
{
	return abs(Base*Height/2);
}
