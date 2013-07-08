/***********************************************************************
* Based on the CS50 Library 4 
* https://manual.cs50.net/Library
*
* Copyright (c) 2013 danger mon. All rights reserved.
***********************************************************************/

#include "iomethods.h"
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>

float GetFloat(void)
{
    // try to get a float from user
    while (1 == 1)
    {
        // get line of text, returning FLT_MAX on failure
        char* line = GetString();
        if (line == NULL)
        {
            return FLT_MAX;
        }

        // return a float if only a float (possibly with
        // leading and/or trailing whitespace) was provided
        char c;
        float f;
        if (sscanf(line, " %f %c", &f, &c) == 1)
        {
            free(line);
            return f;
        }
        else
        {
            free(line);
            printf("Retry: ");
        }
    }
}

char* GetString(void)
{

    char* buffer = NULL;

    unsigned int cap = 0;

    unsigned int num = 0;

    int cha;


    while ((cha = getchar()) != '\n')
    {

        if (num + 1 > cap)
        {

            if (cap == 0)
            {
                cap = 32;
            }
            else if (cap <= (UINT_MAX / 2))
            {
                cap *= 2;
            }
            else
            {
                free(buffer);
                return NULL;
            }

            //Re-allocate more memory for the bigger capacity
            char* increased = realloc(buffer, cap * sizeof(char));
            if (increased == NULL)
            {
                free(buffer);
                return NULL;
            }
            //Assign the new allocation to the buffer
            buffer = increased;
        }

        buffer[num++] = cha;
    }

    if (num == 0)
    {
        return NULL;
    }

    //Create new String with the necessary amount of memory
    char* condensed = malloc((num + 1) * sizeof(char));
    //Copy the chars in the buffer string into the condensed string up to num bytes
    strncpy(condensed, buffer, num);
    //Free the buffer
    free(buffer);

    //Add '\0' inorder to terminate the string
    condensed[num] = '\0';

    return condensed;
}