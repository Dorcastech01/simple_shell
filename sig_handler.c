#include "main.h"

/**
 * sig_handler - this is the function
 * Description: this function is used to handle the crtl + c call in prompt
 * @sig: this is the arg in the function
 */


void sig_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
