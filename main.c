//
//  main.c
//  hello
//
//  Created by daniel germon on 24/03/2013.
//  Copyright (c) 2013 daniel germon. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, string argv[])
{
	//Make sure four arguments are entered
	if (argc != 4)
	{
		printf("Error, not enough agruments\n");
		return 1;
	}

	//Declare variables for numbers
	float a, b, c;

	//Get the numbers from the command line
	if (sscanf(argv[1], "%f", &a) != 1 || sscanf(argv[1], "%f", &b) != 1 || sscanf(argv[3], "%f", &c) != 1)
	{
		printf("You didn't enter a number!\n");
		return 1;
	}
	
	//Work out answers
	float x = (-b+sqrtf((b*b)-4*a*c))/(2*a);
	
	float y = (-b-sqrtf((b*b)-4*a*c))/(2*a);

	//Print answers
	printf("Answer is: %g or %g\n", x, y);

}