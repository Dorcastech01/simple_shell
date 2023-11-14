#include "main.h"




/**
 * check_var - this is the function
 * Description: this function is used to check if the user input is
 * an env variable
 * @head: this is the first arg of the function
 * @inp_str: this is the second arg of the function
 * @d_struc: this is the third arg of the function
 */


void check_var(var_list **head, char *inp_str, data *d_struc)
{
	int r, c, a, l;
	char **ss_envr;

	ss_envr = d_struc->var_environ;
	for (r = 0; ss_envr[r]; r++)
	{
		for (a = 1, c = 0; ss_envr[r][c]; c++)
		{
			if (ss_envr[r][c] == '=')
			{
				l = ss_strlen(ss_envr[r] + c + 1);
				add_var(head, a, ss_envr[r] + c + 1, l);
				return;
			}

			if (inp_str[a] == ss_envr[r][c])
				a++;
			else
				break;
		}
	}

	for (a = 0; inp_str[a]; a++)
	{
		if (inp_str[a] == ' ' || inp_str[a] == '\t' || inp_str[a] == ';' || inp_str[a] == '\n')
			break;
	}

	add_var(head, a, NULL, 0);
}




/**
 * check_dollar - this is the function
 * Description: this function is used to check if the typed variable is $$/$?
 * @head: first arg
 * @inp_str: second arg
 * @status: third arg 
 * @d_struc: fourth arg 
 */


int check_dollar(var_list **head, char *inp_str, char *status, data *d_struc)
{
	int a, x, y;

	x = ss_strlen(status);
	y = ss_strlen(d_struc->pid);

	for (a = 0; inp_str[a]; a++)
	{
		if (inp_str[a] == '$')
		{
			if (inp_str[a + 1] == '?')
				add_var(head, 2, status, x), a++;
			else if (inp_str[a + 1] == '$')
				add_var(head, 2, d_struc->pid, y), a++;
			else if (inp_str[a + 1] == '\n')
				add_var(head, 0, NULL, 0);
			else if (inp_str[a + 1] == '\0')
				add_var(head, 0, NULL, 0);
			else if (inp_str[a + 1] == ' ')
				add_var(head, 0, NULL, 0);
			else if (inp_str[a + 1] == '\t')
				add_var(head, 0, NULL, 0);
			else if (inp_str[a + 1] == ';')
				add_var(head, 0, NULL, 0);
			else
				check_var(head, inp_str + a, d_struc);
		}
	}

	return (a);
}




/**
 * replace_str - this is the function
 * Description: this function is used to replace string with variables
 * @head: first arg
 * @inp_str: second arg
 * @inp2: third arg
 * @len2: fourth arg
 * Return: the result
 */


char *replace_str(var_list **head, char *inp_str, char *inp2, int len2)
{
	var_list *i;
	int x, y, z;

	i = *head;
	for (y = x = 0; x < len2; x++)
	{
		if (inp_str[y] == '$')
		{
			if (!(i->var_length) && !(i->val_length))
			{
				inp2[a] = inp_str[y];
				y++;
			}
			else if (i->var_length && !(i->val_length))
			{
				for (z = 0; z < i->var_length; z++)
					y++;
				x--;
			}
			else
			{
				for (z = 0; z < i->val_length; z++)
				{
					inp2[x] = i->var_value[z];
					x++;
				}
				y += (i->var_length);
				x--;
			}
			i = i->next;
		}
		else
		{
			inp2[x] = inp_str[y];
			y++;
		}
	}

	return (inp2);
}





/**
 * replace_var - this is the function
 * Description: this function is used to replace string in vars
 * @inp_str: first arg
 * @dir: second arg
 * Return: the result
 */


char *replace_var(char *inp_str, data *dir)
{
	var_list *head, *i;
	char *status, *inp2;
	int olen, nlen;

	status = ss_itoa(dir->stats);
	head = NULL;

	olen = check_dollar(&head, inp_str, status, dir);

	if (head == NULL)
	{
		free(status);
		return (inp_str);
	}

	i = head;
	nlen = 0;

	while (i != NULL)
	{
		nlen += (i->val_length - i->var_length);
		i = i->next;
	}

	nlen += olen;

	inp2 = malloc(sizeof(char) * (nlen + 1));
	inp2[nlen] = '\0';

	inp2 = replace_str(&head, inp_str, inp2, nlen);

	free(inp_str);
	free(status);
	free_list_v(&head);

	return (inp2);
}
