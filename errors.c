/**
* error_message - Function
*
* Description: Prints error message, exits with failure.
* 
* @message: Message to print.
* @arg: argument.
* @stack: stack to free.
*/
void error_message(char *message, char *arg)
{
	fprintf(stderr, "%s%s\n", message, arg);
	exit(EXIT_FAILURE);
}
