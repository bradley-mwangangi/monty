#include "monty.h"

/**
 * err_usage - prints usage error to stderr and exits with EXIT_FAILURE
*/
void err_usage(void)
{
	fprintf(stderr, "L%u: ", globals.cLine);
	fprintf(stderr, "usage: push integer\n");
	cleanup();

	exit(EXIT_FAILURE);
}
