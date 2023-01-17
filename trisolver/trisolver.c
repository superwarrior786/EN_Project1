/*
	Name: Elkhai Nagawkar
	Date: January 15, 2023
	Purpose: This program will solve all sides and angles of a triangle if possible.
*/

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/*void getAllAngles(char triangleType, float sideA, float sideB, float sideC)
{
	float perimeter;
	float area;
	float tirangleheight;
	float angleA;
	float angleAResult;
	float angleBResult;
	float angleC;
	float angleCResult;
	const float MAKE_NON_NEGETIVE = -1;
	const float TRIANGLE_DEGREES = 180;


	perimeter = sideA + sideB + sideC;
	area = (sideA + sideB + sideC) / 2;
	area = area * ((area - sideA) * (area - sideB) * (area - sideC)); //get all this code and put in different function and add validation to check for longest side
	area = sqrt(area);
	tirangleheight = (2.0 * area) / sideC;
	area = (sideC * tirangleheight) / 2;

	angleC = pow(sideC, 2) - (pow(sideA, 2) + pow(sideB, 2));
	angleC = angleC / ((2 * (sideA * sideB)) * MAKE_NON_NEGETIVE);
	angleC = acos(angleC) * (180.0 / M_PI);
	angleCResult = angleC;

	angleA = pow(sideA, 2) - (pow(sideB, 2) + pow(sideC, 2));	
	angleA = angleA / ((2 * (sideB * sideC)) * MAKE_NON_NEGETIVE);
	angleA = acos(angleA) * (180.0 / M_PI);
	angleAResult = angleA;

	angleBResult = TRIANGLE_DEGREES - angleCResult - angleAResult;
	
	printf("%-10s%5.3f%15s%10.3f\n", "a = ", sideA, "Alpha = ", angleAResult);
	printf("%-10s%5.3f%15s%10.3f\n", "b = ", sideB, "Beta = ", angleBResult);
	printf("%-10s%5.3f%15s%10.3f\n", "c = ", sideC, "Gamma = ", angleCResult);
	
}*/




int main()
{
	char format[100 + 1] = { '\0' };
	float AngleOrSideA;
	float AngleOrSideB;
	float AngleOrSideC;
	int read = 0;

	while (scanf_s("%s", format, 100) != 0)
	{
		if(strcmp(format, "SSS") == 0)
		{
			break;
		}
		else
		{
			printf("Please enter good\n");
		}
	}
	


	return 0;
}