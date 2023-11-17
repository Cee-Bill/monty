#include "monty.h"

/**
 * ver_toks - Verifies if the tokens are in the correct format
 * @tokens: Pointer to the array of strings
 * Return: 1 if the format is valid, 0 otherwise
 */
int ver_toks(char **tokens)
{
	int i = 0;

	while (tokens[1][i])
	{
		if ((strcmp(tokens[0], "pall") == 0) || (strcmp(tokens[0], "pop") == 0) ||
				(strcmp(tokens[0], "nop") == 0) || (strcmp(tokens[0], "pint") == 0) ||
				(strcmp(tokens[0], "swap") == 0) || (strcmp(tokens[0], "add") == 0) ||
				(strcmp(tokens[0], "sub") == 0))
		{
			return 1;
		}

		if ((tokens[1][i] >= 48 && tokens[1][i] <= 57) || (tokens[1][0] == '-'))
		{
			i++;
		}
		else
		{
			return 0;
		}
	}

	return 1;
}
