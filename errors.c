#include "monty.h"

/**
 * cleanup_and_exit_failure - performs cleanup and exits with EXIT_FAILURE
*/
void cleanup_and_exit_failure(void)
{
	cleanup();
	exit(EXIT_FAILURE);
}

/**
 * err_usage - prints usage error to stderr,
 * performs cleanup and exits with EXIT_FAILURE
*/
void err_usage(void)
{
	fprintf(stderr, "L%u: usage: push integer\n", globals.cLine);
	cleanup_and_exit_failure();
}

/**
 * err_division_by_zero - prints division by zero error to stderr,
 * performs cleanup and exits with EXIT_FAILURE
*/
void err_division_by_zero(void)
{
	fprintf(stderr, "L%u: division by zero\n", globals.cLine);
	cleanup_and_exit_failure();
}

/**
 * err_stack_too_short - prints stack too short error to stderr,
 * performs cleanup and exits with EXIT_FAILURE
 * @opcode: char pointer to opcode for which to print error
*/
void err_stack_too_short(char *opcode)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", globals.cLine, opcode);
	cleanup_and_exit_failure();
}
