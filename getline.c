#include "monty.h"

/**
 * _getline - reads an entire line from fp,
 * storing the address of the buffer containing the text into *buffer
 * the buffer is null-terminated and includes the newline char if found
 * @buffer: pointer to address of buffer where the line read will be stored
 * @size: size of the buffer pointed to by buffer
 * @fp: input stream from which _getline will read the line
 *
 * Return: number of chars read, including the delimeter character but not '\0'
 * -1 on failure to read a line (including EOF condition) or length is 0
*/
ssize_t _getline(char **buffer, size_t *size, FILE *fp)
{
	int c;
	size_t length = 0;
	char *temp;

	if (*buffer == NULL)
	{
		*size = 128;
		*buffer = (char *)malloc(*size);
		if (*buffer == NULL)
			return (-1);
	}

	while ((c = getc(fp)) != EOF)
	{
		if (length >= *size - 1)
		{
			*size *= 2;
			temp = (char *)realloc(*buffer, *size);

			if (temp == NULL)
			{
				free(*buffer);
				*buffer = NULL;
				return (-1);
			}
			*buffer = temp;
		}
		(*buffer)[length++] = (char)c;
		if (c == '\n')
		{
			(*buffer)[length] = '\0';
			return ((ssize_t)length);
		}
	}
	if (length == 0)
		return (-1);

	(*buffer)[length] = '\0';

	return ((ssize_t)length);
}
