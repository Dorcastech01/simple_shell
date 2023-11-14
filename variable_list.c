#include "main.h"





/**
 * add_var - this is the function
 * Description: this function is used to add a variable
 * @head: this is the first arg of the function
 * @var_len: this is the second arg of the function
 * @var_val: this is the third arg of the function
 * @val_len: this is the fourth arg of the function
 * Return: the result
 */


var_list *add_var(var_list **head, int var_len, char *var_val, int val_len)
{
	var_list *rec, *tmp;

	rec = malloc(sizeof(var_list));
	if (rec == NULL)
		return (NULL);

	rec->var_length = var_len;
	rec->var_value = var_val;
	rec->val_length = val_len;

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
 * free_list_v - this is a function
 * Description: this function is used to free a variable list
 * @head: this is the arg of the function
 */


void free_list_v(var_list **head)
{
	var_list *tmp;
	var_list *frec;

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
