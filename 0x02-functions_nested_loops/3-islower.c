#include "main.h"
/**
 * _islower - Show if the input is lower
 *
 * Description: A C program that print the input in lowercase
 *
 *@C: the cgaracter in ASCII code
 *
 * Return : returns 1 if 'c' is lowercase otherwise  always 0 (Success)
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}
