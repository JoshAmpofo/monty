#include "monty.h"

int usage_error(void);
int malloc_error(void);
int f_open_err(char *filename);
int inv_ins_error(char *opcode, unsigned int line_number);
int intnum_error(unsigned int line_number);

/**
 * usage_error - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_err - Prints file opening error messages w/ file name.
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int f_open_err(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * inv_ins_err - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_number: Line number in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int inv_ins_err(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * intnum_err - Prints invalid monty_push argument error messages.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int intnum_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
