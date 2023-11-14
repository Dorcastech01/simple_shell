#include "main.h"




/**
 * error_f - this is the function
 * Description: this function is used to call the error
 * according the builtin
 * @dir: this is the firsta arg of the function
 * @err_val: this is the second arg of the function
 * Return: the result
 */


int error_f(data *dir, int err_val)
{
	char *error;

	switch (err_val)
	{
	case -1:
		error = getenv_err(dir);
		break;
	case 126:
		error = path_err(dir);
		break;
	case 127:
		error = error_not_found(datash);
		break;
	case 2:
		if (ss_strcmp("exit", dir->args[0]) == 0)
			error = exit_sherr(dir);
		else if (ss_strcmp("cd", dir->args[0]) == 0)
			error = cd_err(dir);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, ss_strlen(error));
		free(error);
	}

	dir->stats = err_val;
	return (err_val);
}
