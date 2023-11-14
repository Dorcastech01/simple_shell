#include "main.h"

/**
 * shell_exit - this is the function
 * Description: this function is used to exit the shell
 * @dir: this is the arg of the function 
 * Return: the result
 */


int shell_exit(data *dir)
{
	unsigned int x_stats;
	int is_digit;
	int str_len;
	int big_number;

	if (dir->args[1] != NULL)
	{
		x_stats = ss_atoi(dir->args[1]);
		is_digit = ss_isdigit(dir->args[1]);
		str_len = ss_strlen(dir->args[1]);
		big_number = x_stats > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(dir, 2);
			dir->stats = 2;
			return (1);
		}
		dir->stats = (x_stats % 256);
	}
	return (0);
}
