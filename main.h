#ifndef MAIN_H
#define MAIN_H

#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define SHELL_BUFSIZE 1024
#define TOKEN_BUFSIZE 128
#define TOKEN_DELIMITER " \t\r\n\a"


extern char **environ;


/**
 * struct runtym_data - this is the struct for runtime data
 * @av: this is the argument vector
 * @user_input: this is the cmd entered by user
 * @args: this is the tokens of the command line
 * @stats: this is the last status of the shell
 * @cntr: this is the line counter
 * @var_environ: this is the environment variable
 * @pid: this is the process ID of the shell
 */

typedef struct runtym_data
{
	char **av;
	char *user_input;
	char **args;
	int stats;
	int num;
	char **var_environ;
	char *pid;
} data;



/**
 * struct list_s - this is the struct for the singly linked list
 * to store operators
 * @shell_operator: ; | &
 * @next: this is the next node
 */

typedef struct list_s
{
	char shell_operator;
	struct list_s *next;
} op_list;




/**
 * struct list_l - this is the struct for the singly linked list
 * to store command lines
 * @cmd_line: this is the command line
 * @next: this is the next node
 */

typedef struct list_l
{
	char *cmd_line;
	struct list_l *next;
} line_list;





/**
 * struct list_v - this is the struct for the singly linked list
 * to store variables
 * @var_length: this is the length of the variable
 * @var_value: this is the value of the variable
 * @val_length: this is the length of the value
 * @next: this is the next node
 */

typedef struct list_v
{
	int var_length;
	char *var_value;
	int val_length;
	struct list_v *next;
} var_list;





/**
 * struct cmd_builtins - this is the built-in struct for the command args
 * @cmd_name: this is the name of the built-in command
 * @func: this is the data type pointer function
 */

typedef struct cmd_builtins
{
	char *cmd_name;
	int (*func)(data *dir);
} builtins;


#endif
