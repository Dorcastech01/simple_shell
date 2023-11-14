#include "main.h"




/**
 * cd_parent - this is the function
 * Description: this function is used to change directory
 * to the parent directory
 * @dir: this is the arg of the function
 */


void cd_parent(data *dir)
{
	char pwd[PATH_MAX];
	char *d, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = ss_strdup(pwd);
	set_env("OLDPWD", cp_pwd, dir);
	d = dir->args[1];
	if (ss_strcmp(".", d) == 0)
	{
		set_env("PWD", cp_pwd, dir);
		free(cp_pwd);
		return;
	}
	if (ss_strcmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_string(cp_strtok_pwd);
	cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = ss_strtok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("PWD", cp_strtok_pwd, dir);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", dir);
	}
	dir->stats = 0;
	free(cp_pwd);
}




/**
 * cd_cmd - this is the function
 * Description: this function is used to change into a given directory
 * @dir: this is the arg of the function
 */


void cd_cmd(data *dir)
{
	char pwd[PATH_MAX];
	char *d, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	d = dir->args[1];
	if (chdir(d) == -1)
	{
		get_error(dir, 2);
		return;
	}

	cp_pwd = ss_strdup(pwd);
	set_env("OLDPWD", cp_pwd, dir);

	cp_dir = ss_strdup(d);
	set_env("PWD", cp_dir, dir);

	free(cp_pwd);
	free(cp_dir);

	dir->stats = 0;

	chdir(d);
}




/**
 * cd_prev - this is the function
 * Description: this function is used to change into the
 * previous known directory
 * @dir: this is the arg of the function
 */


void cd_prev(data *dir)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = ss_strdup(pwd);

	p_oldpwd = ss_getenv("OLDPWD", dir->var_environ);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = ss_strdup(p_oldpwd);

	set_env("OLDPWD", cp_pwd, dir);

	if (chdir(cp_oldpwd) == -1)
		set_env("PWD", cp_pwd, dir);
	else
		set_env("PWD", cp_oldpwd, dir);

	p_pwd = ss_getenv("PWD", dir->var_environ);

	write(STDOUT_FILENO, p_pwd, ss_strlen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	dir->stats = 0;

	chdir(p_pwd);
}




/**
 * cd_home - this is the function
 * Description: this function is used to change into the home directory
 * @dir: this is the arg for the function
 */


void cd_home(data *dir)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = ss_strdup(pwd);

	home = ss_getenv("HOME", dir->var_environ);

	if (home == NULL)
	{
		set_env("OLDPWD", p_pwd, dir);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		get_error(dir, 2);
		free(p_pwd);
		return;
	}

	set_env("OLDPWD", p_pwd, dir);
	set_env("PWD", home, dir);
	free(p_pwd);
	dir->stats = 0;
}




/**
 * cd_f - this is the function
 * Description: this function is used to change the current directory
 * @dir: this is the arg of the function
 * Return: the result
 */


int cd_f(data *dir)
{
	char *d;
	int ishome, ishome2, isddash;

	d = dir->args[1];

	if (d != NULL)
	{
		ishome = ss_strcmp("$HOME", dir);
		ishome2 = ss_strcmp("~", dir);
		isddash = ss_strcmp("--", dir);
	}

	if (d == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_home(dir);
		return (1);
	}

	if (ss_strcmp("-", d) == 0)
	{
		cd_prev(dir);
		return (1);
	}

	if (ss_strcmp(".", d) == 0 || ss_strcmp("..", d) == 0)
	{
		cd_parent(dir);
		return (1);
	}

	cd_cmd(dir);

	return (1);
}
