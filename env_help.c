#include "main.h"

/**
 * env_help - this is the function
 * Description: this function is used to get the env help information
 */


void env_help(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, help, ss_strlen(help));

}




/**
 * setenv_help - this is the function
 * Description: this function is used to get the setenv help information
 */


void setenv_help(void)
{

	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, help, ss_strlen(help));
}




/**
 * unsetenv_help - this is the function
 * Description: this function is used to get the unsetenv help information
 */


void unsetenv_help(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, help, ss_strlen(help));
}




/**
 * help_entry - this is the function
 * Description: this function is the start point for the help command
 */


void help_entry(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help, ss_strlen(help));
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, ss_strlen(help));
}




/**
 * help_exit - this is the function
 * Description: this function is used to get the exit help information
 */


void help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "Exits the shell with a status of N. If N is ommited, then the exit";
	write(STDOUT_FILENO, help, ss_strlen(help));
	help = "The status is that of the last command executed\n";
	write(STDOUT_FILENO, help, ss_strlen(help));
}
