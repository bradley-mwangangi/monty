#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct global_s - structure for global variables
 * @isStack: boolean for is either stack or queue (not stack)
 * @cLine: current line
 * @arg: pointer to opcode argument
 * @top: pointer to top of stack
 * @file: pointer to file
 * @buffer: pointer to buffer
*/
typedef struct global_s
{
	bool isStack;
	unsigned int cLine;
	char *arg;
	stack_t *top;
	FILE *file;
	char *buffer;
} global_t;

extern global_t globals;

ssize_t _getline(char **buffer, size_t *size, FILE *fp);

void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number);

void _push(stack_t **top, unsigned int line_number);
void _pall(stack_t **top, unsigned int line_number);
void _pint(stack_t **top, unsigned int line_number);
void _pop(stack_t **top, unsigned int line_number);
void _swap(stack_t **top, unsigned int line_number);
void _add(stack_t **top, unsigned int line_number);
void _nop(stack_t **top, unsigned int line_number);
void _sub(stack_t **top, unsigned int line_number);
void _div(stack_t **top, unsigned int line_number);
void _mul(stack_t **top, unsigned int line_number);
void _mod(stack_t **top, unsigned int line_number);
void _pchar(stack_t **top, unsigned int line_number);
void _pstr(stack_t **top, unsigned int line_number);
void _rotl(stack_t **top, unsigned int line_number);
void _rotr(stack_t **top, unsigned int line_number);
void _stack(stack_t **top, unsigned int line_number);
void _queue(stack_t **top, unsigned int line_number);

stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);

void free_dlistint(stack_t *head);
void cleanup_and_exit_failure(void);
void err_usage(void);
void err_division_by_zero(void);
void err_stack_too_short(char *opcode);
void cleanup(void);

#endif /* MONTY_H */
