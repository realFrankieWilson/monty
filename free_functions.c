#include "monty.h"

/**
* free_stack -> Releases the memory use of the stack element
* @stack_ptr: Pointer to stack memory address
* Return: Nothing.
*/
void free_stack(stack_t *stack_ptr)
{
	stack_t *tmp = stack_ptr;

	while (stack_ptr)
	{
		tmp = stack_ptr->next;
		free(stack_ptr);
		stack_ptr = tmp;
	}
}



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
