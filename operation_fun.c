#include "monty.h"

/**
* op_select -> Selects a function
* @line_info: words in line
* @stack_ptr: pointer to the stack memory address
* @line_num: current line number.
* @monty_file: the monty file
*
* Return: 0(Success), if opcode is found. Otherwise 1.
*/
int op_select_fun(char *line_info, stack_t **stack_ptr, unsigned int line_num,
	FILE *monty_file)
{
	global_rep global;
	unsigned int idx = 0;
	char *code_opt;

	instruction_t list_op[] = {
		{"push", push_value},
	};
	code_opt = strtok(line_info, DEL);
	if (code_opt && code_opt[0] == '#')
		return (0);
	global.data_ptr = strtok(NULL, DEL);

	while (list_op[idx].opcode && code_opt)
	{
		if (strcmp(code_opt, list_op[idx].opcode) == 0)
		{
			list_op[idx].f(stack_ptr, line_num);
			return (0);
		}
		idx++;
	}
	if (code_opt && list_op[idx].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, code_opt);
		fclose(monty_file);
		free(line_info);
	}
	return (1);
}
