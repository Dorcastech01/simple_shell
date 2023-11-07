#include "main.h"



/**
 * ss_strcat - this is a function
 * Description: this function is used to concatenate two strings
 * @dest: this is the first arg of the function
 * @src: this is the second arg of the function
 * Return: the concatenated string
 */


char *ss_strcat(char *dest, const char *src)
{
	int a;
	int b;

	for (a = 0; dest[b] != '\0'; a++)
		;

	for (b = 0; src[b] != '\0'; b++)
	{
		dest[a] = src[b];
		a++;
	}

	dest[a] = '\0';
	return (dest);
}




/**
 * ss_strcpy - this is another string function
 * Description: this function is used to copy the string pointed to by the src
 * @dest: this is the first arg of the function
 * @src: this is the second arg of the function
 * Return: the copied string
 */


char *ss_strcpy(char *dest, char *src)
{

	size_t z;

	for (z = 0; src[z] != '\0'; z++)
	{
		dest[z] = src[z];
	}
	dest[z] = '\0';

	return (dest);
}




/**
 * ss_strcmp - this is a function
 * Description: this function is used to compare two strings
 * @str1: this is the first arg of the function
 * @str2: this is the second arg of the function
 * Return: 0
 */


int ss_strcmp(char *str1, char *str2)
{
	int a;

	for (a = 0; str1[a] == str2[a] && str1[a]; a++)
		;

	if (str1[a] > str2[a])
		return (1);
	if (str1[a] < str2[a])
		return (-1);
	return (0);
}




/**
 * ss_strchr - this is a function
 * Description: this function is used to get a character in a given string
 * @str: this is the first arg of the function
 * @ch: this is the second arg of the function
 * Return: the ptr to the character
 */


char *ss_strchr(char *str, char ch)
{
	unsigned int a = 0;

	for (; *(str + a) != '\0'; a++)
		if (*(str + a) == ch)
			return (str + a);
	if (*(str + a) == ch)
		return (str + a);
	return ('\0');
}




/**
 * ss_strspn - this is a function
 * Description: this function is used to get the length of a preceding substring
 * @str: this is the first arg of the function
 * @byts: this is the second arg of the function
 * Return: the number of the bytes
 */
int ss_strspn(char *str, char *byts)
{
	int a, b, bool;

	for (a = 0; *(str + a) != '\0'; a++)
	{
		bool = 1;
		for (b = 0; *(byts + b) != '\0'; b++)
		{
			if (*(str + a) == *(byts + b))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (a);
}
