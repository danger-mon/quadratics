/***********************************************************************
* main.c
* Copyright (c) 2013 danger-mon. All rights reserved.
***********************************************************************/

#include <stdio.h>
#include <math.h>
#include "iomethods.h"
#include <float.h>

//Define helper methods
float WorkOutx(float a, float b, float c);
float WorkOuty(float a, float b, float c);
void PrintOut(float x, float y);

int main(int argc, char *argv[])
{
	float a, b, c;

	//Check whether 4 arguments were entered
	if (argc == 4)
	{
		//Check all were floats
		if (sscanf(argv[1], "%f", &a) != 1 || sscanf(argv[2], "%f", &b) != 1 || sscanf(argv[3], "%f", &c) != 1)
		{
			printf("You didn't enter a number!\n");
			return 1;
		}

		//Work out answers
		float x = WorkOutx(a, b, c);
		float y = WorkOuty(a, b, c);

		//Print answers
		PrintOut(x, y);
	}
	else
	{
		//Carry on asking for numbers
		while (1 == 1)
		{	
			if (argc == 1)
			{
				//Get input
				printf("Enter A: ");
				a = GetFloat();
				printf("Enter B: ");
				b = GetFloat();
				printf("Enter C: ");
				c = GetFloat();

			}
			
			//Work out answers
			float x = WorkOutx(a, b, c);
			float y = WorkOuty(a, b, c);

			//Print answers
			PrintOut(x, y);
		}
	}
}

//Helper Methods
float WorkOutx (float a, float b, float c)
{
	float x = (-b+sqrtf((b*b)-4*a*c))/(2*a);
	if (x != x)
	{
		return FLT_MAX;
	}
	return x;
}

float WorkOuty (float a, float b, float c)
{
	float y = (-b-sqrtf((b*b)-4*a*c))/(2*a);
	if (y != y)
	{
		return FLT_MAX;
	}
	return y;
}

void PrintOut (float x, float y)
{
	if (x == FLT_MAX || y == FLT_MAX)
	{
		printf("There is no solution, make sure numbers are inputted correctly\n");
	}
	else
	{
		printf("Answer is: %g or %g\n", x, y);	
	}
}