#include "main.h"




/**
 * vi_env - this is a function
 * Description: this function is used to copy information
 * to create a new env or alias
 * @env_name: this is the first arg of the function
 * @env_value: this is the second arg of the function
 * Return: the result
 */


char *vi_env(char *env_name, char *env_value)
{
	char *new_env;
	int name_len, value_len, len;

	name_len = ss_strlen(env_name);
	value_len = ss_strlen(env_value);
	len = name_len + value_len + 2;
	new_env = malloc(sizeof(char) * (len));
	ss_strcpy(new_env, env_name);
	ss_strcat(new_env, "=");
	ss_strcat(new_env, env_value);
	ss_strcat(new_env, "\0");

	return (new_env);
}




/**
 * set_env - this is the function
 * Description: this function is used to set an environment variable
 * @env_name: this is the first arg of the function
 * @env_value: this is the second arg of the function
 * @dir: this is the third arg of the function
 */


void set_env(char *env_name, char *env_value, data *dir)
{
	int a;
	char *ve, *ne;

	for (a = 0; dir->var_environ[a]; a++)
	{
		ve = ss_strdup(dir->var_environ[a]);
		ne = ss_strtok(ve, "=");
		if (ss_strcmp(ne, env_name) == 0)
		{
			free(dir->var_environ[a]);
			dir->var_environ[a] = vi_env(ne, env_value);
			free(ve);
			return;
		}
		free(ve);
	}

	dir->var_environ = ss_reallocdp(dir->var_environ, a, sizeof(char *) * (a + 2));
	dir->var_environ[a] = vi_env(env_name, env_value);
	dir->var_environ[a + 1] = NULL;
}




/**
 * ss_setenv - this is the function
 * Description: this function is used to compare
 * the names of environment variables
 * @dir: this is the first arg of the function
 * Return: the result
 */


int ss_setenv(data *dir)
{

	if (dir->args[1] == NULL || dir->args[2] == NULL)
	{
		get_error(dir, -1);
		return (1);
	}

	set_env(dir->args[1], dir->args[2], dir);

	return (1);
}




/**
 * ss_unsetenv - this is the function
 * Description: this function is used to delete a environment variable
 * @dir: this is the first arg of the function
 * Return: the result
 */


int ss_unsetenv(data *dir)
{
	char **re;
	char *ve, *ne;
	int x, y, z;

	if (dir->args[1] == NULL)
	{
		get_error(dir, -1);
		return (1);
	}
	z = -1;
	for (x = 0; dir->var_environ[x]; x++)
	{
		ve = ss_strdup(dir->var_environ[x]);
		ne = ss_strtok(ve, "=");
		if (ss_strcmp(ne, dir->args[1]) == 0)
		{
			z = x;
		}
		free(ve);
	}
	if (z == -1)
	{
		get_error(dir, -1);
		return (1);
	}
	re = malloc(sizeof(char *) * (x));
	for (x = y = 0; dir->var_environ[x]; x++)
	{
		if (x != z)
		{
			re[y] = dir->var_environ[x];
			y++;
		}
	}
	re[y] = NULL;
	free(dir->var_environ[z]);
	free(dir->var_environ);
	dir->var_environ = re;
	return (1);
}
