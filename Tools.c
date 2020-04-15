#include "holberton.h"


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
*_puts -  function that prints a string, followed by a new line, to stdout.
**@str : int
* Return : Void.
*/
void _puts(char *str)
{
	int i = -1;

	while (str[++i] != '\0')
		_putchar(str[i]);
	/**_putchar('\n');*/
}

/**
 * _strdup - function that returns a pointer to a newly allocated space in
 *  memory, which contains a copy of the string given as a parameter.
 *@str : array.
 * Return: pointer to a new string , NULL if str = NULL , on success eturns a
 * pointer to the duplicated string
 */

char *_strdup(char *str)
{
	int i = 0, len = 0;
	char *p;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	p = malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	for (i = 0 ; i < len  ; i++)
		p[i] = str[i];
	p[i] = '\0';
	return (p);
}
/**
 * str_concat - a function that concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 * Return: result of concarenation on success , NULL on Failure.
 */
char *str_concat(char *s1, char *s2)
{
	int l1 = 0, l2 = 0, i = 0;
	char *p = NULL;

	if (s1 == NULL)
		l1 = 0;
	else
	{
		while (s1[l1] != '\0')
			l1++;
	}
	if (s2 == NULL)
		l2 = 0;
	else
	{
		while (s2[l2] != '\0')
			l2++;
	}
	p = malloc((l1 + l2 + 1) * sizeof(char));
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0 ; i < l1 ; i++)
	{
		p[i] = s1[i];
	}
	for (i = 0 ; i < l2 ; i++)
	{
		p[i + l1] = s2[i];
	}
	p[l1 + l2] = '\0';
	return (p);
}

/**
 *_itoi- Function that convert an integer string.
 *
 *@num: The number to be converted.
 *
 *Return:String.
*/
char *_itoi(long long num)
{
	long long num_tmp, div = 1;
	long long i = 0, j = 0, tmp_i;
	char *str_num = NULL;

	num_tmp = num;
	while (num_tmp != 0)
	{
		num_tmp /= 10;
		i++;
	}
	str_num = malloc((i + 1) * sizeof(char));
	tmp_i = i;
	while (--tmp_i)
		div *= 10;
	while (j < i)
	{
		str_num[j] = (num / div) + '0';
		num = num % ((num / div) * div);
		div /= 10;
		j++;
	}
	str_num[j] = '\0';
	return (str_num);
}
