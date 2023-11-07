#include "main.h"

/**
 * ss_strdup - this is a function
 * Description: this function is used to duplicate a string in the heap memory
 * @str: this is the first arg in the function
 * Return: the duplicated string
 */


char *ss_strdup(const char *str)
{
	char *str2;
	size_t str_length;

	str_length = ss_strlen(str);
	str2 = malloc(sizeof(char) * (str_length + 1));
	if (str2 == NULL)
		return (NULL);
	ss_memcpy(str2, str, str_length + 1);
	return (str2);
}



/**
 * ss_strlen - this is the function
 * Description: this function is used to get the length of a given string
 * @str: this is the first arg in the function
 * Return: 0
 */


int ss_strlen(const char *str)
{
	int str_length;

	for (str_length = 0; str[str_length] != 0; str_length++)
	{
	}
	return (str_length);
}





/**
 * char_cmp - this is a function
 * Description: this function is used to compare the
 * characters of a given string
 * @str: this is the first arg in the function
 * @delim: this is the second arg in the function
 * Return: 1 if there is a match and 0 if there is not a match
 */

int char_cmp(char str[], const char *delim)
{
	unsigned int a, b, c;

	for (a = 0, c = 0; str[a]; a++)
	{
		for (b = 0; delim[b]; b++)
		{
			if (str[a] == delim[b])
			{
				c++;
				break;
			}
		}
	}
	if (a == c)
		return (1);
	return (0);
}





/**
 * ss_strtok - this is a function
 * Description: this function is used to split a string by given delimiter(s)
 * @str: this is the first arg in the function
 * @delim: this is the second arg in the function
 * Return: the splitted string
 */


char *ss_strtok(char str[], const char *delim)
{
	static char *div, *rear;
	char *front;
	unsigned int a, bool;

	if (str != NULL)
	{
		if (char_cmp(str, delim))
			return (NULL);
		div = str
		a = ss_strlen(str);
		rear = &str[a];
	}
	front = div;
	if (front == rear)
		return (NULL);

	for (bool = 0; *div; div++)
	{
		if (div != front)
			if (*div && *(div - 1) == '\0')
				break;
		for (a = 0; delim[a]; a++)
		{
			if (*div == delim[a])
			{
				*div = '\0';
				if (div == front)
					front++;
				break;
			}
		}
		if (bool == 0 && *div)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (front);
}





/**
 * ss_isdigit - this is the function
 * Description: this function is used to check if the input is a number
 * @str: this is the first arg in the function
 * Return: 1 if true 0 if false
 */
int ss_isdigit(const char *str)
{
	unsigned int a;

	for (a = 0; str[a]; a++)
	{
		if (str[a] < 48 || str[a] > 57)
			return (0);
	}
	return (1);
}
