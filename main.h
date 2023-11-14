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



void cd_parent(data *dir);
void cd_cmd(data *dir);
void cd_prev(data *dir);
void cd_home(data *dir);
int cd_f(data *dir);
int is_cdir(char *path, int *x);
char *ss_which(char *cmd_name, char **var_environ);
int is_exec(data *dir);
int errcmd_check(char *d, data *dir);
int exec_cmdline(data *dir);
void env_help(void);
void setenv_help(void);
void unsetenv_help(void);
void help_entry(void);
void help_exit(void);
int cmpvar_name(const char *name_envvar, const char *name_passed);
char *ss_getenv(const char *envvar_name, char **var_environ);
int ss_env(data *dir);
int char_rep(char *user_input, int x);
int get_synerr(char *user_input, int x, char x_n);
int char_index(char *user_input, int *x);
void syntax_err(data *dir, char *user_input, int x, int err_ctrl);
int error_check(data *dir, char *user_input);
char *join_cderr(data *dir, char *err_msg, char *out_msg, char *cntr);
char *cd_err(data *dir);
char *cmd_notfound(data *dir);
char *exit_sherr(data *dir);
char *getenv_err(data *dir);
int exec_cmds(data *dir);
void get_help(void);
void getalias_help(void);
void getcd_help(void);
op_list *add_op(op_list **head, char op);
void free_op_list(op_list **head);
line_list *add_cmdline(line_list **head, char *cmdline);
void free_linelist(line_list **head);
char *ss_strcat(char *dest, const char *src);
char *ss_strcpy(char *dest, char *src);
int ss_strcmp(char *str1, char *str2);
char *ss_strchr(char *str, char ch);
int ss_strspn(char *str, char *byts);
char *ss_strdup(const char *str);
int ss_strlen(const char *str);
int char_cmp(char str[], const char *delim);
char *ss_strtok(char str[], const char *delim);
int ss_isdigit(const char *str);
void ss_strrev(char *str);
void ss_memcpy(void *p2, const void *p1, unsigned int p_sz);
void *ss_realloc(void *ptr, unsigned int sz1, unsigned int sz2);
char **ss_reallocptr(char **ptr, unsigned int sz1, unsigned int sz2);
char *path_err(data *dir);
char *read_cmd(int *i_eof);
int shell_exit(data *dir);
void sig_handler(int sig);
int num_len(int x);
char *ss_itoa(int x);
int ss_atoi(char *str);
var_list *add_var(var_list **head, int var_len, char *var_val, int val_len);
void free_list_v(var_list **head);



#endif
