#include "shell.h"

/**
 * is_it_the_Delimiter - checks if character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int is_it_the_Delimiter(char c, const char *delim)
{
    
	while (*delim != '\0') 
	
	{
	
		if (*delim == c)
	
	{
	
		return 1;
        
	}

	delim++;
	
	}

	return (0);
}

