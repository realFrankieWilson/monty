#include "monty.h"
global_rep global;

/**
 * main -> Runs the program
 * @argc: Argument count
 * @argv: Argument array passed by the usr
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *f_desc;
	char *line_info;
	size_t size = 0;
	ssize_t line_content = 1;
	stack_t *stack = NULL;
	unsigned int line_num = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f_desc = fopen(argv[1], "r");
	global.f_handler = f_desc;

	if (f_desc == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (line_content > 0)
	{
		line_info = NULL;
		line_content = getline(&line_info, &size, f_desc);
		global.monty_line = line_info;
		line_num++;

		if (line_content > 0)
			op_select_fun(line_info, &stack, line_num, f_desc);
		free(line_info);
	}
	free_stack(stack);
	fclose(f_desc);
}
