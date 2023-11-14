#include "main.h"



/**
 * shell_builtins - this is the function
 * Description: this function is the builtin that pass the command in the arg
 * @cmd: this is the arg in the function
 * Return: the result
 */


int (*shell_builtins(char *cmd))(data *)
{
	builtin builtins[] = {
		{ "env", ss_env },
		{ "exit", shell_exit },
		{ "setenv", ss_setenv },
		{ "unsetenv", ss_unsetenv },
		{ "cd", cd_f },
		{ "help", help_f },
		{ NULL, NULL }
	};
	int a;

	for (a = 0; builtins[a].cmd_name; a++)
	{
		if (ss_strcmp(builtins[a].cmd_name, cmd_name) == 0)
			break;
	}

	return (builtins[a].func);
}
