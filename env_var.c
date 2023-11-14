#include "main.h"




/**
 * cmpvar_name - this is the function
 * Description: this function is used to compare env variable names
 * with the name passed
 * @name_envvar: this is the first arg of the function
 * @name_passed: this is the second arg of the function
 * Return: the result
 */


int cmpvar_name(const char *name_envvar, const char *name_passed)
{
	int a;

	for (a = 0; name_envvar[a] != '='; a++)
	{
		if (name_envvar[a] != name_passed[a])
		{
			return (0);
		}
	}

	return (a + 1);
}




/**
 * ss_getenv - this is the function
 * Description: this function is used to get an environment variable
 * @envvar_name: this is the first arg of the function
 * @var_environ: this is the second arg of the function
 * Return: the result
 */


char *ss_getenv(const char *envvar_name, char **var_environ)
{
	char *ptr_env;
	int a, mov;

	ptr_env = NULL;
	mov = 0;
	for (a = 0; var_environ[a]; a++)
	{
		mov = cmpvar_name(var_environ[a], envvar_name);
		if (mov)
		{
			ptr_env = var_environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}




/**
 * ss_env - this is the function
 * Description: this function is used to print the evironment variables
 * @dir: this is the arg of the function
 * Return: the result
 */


int ss_env(data *dir)
{
	int a, x;

	for (a = 0; dir->var_environ[a]; a++)
	{

		for (x = 0; dir->var_environ[a][x]; x++)
			;

		write(STDOUT_FILENO, dir->var_environ[a], x);
		write(STDOUT_FILENO, "\n", 1);
	}
	dir->stats = 0;

	return (1);
}
