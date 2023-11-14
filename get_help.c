#include "main.h"



/**
 * get_help - this is the function
 * Description: this function is used to get the builtin help information
 */


void get_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, ss_strlen(help));
}




/**
 * getalias_help - this is the function
 * Description: this function is used to get the builtin alias help information
 */


void getalias_help(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, ss_strlen(help));
}




/**
 * getcd_help - this is the function
 * Description: this functionis used to get the help information for cd command
 */


void getcd_help(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, ss_strlen(help));
}
