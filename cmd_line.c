#include "main.h"




/**
 * is_cdir - this is the function
 * Description: this function is used to check
 * ":" if it is in the current directory
 * @path: this is the first arg of the function
 * @x: this is the second arg of the function
 * Return: the result
 */


int is_cdir(char *path, int *x)
{
	if (path[*x] == ':')
		return (1);

	while (path[*x] != ':' && path[*x])
	{
		*x += 1;
	}

	if (path[*x])
		*x += 1;

	return (0);
}




/**
 * ss_which - this is the function
 * Description: this function is used to locate a command
 * @cmd_name: this is the first arg of the function
 * @var_environ: this is the second arg of the function
 * Return: the result
 */


char *ss_which(char *cmd_name, char **var_environ)
{
	char *path, *ptr_path, *token_path, *d;
	int d_len, cmd_len, x;
	struct stat st;

	path = ss_getenv("PATH", var_environ);
	if (path)
	{
		ptr_path = ss_strdup(path);
		cmd_len = ss_strlen(cmd_name);
		token_path = ss_strtok(ptr_path, ":");
		x = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &x))
				if (stat(cmd_name, &st) == 0)
					return (cmd_name);
			d_len = ss_strlen(token_path);
			d = malloc(d_len + cmd_len + 2);
			ss_strcpy(d, token_path);
			ss_strcat(d, "/");
			ss_strcat(d, cmd_name);
			ss_strcat(d, "\0");
			if (stat(d, &st) == 0)
			{
				free(ptr_path);
				return (d);
			}
			free(d);
			token_path = ss_strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd_name, &st) == 0)
			return (cmd_name);
		return (NULL);
	}
	if (cmd_name[0] == '/')
		if (stat(cmd_name, &st) == 0)
			return (cmd_name);
	return (NULL);
}




/**
 * is_exec - this is the function
 * Description: this function is used to check if a command is an executable
 * @dir: this is the arg for the function
 * Return: the result
 */


int is_exec(data *dir)
{
	struct stat st;
	int x;
	char *user_input;

	user_input = dir->args[0];
	for (x = 0; user_input[x]; x++)
	{
		if (user_input[x] == '.')
		{
			if (user_input[x + 1] == '.')
				return (0);
			if (user_input[x + 1] == '/')
				continue;
			else
				break;
		}
		else if (user_input[x] == '/' && x != 0)
		{
			if (user_input[x + 1] == '.')
				continue;
			x++;
			break;
		}
		else
			break;
	}
	if (x == 0)
		return (0);

	if (stat(user_input + x, &st) == 0)
	{
		return (x);
	}
	get_error(dir, 127);
	return (-1);
}




/**
 * errcmd_check - this is the function
 * Description: this function is used to verify if a user
 * have access permission
 * @d: this is the first arg of the function
 * @dir: this is the second arg of the function
 * Return: the result
 */


int errcmd_check(char *d, data *dir)
{
	if (d == NULL)
	{
		get_error(dir, 127);
		return (1);
	}

	if (ss_strcmp(dir->args[0], d) != 0)
	{
		if (access(d, X_OK) == -1)
		{
			get_error(dir, 126);
			free(d);
			return (1);
		}
		free(d);
	}
	else
	{
		if (access(dir->args[0], X_OK) == -1)
		{
			get_error(dir, 126);
			return (1);
		}
	}

	return (0);
}




/**
 * exec_cmdline - this is the function
 * Description: this function is used to execute the command line
 * @dir: this is the arg in the function
 * Return: the result
 */


int exec_cmdline(data *dir)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *d;
	(void) wpd;

	exec = is_exec(dir);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		d = ss_which(dir->args[0], dir->var_environ);
		if (errcmd_check(d, dir) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			d = ss_which(dir->args[0], dir->var_environ);
		else
			d = dir->args[0];
		execve(d + exec, dir->args, dir->var_environ);
	}
	else if (pd < 0)
	{
		perror(dir->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	dir->stats = state / 256;
	return (1);
}
