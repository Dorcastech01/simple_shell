#include "main.h"

/**
 * add_op - this is a function
 * Description: this function is used to add a seperator
 * @head: this is the first arg of the function
 * @op: this is the second arg of the function
 * Return: the result
 */


op_list *add_op(op_list **head, char op)
{
	op_list *rec, *tmp;

	rec = malloc(sizeof(op_list));
	if (rec == NULL)
		return (NULL);

	rec->shell_operator = op;
	rec->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = rec;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = rec;
	}

	return (*head);
}




/**
 * free_op_list - this is a function
 * Description: this function is used to free the op_list
 * @head: this is the arg of the function
 */


void free_op_list(op_list **head)
{
	op_list *tmp;
	op_list *frec;

	if (head != NULL)
	{
		frec = *head;
		while ((tmp = frec) != NULL)
		{
			frec = frec->next;
			free(tmp);
		}
		*head = NULL;
	}
}




/**
 * add_cmdline - this is a function
 * Description: this function is used to add a command line to the end
 * of a line_list
 * @head: this is the first arg of the function
 * @cmdline: this is the second arg of the function
 * Return: the result
 */


line_list *add_cmdline(line_list **head, char *cmdline)
{
	line_list *rec, *tmp;

	rec = malloc(sizeof(line_list));
	if (rec == NULL)
		return (NULL);

	rec->line = cmd_line;
	rec->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = rec;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = rec;
	}

	return (*head);
}





/**
 * free_linelist - this is a function
 * Description: this function is used to free a line_list
 * @head: this is the arg of the function
 */


void free_linelist(line_list **head)
{
	line_list *tmp;
	line_list *frec;

	if (head != NULL)
	{
		frec = *head;
		while ((tmp = frec) != NULL)
		{
			frec = frec->next;
			free(tmp);
		}
		*head = NULL;
	}
}
