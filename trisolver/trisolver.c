/*
	Name: Elkhai Nagawkar
	Date: January 15, 2023
	Purpose: This program will solve all sides and angles of a triangle if possible.
*/

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

float getArea(float sideA, float sideB, float sideC)
{
	float area;
	float tirangleheight;
	float longestSide = findLongestSide(sideA, sideB, sideC);

	area = (sideA + sideB + sideC) / 2.0;
	area = area * ((area - sideA) * (area - sideB) * (area - sideC));
	area = sqrt(area);
	tirangleheight = (2.0 * area) / longestSide;
	area = (longestSide * tirangleheight) / 2.0;


	return area;
}

float findLongestSide(float sideA, float sideB, float sideC)
{

	if (sideA > sideB && sideA > sideC)
	{
		return sideA;
	}
	else if (sideB > sideA && sideB > sideC)
	{
		return sideB;
	}
	else if (sideC > sideA && sideC > sideB)
	{
		return sideC;
	}
	else
	{
		return sideC;

	}
}

int getImpossibleTriangle(float sideA, float sideB, float sideC)
{
	if (sideA > sideB && sideA > sideC)
	{
		if ((sideB + sideC) < sideA)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
	}
	else if (sideB > sideA && sideB > sideC)
	{
		if ((sideA + sideC) < sideB)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (sideC > sideA && sideC > sideB)
	{
		if ((sideA + sideB) < sideC)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int getTriangleType(float sideA, float sideB, float sideC)
{
	if (sideA == sideB && sideA == sideC)
	{
		return 1;
	}
	else if (sideA == sideB && sideA != sideC || sideA != sideB && sideA == sideC || sideB == sideC && sideB != sideA)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

int getTriangleAngleType(float angleA, float angleB, float angleC)
{
	if (angleA == 90.0 || angleB == 90.0 || angleC == 90.0)
	{
		return 1;
	}
	else if (angleA < 90.0 && angleB < 90.0 && angleC < 90.0)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

void getSSS(float sideA, float sideB, float sideC)
{
	float perimeter;
	float angleA;
	float angleAResult;
	float angleBResult;
	float angleC;
	float angleCResult;
	const float MAKE_NON_NEGETIVE = -1;
	const float TRIANGLE_DEGREES = 180.0;


	perimeter = sideA + sideB + sideC;
	float area = getArea(sideA, sideB, sideC);
	
	

	angleC = pow(sideC, 2) - (pow(sideA, 2) + pow(sideB, 2));
	angleC = angleC / ((2 * (sideA * sideB)) * MAKE_NON_NEGETIVE);
	angleC = acos(angleC) * (180.0 / M_PI);
	angleCResult = angleC;

	angleA = pow(sideA, 2) - (pow(sideB, 2) + pow(sideC, 2));	
	angleA = angleA / ((2 * (sideB * sideC)) * MAKE_NON_NEGETIVE);
	angleA = acos(angleA) * (180.0 / M_PI);
	angleAResult = angleA;

	angleBResult = TRIANGLE_DEGREES - angleCResult - angleAResult;
	
	int checkForImpposibleTrianle = getImpossibleTriangle(sideA, sideB, sideC);
	int triangleType = getTriangleType(sideA, sideB, sideC);
	int angleType = getTriangleAngleType(angleAResult, angleBResult, angleCResult);

	if (checkForImpposibleTrianle == 1)
	{
		printf("Impossible Triangle\n");
	}
	else
	{
		printf("%-5s %10.3f %15s %10.3f\n", "a = ", sideA, "Alpha =", angleAResult);
		printf("%-5s %10.3f %15s %10.3f\n", "b = ", sideB, "Beta  =", angleBResult);
		printf("%-5s %10.3f %15s %10.3f\n", "c = ", sideC, "Gamma =", angleCResult);
		printf("%-10s %-10s %-5.3f\n", "Perimeter", "=", perimeter);
		printf("%-10s %-10s %-5.3f\n", "Area", "=", area);
		if (triangleType == 1)
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Equilateral, ");
		}
		else if (triangleType == 2)
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Isosceles, ");
		}
		else
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Scalene, ");
		}

		if (angleType == 1)
		{
			printf("Right\n");
		}
		else if (angleType == 2)
		{
			printf("Acute\n");
		}
		else
		{
			printf("Obtuse\n");
		}
	}
}

void getSAS(float sideA, float angleC, float sideB)
{
	float perimeter;
	float angleA;
	float angleAResult;
	float angleBResult;
	float sideC;
	float sideCResult;
	float temp;
	const float TRIANGLE_DEGREES = 180.0;

	sideC = pow(sideA, 2) + pow(sideB, 2);
	temp = angleC * (M_PI / 180.0);
	temp = cos(temp);
	sideC = sideC - ((2 * (sideA * sideB)) * temp);
	sideC = sqrt(sideC);
	sideCResult = sideC;
	
	temp = angleC * (M_PI / 180);
	angleA = sin(temp) * sideA;
	angleA = angleA / sideCResult;
	angleA = asin(angleA) * (180 / M_PI);
	angleAResult = angleA;

	angleBResult = TRIANGLE_DEGREES - angleC - angleAResult;
	perimeter = sideA + sideB + sideCResult;
	float area = getArea(sideA, sideB, sideCResult);

	int checkForImpposibleTrianle = getImpossibleTriangle(sideA, sideB, sideCResult);
	int triangleType = getTriangleType(sideA, sideB, sideCResult);
	int angleType = getTriangleAngleType(angleAResult, angleBResult, angleC);

	if (checkForImpposibleTrianle == 1)
	{
		printf("Impossible Triangle\n");
	}
	else
	{
		printf("%-5s %10.3f %15s %10.3f\n", "a = ", sideA, "Alpha =", angleAResult);
		printf("%-5s %10.3f %15s %10.3f\n", "b = ", sideB, "Beta  =", angleBResult);
		printf("%-5s %10.3f %15s %10.3f\n", "c = ", sideC, "Gamma =", angleC);
		printf("%-10s %-10s %-10.3f\n", "Perimeter", "=", perimeter);
		printf("%-10s %-10s %-10.3f\n", "Area", "=", area);
		if (triangleType == 1)
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Equilateral, ");
		}
		else if (triangleType == 2)
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Isosceles, ");
		}
		else
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Scalene, ");
		}

		if (angleType == 1)
		{
			printf("Right\n");
		}
		else if (angleType == 2)
		{
			printf("Acute\n");
		}
		else
		{
			printf("Obtuse\n");
		}
	}
}

void getASA(float angleA, float sideC, float angleB)
{
	float perimeter;
	float sideA;
	float sideAResult;
	float angleC;
	float angleCResult;
	float sideB;
	float sideBResult;
	float temp;
	const float TRIANGLE_DEGREES = 180.0;

	angleC = TRIANGLE_DEGREES - angleA - angleB;
	angleCResult = angleC;

	temp = angleA * (M_PI / 180.0);
	sideA = sin(temp) * sideC;
	temp = angleCResult * (M_PI / 180.0);
	sideA = sideA / sin(temp);
	sideAResult = sideA;

	temp = angleB * (M_PI / 180.0);
	sideB = sin(temp) * sideC;
	temp = angleCResult * (M_PI / 180.0);
	sideB = sideB / sin(temp);
	sideBResult = sideB;

	perimeter = sideC + sideBResult + sideAResult;
	float area = getArea(sideAResult, sideBResult, sideC);
	int checkForImpposibleTrianle = getImpossibleTriangle(sideAResult, sideBResult, sideC);
	int triangleType = getTriangleType(sideAResult, sideBResult, sideC);
	int angleType = getTriangleAngleType(angleA, angleB, angleCResult);

	if (checkForImpposibleTrianle == 1)
	{
		printf("Impossible Triangle\n");
	}
	else
	{
		printf("%-5s %10.3f %15s %10.3f\n", "a = ", sideA, "Alpha =", angleA);
		printf("%-5s %10.3f %15s %10.3f\n", "b = ", sideBResult, "Beta  =", angleB);
		printf("%-5s %10.3f %15s %10.3f\n", "c = ", sideC, "Gamma =", angleC);
		printf("%-10s %-10s %-10.3f\n", "Perimeter", "=", perimeter);
		printf("%-10s %-10s %-10.3f\n", "Area", "=", area);
		if (triangleType == 1)
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Equilateral, ");
		}
		else if (triangleType == 2)
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Isosceles, ");
		}
		else
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Scalene, ");
		}

		if (angleType == 1)
		{
			printf("Right\n");
		}
		else if (angleType == 2)
		{
			printf("Acute\n");
		}
		else
		{
			printf("Obtuse\n");
		}
	}
}
void getSSA(float sideB, float sideC, float angleB)
{
	float perimeter;
	float perimeter2;
	float angleC;
	float sideA;
	float sideAResult;
	float sideAReasult2;
	float angleAResult;
	float angleAResult2;
	float angleCResult;
	float angleCResult2;
	float temp;
	float checkForImpposibleTriangle;
	float checkForTwoSoloutions;
	const float TRIANGLE_DEGREES = 180.0;

	temp = angleB * (M_PI / 180);
	angleC = sin(temp) * sideC;
	angleC = angleC / sideB;
	checkForImpposibleTriangle = angleC; //check if it imposible
	angleC = asin(angleC) * (180 / M_PI);
	angleCResult = angleC;

	angleAResult = TRIANGLE_DEGREES - angleCResult - angleB;
	
	temp = angleAResult * (M_PI / 180);
	sideA = sin(temp) * sideB;
	temp = angleB * (M_PI / 180);
	sideA = sideA / sin(temp);
	sideAResult = sideA;

	perimeter = sideB + sideC + sideAResult;
	float area = getArea(sideAResult, sideB, sideC);
	int triangleType = getTriangleType(sideAResult, sideB, sideC);
	int angleType = getTriangleAngleType(angleAResult, angleB, angleCResult);

	checkForTwoSoloutions = TRIANGLE_DEGREES - angleCResult;
	checkForTwoSoloutions += angleB;

	

	if (checkForImpposibleTriangle > 1.0)
	{
		printf("Imposible Triangle\n");
	}
	else if (checkForTwoSoloutions < TRIANGLE_DEGREES)
	{
		angleCResult2 = TRIANGLE_DEGREES - angleCResult;
		angleAResult2 = TRIANGLE_DEGREES - angleCResult2 - angleB;

		temp = angleAResult2 * (M_PI / 180);
		sideAReasult2 = sin(temp) * sideB;
		temp = angleB * (M_PI / 180);
		sideAReasult2 = sideAReasult2 / sin(temp);
		perimeter2 = sideB + sideC + sideAReasult2;
		float area2 = getArea(sideAReasult2, sideB, sideC);
		

		printf("%-5s %10.3f %15s %10.3f\n", "a = ", sideAResult, "Alpha =", angleAResult);
		printf("%-5s %10.3f %15s %10.3f\n", "b = ", sideB, "Beta  =", angleB);
		printf("%-5s %10.3f %15s %10.3f\n", "c = ", sideC, "Gamma =", angleCResult);
		printf("%-10s %-10s %-10.3f\n", "Perimeter", "=", perimeter);
		printf("%-10s %-10s %-10.3f\n", "Area", "=", area);

		if (triangleType == 1)
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Equilateral, ");
		}
		else if (triangleType == 2)
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Isosceles, ");
		}
		else
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Scalene, ");
		}

		if (angleType == 1)
		{
			printf("Right\n");
		}
		else if (angleType == 2)
		{
			printf("Acute\n");
		}
		else
		{
			printf("Obtuse\n");
		}

		triangleType = getTriangleType(sideAReasult2, sideB, sideC);
		angleType = getTriangleAngleType(angleAResult2, angleB, angleCResult2);
		printf("%-5s %10.3f %15s %10.3f\n", "a = ", sideAReasult2, "Alpha =", angleAResult2);
		printf("%-5s %10.3f %15s %10.3f\n", "b = ", sideB, "Beta  =", angleB);
		printf("%-5s %10.3f %15s %10.3f\n", "c = ", sideC, "Gamma =", angleCResult2);
		printf("%-10s %-10s %-10.3f\n", "Perimeter", "=", perimeter2);
		printf("%-10s %-10s %-10.3f\n", "Area", "=", area2);

		if (triangleType == 1)
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Equilateral, ");
		}
		else if (triangleType == 2)
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Isosceles, ");
		}
		else
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Scalene, ");
		}

		if (angleType == 1)
		{
			printf("Right\n");
		}
		else if (angleType == 2)
		{
			printf("Acute\n");
		}
		else
		{
			printf("Obtuse\n\n");
		}
	}
	else
	{
		printf("%-5s %10.3f %15s %10.3f\n", "a = ", sideAResult, "Alpha =", angleAResult);
		printf("%-5s %10.3f %15s %10.3f\n", "b = ", sideB, "Beta  =", angleB);
		printf("%-5s %10.3f %15s %10.3f\n", "c = ", sideC, "Gamma =", angleCResult);
		printf("%-10s %-10s %-10.3f\n", "Perimeter", "=", perimeter);
		printf("%-10s %-10s %-10.3f\n", "Area", "=", area);

		if (triangleType == 1)
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Equilateral, ");
		}
		else if (triangleType == 2)
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Isosceles, ");
		}
		else
		{
			printf("%-10s %-10s %-5s", "Type", "=", "Scalene, ");
		}

		if (angleType == 1)
		{
			printf("Right\n");
		}
		else if (angleType == 2)
		{
			printf("Acute\n");
		}
		else
		{
			printf("Obtuse\n\n");
		}
	}
}

void turnToUpperCase(char makeStringUpperCase[])
{
	int length = strlen(makeStringUpperCase);

	for (int i = 0; i < length; i++)
	{
		makeStringUpperCase[i] = toupper(makeStringUpperCase[i]);
	}
}







int main()
{
#define BUFFER 100u
	char format[BUFFER + 1];
	char triangletype[100];
	float AngleOrSideA;
	float AngleOrSideB;
	float AngleOrSideC;
	const float MAKE_POSITIVE = -1;
	int read = 0;
	int ch;
	
	printf("trisolver, Elkhai Nagawkar\n\n");
	printf("--> ");

	while (1)
	{
		gets_s(format, BUFFER);
		turnToUpperCase(triangletype);
		read = sscanf_s(format, "%s%f%f%f", triangletype, 100, &AngleOrSideA, &AngleOrSideB, &AngleOrSideC);
		
		if (AngleOrSideA < 0)
		{
			AngleOrSideA * MAKE_POSITIVE;
		}
		if (AngleOrSideB < 0)
		{
			AngleOrSideB * MAKE_POSITIVE;
		}
		if (AngleOrSideC < 0)
		{
			AngleOrSideC * MAKE_POSITIVE;
		}

		

		if (read != 4 || strcmp(triangletype, "SSS") != 0 && strcmp(triangletype, "SAS") != 0 && strcmp(triangletype, "ASA") != 0 && strcmp(triangletype, "SSA") != 0)
		{
			do
			{
				printf("Bad command : Format # # #\n");
				printf("where Format = SSS | SAS | ASA | SSA\n");
				printf("%7s %5s", "#", "= a real number\n\n");
				printf("--> ");
				rewind(stdin);
				gets_s(format, BUFFER);
				read = sscanf_s(format, "%s%f%f%f", triangletype, 100, &AngleOrSideA, &AngleOrSideB, &AngleOrSideC);
				turnToUpperCase(triangletype);
				if (AngleOrSideA < 0)
				{
					AngleOrSideA* MAKE_POSITIVE;
				}
				if (AngleOrSideB < 0)
				{
					AngleOrSideB* MAKE_POSITIVE;
				}
				if (AngleOrSideC < 0)
				{
					AngleOrSideC* MAKE_POSITIVE;
				}

			} while (read != 4 || strcmp(triangletype, "SSS") != 0 && strcmp(triangletype, "SAS") != 0 && strcmp(triangletype, "ASA") != 0 && strcmp(triangletype, "SSA") != 0);
		}
		
			if (strcmp(triangletype, "SSS") == 0)
			{
				getSSS(AngleOrSideA, AngleOrSideB, AngleOrSideC);
			}
			else if (strcmp(triangletype, "SAS") == 0)
			{
				getSAS(AngleOrSideA, AngleOrSideB, AngleOrSideC);
			}
			else if (strcmp(triangletype, "ASA") == 0)
			{
				getASA(AngleOrSideA, AngleOrSideB, AngleOrSideC);
			}
			else
			{
				getSSA(AngleOrSideA, AngleOrSideB, AngleOrSideC);
			}
		


		




	}

	return 0;
}