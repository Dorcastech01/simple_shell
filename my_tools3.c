#include "main.h"

/**
 * ss_strrev - this is a function
 * Description: this function is used to reverse a given string
 * @str: this is the arg of the function
 */


void ss_strrev(char *str)
{
	int k = 0, a, b;
	char *src_str, x;

	while (k >= 0)
	{
		if (str[k] == '\0')
			break;
		k++;
	}
	src_str = str;

	for (a = 0; a < (k - 1); a++)
	{
		for (b = a + 1; b > 0; b--)
		{
:		x = *(src_str + b);
			*(src_str + b) = *(src_str + (b - 1));
			*(src_str + (b - 1)) = x;
		}
	}
}




/**
 * ss_memcpy - this is a function
 * Description: this function is used to copy information between void pointers
 * @p2: this is the first arg in the function
 * @p1: this is the second arg in the function
 * @p_sz: this is the third arg in the function
 */


void ss_memcpy(void *p2, const void *p1, unsigned int p_sz)
{
	char *abc = (char *)p1;
	char *xyz = (char *)p2;
	unsigned int a;

	for (a = 0; a < p_sz; a++)
		xyz[a] = abc[a];
}





/**
 *
 * ss_realloc - this is the function
 * Description: this function is used to reallocate a memory block
 * @ptr: this is the first arg in the function
 * @sz1: this is the second arg in the function
 * @sz2: this is the third arg in the function
 */


void *ss_realloc(void *ptr, unsigned int sz1, unsigned int sz2)
{
	void *ptr2;

	if (ptr == NULL)
		return (malloc(sz2));

	if (sz2 == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (sz2 == sz1)
		return (ptr);

	ptr2 = malloc(sz2);
	if (ptr2 == NULL)
		return (NULL);

	if (sz2 < sz1)
		ss_memcpy(ptr2, ptr, sz2);
	else
		ss_memcpy(ptr2, ptr, sz1);

	free(ptr);
	return (ptr2);
}





/**
 * ss_reallocptr - this is the function
 * Description: this function is used to reallocate the memory block of a double pointer
 * @ptr: this is the first arg in the function
 * @sz1: this is the second arg in the function
 * @sz2: this is the third arg in the function
 * Return: the pointer to the reallocated memory
 */


char **ss_reallocptr(char **ptr, unsigned int sz1, unsigned int sz2)
{
	char **ptr2;
	unsigned int a;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * sz2));

	if (sz2 == sz1)
		return (ptr);

	ptr2 = malloc(sizeof(char *) * sz2);
	if (ptr2 == NULL)
		return (NULL);

	for (a = 0; a < sz1; a++)
		ptr2[a] = ptr[a];

	free(ptr);

	return (ptr2);
}
