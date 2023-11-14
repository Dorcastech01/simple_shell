#include "main.h"




/**
 * free_datastruct - this is the function
 * Description: this function is used to free data structure
 * @dir: this is the arg of the function
 */


void free_datastruct(data *dir)
{
	unsigned int a;

	for (a = 0; dir->var_environ[a]; a++)
	{
		free(dir->var_environ[a]);
	}

	free(dir->var_environ);
	free(dir->pid);
}




/**
 * set_datastruct - this is the function
 * Description: this function is used to initialize a data structure
 * @dir: this is the first arg of the function
 * @av: this is the second arg of the function
 */


void set_datastruct(data *dir, char **av)
{
	unsigned int a;

	dir->av = av;
	dir->user_input = NULL;
	dir->args = NULL;
	dir->stats = 0;
	dir->num = 1;

	for (a = 0; environ[a]; a++)
		;

	dir->var_environ = malloc(sizeof(char *) * (a + 1));

	for (a = 0; environ[a]; a++)
	{
		dir->var_environ[a] = ss_strdup(environ[a]);
	}

	dir->var_environ[a] = NULL;
	dir->pid = ss_itoa(getpid());
}




/**
 * main - this is the main function
 * Description: this is the start point
 * @ac: this is the first arg of the function
 * @av: this is the second arg of the function
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	data dir;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_datastruct(&dir, av);
	shell_loop(&dir);
	free_datastruct(&dir);
	if (dir.stats < 0)
		return (255);
	return (dir.stats);
}
