#include "monty.h"

global_t globals;

/**
 * init_globals - initialize global variables
 * @file: pointer to file descriptor
*/
void init_globals(FILE *file)
{
	globals.isStack = true;
	globals.cLine = 1;
	globals.arg = NULL;
	globals.top = NULL;
	globals.file = file;
	globals.buffer = NULL;
}

/**
 * cleanup - performs memory cleanup
*/
void cleanup(void)
{
	free_dlistint(globals.top);
	free(globals.buffer);
	fclose(globals.file);
}

FILE *validate_input(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * main - program entry
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
*/
int main(int argc, char *argv[])
{
	FILE *file;
	size_t n = 256;
	ssize_t nchars_read = 0;
	char *line_read;
	void (*f)(stack_t **stack, unsigned int line_number);

	file = validate_input(argc, argv);
	init_globals(file);

	nchars_read = _getline(&globals.buffer, &n, file);
	while (nchars_read != -1)
	{
		line_read = strtok(globals.buffer, " \t\n");
		if (line_read && line_read[0] != '#')
		{
			f = get_opcode(line_read);
			if (!f)
			{
				fprintf(stderr, "L%u: ", globals.cLine);
				fprintf(stderr, "unknown instruction %s\n", line_read);
				cleanup_and_exit_failure();
			}
			globals.arg = strtok(NULL, " \t\n");
			f(&globals.top, globals.cLine);
		}
		nchars_read = _getline(&globals.buffer, &n, file);
		globals.cLine++;
	}
	cleanup();

	return (0);
}
