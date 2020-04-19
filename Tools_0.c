#include "holberton.h"
/**
*_strcmp - a function that compares two strings.
*
*@s2: Pointer to the array.
*@s1: Pointer to the array.
*
*Return: int.
*/
int _strcmp(char *s1, char *s2)
{
	char c1, c2;

	do {
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
		if (c1 == '\0')
			return (c1 - c2);
	} while (c1 == c2);
	return (c1 - c2);
}
