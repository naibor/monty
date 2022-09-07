#include "monty.h"
/* main - Entry point
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: returns EXIT_SUCCESS on success else EXIT_FAILURE 
 */
int main(int argc, char *argv[])
{
	instruction_t opcodes[] = {{"push", push_stack}, {"pall", pall}, {"pop", pop}, {"pint", pint},{"add", add}
	};
	stack_t *stack = NULL;

	if (argc != 2)
	{	
		/*return error message*/
		error_message("USAGE: monty file", "", &stack);
	}
	return (EXIT_SUCCESS);

}
