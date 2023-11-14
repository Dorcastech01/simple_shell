#include "main.h"




/**
 * del_comment - this is the function
 * Description: this function is used to delete comments from the input
 * @inp_str: the first arg
 * Return: the result
 */


char *del_comment(char *inp_str)
{
	int x, count;

	count = 0;
	for (x = 0; inp_str[x]; x++)
	{
		if (inp_str[x] == '#')
		{
			if (x == 0)
			{
				free(inp_str);
				return (NULL);
			}

			if (inp_str[x - 1] ==
					' ' || inp_str[x - 1] == '\t' || inp_str[x - 1] == ';')
				count = x;
		}
	}

	if (count != 0)
	{
		inp_str = ss_realloc(inp_str, x, count + 1);
		inp_str[count] = '\0';
	}

	return (inp_str);
}




/**
 * shell_loop - this is the function
 * Description: this is the loop of  the shell
 * @dir: the arg
 */

void shell_loop(data *dir)
{
	int loop, i_eof;
	char *inp_str;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		inp_str = read_line(&i_eof);
		if (i_eof != -1)
		{
			inp_str = del_comment(inp_str);
			if (inp_str == NULL)
				continue;

			if (check_syntax_error(dir, inp_str) == 1)
			{
				dir->stats = 2;
				free(inp_str);
				continue;
			}
			inp_str = replace_var(inp_str, dir);
			loop = split_commands(dir, inp_str);
			dir->num += 1;
			free(inp_str);
		}
		else
		{
			loop = 0;
			free(inp_str);
		}
	}
}
