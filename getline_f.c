#include "main.h"




/**
 * assign_line - this is the function
 * Description: this function is used to assign
 * the line variable for getline function
 * @str_ptr: this is the first arg of the function
 * @buff: this is the second arg of the function
 * @line_size: this is the third arg of the function
 * @buff_size: this is the fourth arg of the function
 */


void assign_line(char **str_ptr, size_t *line_size, char *buff, size_t buff_size)
{

	if (*str_ptr == NULL)
	{
		if  (buff_size > SHELL_BUFSIZE)
			*line_size = buff_size;

		else
			*line_size = SHELL_BUFSIZE;
		*str_ptr = buff;
	}
	else if (*line_size < buff_size)
	{
		if (buff_size > SHELL_BUFSIZE)
			*line_size = buff_size;
		else
			*line_size = SHELL_BUFSIZE;
		*str_ptr = buff;
	}
	else
	{
		ss_strcpy(*str_ptr, buff);
		free(buff);
	}
}




/**
 * getline_f - this is the function
 * Description: this functiomn is used to read user input from stream
 * @str_ptr: this is the first arg of the function
 * @line_size: this is the second arg of the function
 * @stream: this is the third arg of the function
 * Return: the result
 */


ssize_t getline_f(char **str_ptr, size_t *line_ptr, FILE *stream)
{
	int a;
	static ssize_t user_input;
	ssize_t retval;
	char *buff;
	char t = 'z';

	if (user_input == 0)
		fflush(stream);
	else
		return (-1);
	user_input = 0;

	buff = malloc(sizeof(char) * SHELL_BUFSIZE);
	if (buff == 0)
		return (-1);
	while (t != '\n')
	{
		a = read(STDIN_FILENO, &t, 1);
		if (a == -1 || (a == 0 && user_input == 0))
		{
			free(buff);
			return (-1);
		}
		if (a == 0 && user_input != 0)
		{
			user_input++;
			break;
		}
		if (user_input >= SHELL_BUFSIZE)
			buff = ss_realloc(buff, user_input, user_input + 1);
		buff[user_input] = t;
		user_input++;
	}
	buff[user_input] = '\0';
	assign_line(str_ptr, line_size, buff, user_input);
	retval = user_input;
	if (a != 0)
		user_input = 0;
	return (retval);
}
