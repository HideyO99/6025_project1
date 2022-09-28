#include <cmath>
#include <iostream>
#include "include/basicFunction.h"

int main(int argc, char** argv)
{
	int result = 0;
	result = Sum(1, 10);
	std::cout << "sum:" << result << std::endl;
	float Fresult = 0.0f;
	Fresult = CelsiusToFahrenheit(0);
	std::cout << "CtoF:" << Fresult << std::endl;
	Fresult = FahrenheitToCelsius(52);
	std::cout << "FtoC:" << Fresult << std::endl;
	bool state = false;
	state = Hysterasis(5, 3, 4, state);
	std::cout << "false " <<state<< std::endl;
	state = Hysterasis(5, 3, 6, state);
	std::cout << "high pass "<<state << std::endl;
	state = Hysterasis(5, 3, 4, state);
	std::cout << "b pass " << state << std::endl;
	state = Hysterasis(5, 3, 2, state);
	std::cout << "low pass " << state << std::endl;
	Fresult = AreaOfTriangle(10, 5);
	std::cout << "area:" << Fresult << std::endl;
	return 0;
}