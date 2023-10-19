#include "monty.h"

/**
 * get_opcode - selects the correct opcode function
 * @opcode: opcode passed into function
 *
 * Return: pointer to selected function
*/
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};

	int i;

	for (i = 0; instruction[i].opcode; i++)
	{
		if (strcmp(instruction[i].opcode, opcode) == 0)
			break;
	}

	return (instruction[i].f);
}
