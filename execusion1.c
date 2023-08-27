#include "monty.h"

/**
* queue_f -> A queue function to describe a data struct
* @stack_ptr: The pointer to the stack memory address
* @l_num: The current line number
*
* Return: Nothing
*/
void queue_f(stack_t **stack_ptr, unsigned int l_num)
{
	(void)stack_ptr;
	(void)l_num;
	global.data_ptr = 0;
}



/**
* stack_f -> A function that describes a data struct
* @stack_ptr: A pointer to the stack memory address
* @l_num: The current line number.
*
* Return: Nothing
*/
void stack_f(stack_t **stack_ptr, unsigned int l_num)
{
	(void)stack_ptr;
	(void)l_num;
	global.data_string = 1;
}
