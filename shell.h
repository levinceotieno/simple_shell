#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include "print.h"
#include <limits.h>

/* macros*/
#define PROMPT "$ "
#define DELIMITER " \n"
/* Struct */

/**
 * struct command_var - struct of command variables
 * @cmd: command
 * @cmd_no: command number
 * @status: execution status
 * @prg_name: program name
 * @env: environment variables
 */

typedef struct command_var
{
	char **cmd;
	int cmd_no;
	int status;
	char *prg_name;
	char **env;
} cmd_t;

/**
 * struct builtin_t - this is a structure of funtion pointers for built
 * builtin commands
 * @cmd_n: command name of type char *
 * @cmd: function pointer
 */
typedef struct builtin_t
{
	char *cmd_n;
	int (*cmd)(cmd_t varComnd);
} built_t;

extern char **environ;
/* path*/
char *_which(char *);
int run_cmd(cmd_t);

char **tokenize(char *, const char *);
int is_builtin(char *command);
int exec_builtin(cmd_t);

/*alloc memory*/
void twodfre(char **);
char *_strtok(char *, char *);

/* builtin functions*/
int (*get_builtin(char **))(cmd_t);
int __exit(cmd_t);
int cd_only(cmd_t);
int _isdigit(int);
int _atoi(char *str);

/*string mani*/
int _strlen(char *s);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
int _strcmp(char *, char *);
char *_strdup(char *);
int intprnt(int num);
int _putchar(char c);
int _puts(char *c, int fd);
unsigned int _strspn(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
void join(char *, char *, char *, const char *);

/*Environ funct*/
char *_getenv(char *var);
int _env(cmd_t);
int we_setenv(const char *, const char *, int);
int non_interactive(char **buffer, size_t *n, FILE *file, cmd_t);
int execute(cmd_t);

#endif /* SIMPLE_SHELL */

