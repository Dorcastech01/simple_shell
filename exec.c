#include "main.h"




/**
 * exec_cmds - this is the function
 * Description: this function is used to find builtin commands
 * @dir: this is the arg of the function
 * Return: the result
 */


int exec_cmds(data *dir)
{
	int (*builtin)(data *dir);

	if (dir->args[0] == NULL)
		return (1);

	builtin = get_builtin(dir->args[0]);

	if (builtin != NULL)
		return (builtin(dir));

	return (cmd_line(dir));
}
