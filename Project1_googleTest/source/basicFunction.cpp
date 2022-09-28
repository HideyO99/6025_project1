#include "include/basicFunction.h"

int Sum(int begin, int end)
{
	int result = 0;
	for (int i = begin; i <= end; i++)
	{
		result += i;
	}
	return result;
}

float CelsiusToFahrenheit(float Tc)
{
	return (Tc*9/5)+32;
}

float FahrenheitToCelsius(float Tf)
{
	return (Tf-32)*5/9;
}

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

float AreaOfTriangle(float Base, float Height)
{
	return Base*Height/2;
}
