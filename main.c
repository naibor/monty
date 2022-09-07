#include "monty.h"
/* main - Entry point
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: returns EXIT_SUCCESS on success else EXIT_FAILURE 
 */
int main(int argc, char *argv[])
{
	instruction_t opcodes[] = {{"push", push_stack}, {"pall", pall}, {"pop", pop}
	};

	if (argc != 2)
	{	
		/*return error message*/
		error_message("USAGE: monty file", "");
	}
	return (EXIT_SUCCESS)

}
