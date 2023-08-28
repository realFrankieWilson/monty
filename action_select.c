#include "monty.h"

/**
* op_select -> Selects a function
* @line_info: words in line
* @stack_ptr: pointer to the stack memory address
* @l_num: current line number.
* @monty_file: the monty file
*
* Return: 0(Success), if opcode is found. Otherwise 1.
*/
int op_select_fun(char *line_info, stack_t **stack_ptr, unsigned int l_num,
		FILE *monty_file)
{
	unsigned int idx = 0;
	char *codeOp;

	/** Lists of Actions to take */
	instruction_t listOpc[] = {
		{"push", push_value}, {"pall", print_stk},
		{"pint", print_tp}, {"pchar", pchar},
		{"pstr", pstr}, {"pop", delett},
		{"nop", nop}, {"queue", queue_f},
		{"swap", swaptp}, {"rotl", rotatetp},
		{"rotr", rotatebtm}, {"add", addmath},
		{"sub", submath}, {"mul", mulmath},
		{"div", divmath}, {"mod", modmath},
		{"stack", stack_f}, {NULL, NULL}
	};


	codeOp = strtok(line_info, " \n\t");
	if (codeOp && codeOp[0] == '#')
		return (0);
	global.data_ptr = strtok(NULL, " \n\t");

	while (listOpc[idx].opcode && codeOp)
	{
		if (strcmp(codeOp, listOpc[idx].opcode) == 0)
		{
			listOpc[idx].f(stack_ptr, l_num);
			return (0);
		}
		idx++;
	}
	if (codeOp && listOpc[idx].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s"N, l_num, codeOp);
		fclose(monty_file);
		free(line_info);
		free_stack(*stack_ptr);
		exit(EXIT_FAILURE);
	}
	return (1);
}

