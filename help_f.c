#include "main.h"



/**
 * help_f - this is the function
 * Description: this function is used to get help messages according to
 * the builtin cmd entered
 * @dir: this is the arg of the function
 * Return: the result
*/


int help_f(data *dir)
{

	if (dir->args[1] == 0)
		help_entry();
	else if (ss_strcmp(dir->args[1], "setenv") == 0)
		setenv_help();
	else if (ss_strcmp(dir->args[1], "env") == 0)
		env_help();
	else if (ss_strcmp(dir->args[1], "unsetenv") == 0)
		unsetenv_help();
	else if (ss_strcmp(dir->args[1], "help") == 0)
		get_help();
	else if (ss_strcmp(dir->args[1], "exit") == 0)
		help_exit();
	else if (ss_strcmp(dir->args[1], "cd") == 0)
		getcd_help();
	else if (ss_strcmp(dir->args[1], "alias") == 0)
		getalias_help();
	else
		write(STDERR_FILENO, dir->args[0],
		      ss_strlen(dir->args[0]));

	dir->stats = 0;
	return (1);
}
