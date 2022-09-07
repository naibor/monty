#include "monty.h"
/**
* _isnumber - Helper function
* Description: checks if a string is a number.
*
* @str: String to check.
*
* Return: 1 if is a number, 0 if not.
*/
short _isnumber(char *str)
{
	short i;

	if (*str == '\n')
		return (0);
	for (i = 0; *(str + i) && *(str + i) != '\n'; i++)
		if (!isdigit(*(str + i)) && *(str + i) != '-')
			return (0);
	return (1);
}
