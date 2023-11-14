#include "main.h"

/**
 * path_err - this is the function
 * Description: this function is used to show the error message
 * when get_path command is used
 * @dir: the arg in the function
 * Return: the result is the error message
 */
char *path_err(data *dir)
{
	int len;
	char *cntr;
	char *out_msg;

	cntr = ss_itoa(dir->num);
	len = ss_strlen(dir->av[0]) + ss_strlen(cntr);
	len += ss_strlen(dir->args[0]) + 24;
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
	ss_strcat(out_msg, ": Permission denied\n");
	ss_strcat(out_msg, "\0");
	free(cntr);
	return (out_msg);
}
