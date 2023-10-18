#include <ctype.h>
#include "monty.h"

/**
 * push - pushes a node to top of the stack
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void push(stack_t **top, unsigned int line_number)
{
	int i, value;
	(void)line_number;

	if (!globals.arg)
	{
		err_usage();
	}

	for (i = 0; globals.arg[i] != '\0'; i++)
	{
		if (!isdigit(globals.arg[i]) && globals.arg[i] != '-')
		{
			err_usage();
		}
	}

	value = atoi(globals.arg);

	if (globals.isStack)
		add_dnodeint(top, value);
	else
	    add_dnodeint_end(top, value);
}

/**
 * pall - prints all values in the stack
 * @top: pointer to pointer of stack's top node
 * @line_number: current line's number
*/
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *top;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
