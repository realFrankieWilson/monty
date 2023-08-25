#include "monty.h"
int malloc_failed(void);
int error_usage(void);
int file_open_error(char *);
int unknown_operator(char *, unsigned int);
int no_int_error(unsigned int);


/**
 * malloc_failed -> Prints malloc error message
 *
 * Return: (exit_failure)
 */
int malloc_failed(void)
{
	fprintf(stderr, "Error: mallock failed\n");
	return (EXIT_FAILURE);
}



/**
 * error_usage -> Prints usage error
 *
 * Return: (exit_failure)
 */
int error_usage(void)
{
	fprintf(stderr, "Usage: monty file\n");
	return (EXIT_FAILURE);
}


/**
 * file_open_error -> Prints error message if unable to open file
 * @filename: Name of the failed file to open
 *
 * Return: (exit_failure)
*/
int file_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}


/**
* unknown_operator -> Prints unknown instruction error messages.
* @opcode: Opcode where error occured.
* @line_num: Line number in monty bytecodes file where error occured.
*
* Return: (exit_failure)
*/
int unknown_operator(char *opcode, unsigned int line_num)
{
	/*fprintf(, "L%u: Unknown operator %s\n", line_num, opcode);*/
	return (EXIT_FAILURE);
}


/**
 * no_int_error -> Prints invalid monty push argument error message
 * @line_num: Line Number in Monty bytecodes file where error occurred
 *
 * Return: (exit failure)
 */
int no_int_error(unsigned int line_num)
{
	fprintf(stderr, "L%u: Usage: push integer\n", line_num);
	return (EXIT_FAILURE);
}
