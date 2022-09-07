#include "monty.h"
global_t the_global;
/**
 * main - Entry point
 *
 * @argc: number of arguments
 * @argv: list of arguments
 *
 * Return: returns EXIT_SUCCESS on success else EXIT_FAILURE 
 */
int main(int argc, char *argv[])
{
	instruction_t opcodes[] = {{"push", push_stack}, {"pall", pall}, {"pop", pop}, {"pint", pint}, {"swap", swap}, {"add", add}
	};
	stack_t *stack = NULL;
	int line_number = 1, getline_res = 0;
	size_t buf_size = 0;

	if (argc != 2)
	{	
		/*return error message*/
		error_message("USAGE: monty file", "", &stack);
	}
	the_global.file = fopen(argv[1], "r");
	if (!the_global.file)
		error_message("Error: Can't open file ", argv[1], &stack);
	while (1)
	{
		getline_res = getline(&the_global.Line_buffer, &buf_size, the_global.file);
		if (getline_res == EOF)
			break;
		check_opc(strtok(the_global.Line_buffer, " \t"), &opcodes, line_number,
			&stack);
		line_number++;
	}
	free_all(&stack);
	return (EXIT_SUCCESS);

}
