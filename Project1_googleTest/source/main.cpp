#include <cmath>
#include <iostream>
#include "include/basicFunction.h"
#include <gtest/gtest.h>
#include <BlackBoxDLL/trajectory.h>

TEST(SumTests_WhiteBox, Sum_Positive)
{
	EXPECT_EQ(55, Sum(1, 10));
	EXPECT_EQ(4950, Sum(1, 99));
	EXPECT_EQ(65703, Sum(1, 362)); //test integer overflow
	EXPECT_EQ(3150, Sum(99, 126));
	EXPECT_EQ(0, Sum(99, 1));
}

TEST(SumTests_WhiteBox, Sum_Negative)
{
	EXPECT_EQ(0, Sum(-10, 10));
	EXPECT_EQ(-34, Sum(-10, 6));
	EXPECT_EQ(-5049, Sum(-100, 1));
	EXPECT_EQ(0, Sum(10, -10));
	EXPECT_EQ(-65702, Sum(-362, 1)); //test integer overflow
}

TEST(CtoFTests_WhiteBox, Convert_test)
{
	EXPECT_FLOAT_EQ(32.f, CelsiusToFahrenheit(0.f));
	EXPECT_FLOAT_EQ(212.f, CelsiusToFahrenheit(100.f));
	EXPECT_FLOAT_EQ(-4.f, CelsiusToFahrenheit(-20.f));
	EXPECT_FLOAT_EQ(1.4f, CelsiusToFahrenheit(-17.f));
	EXPECT_FLOAT_EQ(97.7f, CelsiusToFahrenheit(36.5f));
}

TEST(FtoCTests_WhiteBox, Convert_test)
{
	EXPECT_FLOAT_EQ(0.f, FahrenheitToCelsius(32.f));
	EXPECT_NEAR(-17.7778f, FahrenheitToCelsius(0.f), 0.0001f);
	EXPECT_NEAR(-28.8889f, FahrenheitToCelsius(-20.f),0.0001f);
	EXPECT_NEAR(37.7778f, FahrenheitToCelsius(100.f), 0.0001f);
	EXPECT_FLOAT_EQ(36.5f, FahrenheitToCelsius(97.7f));
}

TEST(HysteratisTests_WhiteBox, Hysteratis)
{
	EXPECT_TRUE(Hysterasis(5.f, 1.5f, 5.5f, false));
	EXPECT_TRUE(Hysterasis(5.f, 1.5f, 5.5f, true));
	EXPECT_TRUE(Hysterasis(5.f, 6.5f, 5.5f, false)); // test low threshold is greather than high threshold 
	EXPECT_TRUE(Hysterasis(5.f, 6.5f, 5.5f, true)); // test low threshold is greather than high threshold
	EXPECT_FALSE(Hysterasis(5.f, 1.5f, 0.f, false));
	EXPECT_FALSE(Hysterasis(5.f, 1.5f, 0.f, true));
	EXPECT_FALSE(Hysterasis(5.f, 1.5f, 3.5f, false));
	EXPECT_TRUE(Hysterasis(5.f, 1.5f, 3.5f, true));
	EXPECT_TRUE(Hysterasis(5.f, -5.5f, -1.5f, true));

}

TEST(AreaOfTriangleTests_WhiteBox,Triagle_Area_Cal)
{
	EXPECT_FLOAT_EQ(10.f, AreaOfTriangle(4.f, 5.f));
	EXPECT_FLOAT_EQ(10.f, AreaOfTriangle(-4.f, 5.f));
	EXPECT_FLOAT_EQ(10.f, AreaOfTriangle(4.f, -5.f));
	EXPECT_FLOAT_EQ(0.f, AreaOfTriangle(0.f, 5.f));
	EXPECT_FLOAT_EQ(0.f, AreaOfTriangle(4.f, 0.f));
	EXPECT_FLOAT_EQ(7.5f, AreaOfTriangle(3.f, 5.f));
}

TEST(TimeOfFlightTests_BlackBox, TOF)
{
	EXPECT_FLOAT_EQ(10.f, TimeOfFlight(49.f, 90.f));
	EXPECT_NEAR(7.0710f, TimeOfFlight(49.f, 45.f), 0.0001f);
	EXPECT_NEAR(0.f, TimeOfFlight(49.f, 360.f), 0.0001f);
	EXPECT_FLOAT_EQ(0.f, TimeOfFlight(49.f, 0.f));
	EXPECT_FLOAT_EQ(20.f, TimeOfFlight(98.f, 90.f));
	EXPECT_NEAR(14.1421f, TimeOfFlight(98.f, 45.f), 0.0001f);
	EXPECT_NEAR(0.f, TimeOfFlight(98.f, 360.f), 0.001f);
	EXPECT_FLOAT_EQ(0.f, TimeOfFlight(98.f, 0.f));
	EXPECT_FLOAT_EQ(0.f, TimeOfFlight(0.f, 90.f));
	EXPECT_FLOAT_EQ(0.f, TimeOfFlight(0.f, 45.f));
	EXPECT_FLOAT_EQ(0.f, TimeOfFlight(0.f, 360.f));
	EXPECT_FLOAT_EQ(0.f, TimeOfFlight(0.f, 0.f));
}

TEST(MaxHeightTests_Blackbox, MaxHeight_test)
{
	EXPECT_NEAR(122.5f, MaxHeight(49.f, 90.f), 0.0001f);
	EXPECT_NEAR(61.25f, MaxHeight(49.f, 45.f), 0.0001f);
	EXPECT_NEAR(0.f, MaxHeight(49.f, 360.f), 0.0001f);
	EXPECT_NEAR(0.f, MaxHeight(49.f, 0.f), 0.0001f);
	EXPECT_NEAR(4.9f, MaxHeight(9.8f, 90.f), 0.0001f);
	EXPECT_NEAR(2.45f, MaxHeight(9.8f, 45.f), 0.0001f);
	EXPECT_NEAR(0.f, MaxHeight(9.8f, 360.f), 0.0001f);
	EXPECT_NEAR(0.f, MaxHeight(9.8f, 0.f), 0.0001f);
	EXPECT_NEAR(0.f, MaxHeight(0.f, 90.f), 0.0001f);
	EXPECT_NEAR(0.f, MaxHeight(0.f, 45.f), 0.0001f);
	EXPECT_NEAR(0.f, MaxHeight(0.f, 360.f), 0.0001f);
	EXPECT_NEAR(0.f, MaxHeight(0.f, 0.f), 0.0001f);
}

TEST(MaxDistanceTests_BlackBox, MaxDistance_test)
{
	
	EXPECT_NEAR(0.f, MaxDistance(49.f, 90.f), 0.01f);
	EXPECT_NEAR(245.f, MaxDistance(49.f, 45.f), 0.01f);
	EXPECT_NEAR(0.f, MaxDistance(49.f, 360.f), 0.01f);
	EXPECT_NEAR(0.f, MaxDistance(49.f, 0.f), 0.01f);
	EXPECT_NEAR(0.f, MaxDistance(9.8f, 90.f), 0.01f);
	EXPECT_NEAR(9.8f, MaxDistance(9.8f, 45.f), 0.01f);
	EXPECT_NEAR(0.f, MaxDistance(9.8f, 360.f), 0.01f);
	EXPECT_NEAR(0.f, MaxDistance(9.8f, 0.f), 0.01f);
	EXPECT_NEAR(0.f, MaxDistance(0.f, 90.f), 0.01f);
	EXPECT_NEAR(0.f, MaxDistance(0.f, 45.f), 0.01f);
	EXPECT_NEAR(0.f, MaxDistance(0.f, 360.f), 0.01f);
	EXPECT_NEAR(0.f, MaxDistance(0.f, 0.f), 0.01f);
}

TEST(VerticalPositionTests_BlackBox, VerticalPosition_test)
{
	EXPECT_NEAR(0.f, VerticalPos(49.f, 0.f, 90.f), 0.01f);
	EXPECT_NEAR(0.f, VerticalPos(49.f, 0.f, 45.f), 0.01f);
	EXPECT_NEAR(0.f, VerticalPos(49.f, 0.f, 360.f), 0.01f);
	EXPECT_NEAR(0.f, VerticalPos(49.f, 0.f, 0.f), 0.01f);
	EXPECT_NEAR(0.f, VerticalPos(49.f, 10.f, 90.f), 0.01f);
	EXPECT_NEAR(9.5918f, VerticalPos(49.f, 10.f, 45.f), 0.01f);
	EXPECT_NEAR(-0.204f, VerticalPos(49.f, 10.f, 360.f), 0.01f);
	EXPECT_NEAR(-0.204f, VerticalPos(49.f, 10.f, 0.f), 0.01f);
	EXPECT_NEAR(0.f, VerticalPos(0.f, 10.f, 90.f), 0.01f);
	EXPECT_NEAR(0.f, VerticalPos(0.f, 10.f, 45.f), 0.01f);	//print error
	EXPECT_NEAR(0.f, VerticalPos(0.f, 10.f, 360.f), 0.01f);	//print error
	EXPECT_NEAR(0.f, VerticalPos(0.f, 10.f, 0.f), 0.01f);	//print error
}


TEST(DegreeToRadianTests_BlackBox, Convert_test)
{
	EXPECT_FLOAT_EQ(0.f, DegreeToRadian(0.f));
	EXPECT_NEAR(6.2831f, DegreeToRadian(360.f), 0.0001f);
	EXPECT_NEAR(1.5708f, DegreeToRadian(90.f), 0.0001f);
	EXPECT_NEAR(0.7853f, DegreeToRadian(45.f), 0.0001f);
	EXPECT_NEAR(4.7123f, DegreeToRadian(270.f), 0.0001f);
	EXPECT_NEAR(0.6435f, DegreeToRadian(36.87f), 0.0001f);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();
	
	return result;
}