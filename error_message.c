#include "main.h"

/**
 * join_cderr - this is the function
 * Description: this function is used to function join the
 * change directory error message
 * @dir: first arg
 * @err_msg: second arg
 * @out_msg: third arg
 * @cntr: fourth arg
 * Return: the result is the error message
 */
char *join_cderr(data *dir, char *err_msg, char *out_msg, char *cntr)
{
	char *x_flag;

	ss_strcpy(out_msg, dir->av[0]);
	ss_strcat(out_msg, ": ");
	ss_strcat(out_msg, cntr);
	ss_strcat(out_msg, ": ");
	ss_strcat(out_msg, dir->args[0]);
	ss_strcat(out_msg, err_msg);
	if (dir->args[1][0] == '-')
	{
		x_flag = malloc(3);
		x_flag[0] = '-';
		x_flag[1] = dir->args[1][1];
		x_flag[2] = '\0';
		ss_strcat(out_msg, x_flag);
		free(x_flag);
	}
	else
	{
		ss_strcat(out_msg, dir->args[1]);
	}

	ss_strcat(out_msg, "\n");
	ss_strcat(out_msg, "\0");
	return (out_ms)g;
}




/**
 * cd_err - this is the function
 * Description: this function is used to show the change directory
 * error message when the get cd command is used
 * @dir: arg for the function
 * Return: the result is the error message
 */
char *cd_err(data *dir)
{
	int len, len_id;
	char *out_msg, *cntr, *err_msg;

	cntr = aux_itoa(dir->num);
	if (dir->args[1][0] == '-')
	{
		err_msg = ": wrong choice ";
		len_id = 2;
	}
	else
	{
		err_msg = ": unable to cd into ";
		len_id = ss_strlen(dir->args[1]);
	}

	len = ss_strlen(dir->av[0]) + ss_strlen(dir->args[0]);
	len += ss_strlen(cntr) + ss_strlen(err_msg) + len_id + 5;
	out_msg = malloc(sizeof(char) * (len + 1));

	if (out_msg == 0)
	{
		free(cntr);
		return (NULL);
	}

	out_msg = join_cderr(dir, err_msg, out_msg, cntr);

	free(cntr);

	return (out_msg);
}

/**
 * cmd_notfound - this is the function
 * Description: this function is used to show an error message
 * when the command entered is not found
 * @dir: the arg in the function
 * Return: the result is an error message
 */
char *cmd_notfound(data *dir)
{
	int len;
	char *out_msg;
	char *cntr;

	cntr = aux_itoa(dir->num);
	len = ss_strlen(dir->av[0]) + ss_strlen(cntr);
	len += ss_strlen(dir->args[0]) + 16;
	out_msg = malloc(sizeof(char) * (len + 1));
	if (out_msg == 0)
	{
		free(out_msg);
		free(cntr);
		return (NULL);
	}
	ss_strcpy(out_msg, dir->av[0]);
	ss_strcat(out_msg, ": ");
	ss_strcat(out_msg, cntr);
	ss_strcat(out_msg, ": ");
	ss_strcat(out_msg, dir->args[0]);
	ss_strcat(out_msg, ": command not found\n");
	ss_strcat(out_msg, "\0");
	free(cntr);
	return (out_msg);
}



/**
 * exit_sherr - this is the function
 * Description: this function is used to show the exit error message
 * when get_exit command is used
 * @dir: the arg in the function
 * Return: the result is the error message
 */
char *exit_sherr(data *dir)
{
	int len;
	char *out_msg;
	char *cntr;

	cntr = aux_itoa(dir->num);
	len = ss_strlen(dir->av[0]) + ss_strlen(cntr);
	len += ss_strlen(dir->args[0]) + ss_strlen(dir->args[1]) + 23;
	out_msg = malloc(sizeof(char) * (len + 1));
	if (out_msg == 0)
	{
		free(cntr);
		return (NULL);
	}
	ss_strcpy(out_msg, dir->av[0]);
	ss_strcat(out_msg, ": ");
	ss_strcat(out_msg, cntr);
	ss_strcat(out_msg, ": ");
	ss_strcat(out_msg, dir->args[0]);
	ss_strcat(out_msg, ": Unaccepted input: ");
	ss_strcat(out_msg, dir->args[1]);
	ss_strcat(out_msg, "\n\0");
	free(cntr);

	return (out_msg);
}


/**
 * getenv_err - this is the function
 * Description: this function is used to show the error message
 * when the get_env command is used
 * @dir: the arg int he function
 * Return: the result is the error message
 */
char *getenv_err(data *dir)
{
	int len;
	char *out_msg;
	char *cntr;
	char *err_msg;

	cntr = aux_itoa(dir->num);
	err_msg = ": cannot add/remove this from environment\n";
	len = ss_strlen(dir->av[0]) + ss_strlen(cntr);
	len += ss_strlen(dir->args[0]) + ss_strlen(err_msg) + 4;
	out_msg = malloc(sizeof(char) * (len + 1));
	if (out_msg == 0)
	{
		free(out_msg);
		free(cntr);
		return (NULL);
	}

	ss_strcpy(out_msg, dir->av[0]);
	ss_strcat(out_msg, ": ");
	ss_strcat(out_msg, cntr);
	ss_strcat(out_msg, ": ");
	ss_strcat(out_msg, dir->args[0]);
	ss_strcat(out_msg, err_msg);
	ss_strcat(out_msg, "\0");
	free(cntr);

	return (out_msg);
}
