#include "main.h"



/**
 * num_len - this is the function
 * Description: this function is used to get the lenght of a number
 * @x: the arg of the function
 * Return: the result
 */


int num_len(int x)
{
	unsigned int y;
	int len = 1;

	if (x < 0)
	{
		len++;
		y = x * -1;
	}
	else
	{
		y = x;
	}
	while (y > 9)
	{
		len++;
		y = y / 10;
	}

	return (len);
}




/**
 * ss_itoa - this is ths function
 * Description: this function is used to convert int to a string
 * @x: this is the arg of the function
 * Return: the result
 */


char *ss_itoa(int x)
{
	unsigned int y;
	int len = num_len(x);
	char *buff;

	buff = malloc(sizeof(char) * (len + 1));
	if (buff == 0)
		return (NULL);

	*(buff + len) = '\0';

	if (x < 0)
	{
		y = x * -1;
		buff[0] = '-';
	}
	else
	{
		y = x;
	}

	len--;
	do {
		*(buff + len) = (y % 10) + '0';
		y = y / 10;
		len--;
	}
	while (y > 0)
		;
	return (buff);
}




/**
 * ss_atoi - this is the function
 * Description: this function is used to convert a string to an int
 * @str: this is the arg of the function
 * Return: integer.
 */
int ss_atoi(char *str)
{
	unsigned int str_count = 0, str_size = 0, k = 0, l = 1, m = 1, a;

	while (*(str + str_count) != '\0')
	{
		if (str_size > 0 && (*(str + str_count) < '0' || *(str + str_count) > '9'))
			break;

		if (*(str + str_count) == '-')
			l *= -1;

		if ((*(str + str_count) >= '0') && (*(str + str_count) <= '9'))
		{
			if (str_size > 0)
				m *= 10;
			str_size++;
		}
		str_count++;
	}

	for (a = str_count - str_size; a < str_count; a++)
	{
		k = k + ((*(str + a) - 48) * m);
		m /= 10;
	}
	return (k * l);
}
