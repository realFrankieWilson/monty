int malloc_error(void);

/**
 * malloc_failed -> Prints malloc error message
 *
 * Return: Nothing
 */

int malloc_failed(void)
{
	fprint(stderr, "Error: mallock failed\n");
	return (EXIT_FAILURE);
}
