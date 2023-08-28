#include "monty.h"
#define  _GNU_SOURCE
#include <stdio.h>
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
	FILE *file_handle;
	char *line_info = NULL;
	size_t size = 0;
	ssize_t line_content = 1;
	stack_t *stack = NULL;
	unsigned int l_num = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_handle = fopen(argv[1], "r");
	global.f_handler = file_handle;

	if (file_handle == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while ((line_content = getline(&line_info, &size, file_handle)) > 0)
	{
		/*line_content = getline(&line_info, &size, file_handle);*/
		global.monty_line = line_info;
		l_num++;

		if (line_content > 0)
			op_select_fun(line_info, &stack, l_num, file_handle);
		free(line_info);
	}
	free_stack(stack);
	fclose(file_handle);
	return (0);
}
