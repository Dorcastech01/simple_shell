#include "main.h"




/**
 * char_rep - this is the function
 * Description: this function is used to count the
 * repetitions of a char
 * @user_input: thi is the first arg of the function
 * @x: this is the second arg of the function
 * Return: the result
 */


int char_rep(char *user_input, int x)
{
	if (*(user_input - 1) == *user_input)
		return (char_rep(user_input - 1, x + 1));

	return (x);
}




/**
 * get_synerr - this is the function
 * Description: this function is used to find the syntax errors
 * @user_input: this is the first arg of the function
 * @x: this is the second arg of the function
 * @x_n: this is the third arg of the function
 * Return: the result
 */


int get_synerr(char *user_input, int x, char x_n)
{
	int x_count;

	x_count = 0;
	if (*user_input == '\0')
		return (0);

	if (*user_input == ' ' || *user_input == '\t')
		return (get_synerr(user_input + 1, x + 1, x_n));

	if (*user_input == ';')
		if (x_n == '|' || x_n == '&' || x_n == ';')
			return (x);

	if (*user_input == '|')
	{
		if (x_n == ';' || x_n == '&')
			return (x);

		if (x_n == '|')
		{
			x_count = char_rep(user_input, 0);
			if (x_count == 0 || x_count > 1)
				return (x);
		}
	}

	if (*user_input == '&')
	{
		if (x_n == ';' || x_n == '|')
			return (x);

		if (x_n == '&')
		{
			x_count = char_rep(user_input, 0);
			if (x_count == 0 || x_count > 1)
				return (x);
		}
	}

	return (get_synerr(user_input + 1, x + 1, *user_input));
}




/**
 * char_index - this is the function
 * Description: this function is used to find the index of the first char
 * @user_input: this is the first arg of the function
 * @x: this is the second arg of the function
 * Return: the result
 */


int char_index(char *user_input, int *x)
{

	for (*x = 0; user_input[*x]; *x += 1)
	{
		if (user_input[*x] == ' ' || user_input[*x] == '\t')
			continue;

		if (user_input[*x] == ';' || user_input[*x] == '|' || user_input[*x] == '&')
			return (-1);

		break;
	}

	return (0);
}




/**
 * syntax_err - this is the function
 * Description: this function is used to print a syntax error when it occurs
 * @dir: this is the first arg of the function
 * @user_input: this is the second arg of the function
 * @x: this is the third arg of the function
 * @err_ctrl: this is the fourth arg of the function
 */


void syntax_err(data *dir, char *user_input, int x, int err_ctrl)
{
	char *err_msg, *err_msg2, *err_msg3, *err, *err_counter;
	int len;

	if (user_input[x] == ';')
	{
		if (err_ctrl == 0)
			err_msg = (user_input[x + 1] == ';' ? ";;" : ";");
		else
			err_msg = (user_input[x - 1] == ';' ? ";;" : ";");
	}

	if (user_input[x] == '|')
		err_msg = (user_input[x + 1] == '|' ? "||" : "|");

	if (user_input[x] == '&')
		err_msg = (user_input[x + 1] == '&' ? "&&" : "&");

	err_msg2 = ": Syntax error: \"";
	err_msg3 = "\" unexpected\n";
	err_counter = ss_itoa(dir->num);
	len = ss_strlen(dir->av[0]) + ss_strlen(err_counter);
	len += ss_strlen(err_msg) + ss_strlen(err_msg2) + ss_strlen(err_msg3) + 2;

	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err_counter);
		return;
	}
	ss_strcpy(err, dir->av[0]);
	ss_strcat(err, ": ");
	ss_strcat(err, err_counter);
	ss_strcat(err, err_msg2);
	ss_strcat(err, err_msg);
	ss_strcat(err, err_msg3);
	ss_strcat(err, "\0");

	write(STDERR_FILENO, err, len);
	free(err);
	free(err_counter);
}




/**
 * error_check - this is the function
 * Description: this function is used to find and print syntax error
 * @dir: this is the first arg of the function
 * @user_input: this is the second arg of the function
 * Return: the result
 */


int error_check(data *dir, char *user_input)
{
	int start = 0;
	int f_char = 0;
	int x = 0;

	f_char = char_index(user_input, &start);
	if (f_char == -1)
	{
		syntax_err(dir, user_input, start, 0);
		return (1);
	}

	x = get_synerr(user_input + start, 0, *(user_input + start));
	if (x != 0)
	{
		syntax_err(dir, user_input, start + x, 1);
		return (1);
	}

	return (0);
}
