/*
	Name: Elkhai Nagawkar
	Date: January 15, 2023
	Purpose: This program will solve all sides and angles of a triangle if possible.
*/

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

void getAllAngles(char triangleType, float sideA, float sideB, float sideC)
{
	float angleA;
	float angleAResult;
	float angleBResult;
	float angleC;
	float angleCResult;
	const float MAKENEGETIVE = -1;
	const float TRIANGLE_DEGREES = 180;

	angleC = pow(sideC, 2) - (pow(sideA, 2) + pow(sideB, 2));
	angleC = angleC / ((2 * (sideA * sideB)) * MAKENEGETIVE);
	angleC = acos(angleC) * (180.0 / M_PI);
	angleCResult = angleC;

	angleA = pow(sideA, 2) - (pow(sideB, 2) + pow(sideC, 2));	
	angleA = angleA / ((2 * (sideB * sideC)) * MAKENEGETIVE);
	angleA = acos(angleA) * (180.0 / M_PI);
	angleAResult = angleA;

	angleBResult = TRIANGLE_DEGREES - angleCResult - angleAResult;
	
	printf("%-10s%5.3f%15s%10.3f\n", "a = ", sideA, "Alpha = ", angleAResult);
	printf("%-10s%5.3f%15s%10.3f\n", "b = ", sideB, "Beta = ", angleBResult);
	printf("%-10s%5.3f%15s%10.3f\n", "c = ", sideC, "Gamma = ", angleCResult);
}




int main()
{
	char format[100 + 1] = { '\0' };
	float AngleOrSideA;
	float AngleOrSideB;
	float AngleOrSideC;
	int read = 0;

	do
	{
		

		if (scanf_s("%s", format, 100) == 1)
		{
			read++;
		}

		if (scanf_s("%f", &AngleOrSideA) == 1)
		{
			read++;
		}

		if (scanf_s("%f", &AngleOrSideB) == 1)
		{
			read++;
		}

		if (scanf_s("%f", &AngleOrSideC) == 1)
		{
			read++;
		}


	} while (read !=4);

	getAllAngles(format, AngleOrSideA, AngleOrSideB, AngleOrSideC);


	return 0;
}