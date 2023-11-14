#include "main.h"




/**
 * read_cmd - this is the function
 * Description: this function is used to read the user input
 * @i_eof: this is the arg of the function
 * Return: the result
 */


char *read_cmd(int *i_eof)
{
	char *user_input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&user_input, &bufsize, stdin);

	return (user_input);
}
