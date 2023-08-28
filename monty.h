#ifndef MONTY_H
#define MONTY_H




/******************* STANDARD LIBRARY ******************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <fcntl.h>




/***************** MACROS *************************************/
#define DEL " \t\n"
#define N "\n"

/******************** STRUCTURES DECLARATIONS*******************
 * struct stac_s -> doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previouse element of the stack or queue
 * @next: points to the next element of the stack or queue
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;



/**
 * struct global_rep -> Global representation
 * @data: integer
 * @prev_st: points to the previous element of the stack (or queue)
 * @next_st: points to the next element of the stack (or queue)
 * @flag_q: checks for queue
 * @data_ptr: ....
 */
typedef struct global_s
{
	char *data_ptr;
	FILE *f_handler;
	char *monty_line;
	int data_string;
} global_rep;


/**
 * struct instructions_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/*action select function*/
int op_select_fun(char *, stack_t **, unsigned int, FILE *filename);

/**global variable*/
extern global_rep global;


/******************** CODE FUNCTIONS ***********************/

/*execusion0 function*/
void push_value(stack_t **, unsigned int);
void addtp(stack_t **, int);
void addlst(stack_t **, int);
void delett(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

/*execusion1*/
void queue_f(stack_t **, unsigned int);
void stack_f(stack_t **, unsigned int);
void swaptp(stack_t **, unsigned int);
void rotatetp(stack_t **, unsigned int);
void rotatebtm(stack_t **, unsigned int);

/*display function */
void print_stk(stack_t **, unsigned int);
void print_tp(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);

/*math function*/
void addmath(stack_t **, unsigned int);
void submath(stack_t **, unsigned int);
void modmath(stack_t **, unsigned int);
void divmath(stack_t **, unsigned int);
void mulmath(stack_t **, unsigned int);

/******************** ERROR MESSAGES ***********************/
int malloc_failed(void);
void free_stack(stack_t *);


#endif /*MONTY*/
