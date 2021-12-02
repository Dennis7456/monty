#include "monty.h"

char *lines_check(char *buffer, unsigned int line_number)
{
	char *token = NULL, *num_t = NULL;
	long int i = 0;

	token = strtok(buffer, " \t\n");
	if (strcmp(token, "push") == 0)
	{
		num_t = strtok(NULL, " \t\n");
		if (num_t == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free(buffer);
			var_glob[1] = 1;
			return (NULL);
		}
		for (i = 0; num_t[i] != '\0'; i++)
		{
			if (num_t[i] == '-')
				i++;
			if (num_t[i] < 48 || num_t[i] > 57)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				free(buffer);
				var_glob[1] = 1;
				return (NULL);
			}
		}
		var_glob[0] = atoi(num_t);
	}
	return (token);
}