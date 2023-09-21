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
 * struct varableCmd - struct of command variables
 * @cmd: command
 * @cmand_no: command number
 * @status: execution status
 * @f_name: program name
 * @env: environment variables
 */

typedef struct varableCmd
{
	char **cmd;
	int cmand_no;
	int status;
	char *f_name;
	char **env;
} cmand_t;

/**
 * struct builtin_t - this is a struct of funtion pointers for built
 * builtin commands
 * @cmand_n: command name of type char *
 * @cmd: function pointer
 */
typedef struct builtin_t
{
	char *cmand_n;
	int (*cmd)(cmand_t varComnd);
} built_t;

extern char **environ;
/* path*/
char *_which(char *);
int run_cmd(cmand_t);

char **tokenize(char *, const char *);
int is_builtin(char *command);
int exec_builtin(cmand_t);

/*alloc memory*/
void twodfre(char **);
char *_strtok(char *, char *);

/* builtin functions*/
int (*get_builtin(char **))(cmand_t);
int __exit(cmand_t);
int cd_only(cmand_t);
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
void __enter(char *, char *, char *, const char *);

/*environ funct*/
char *_getenv(char *var);
int _env(cmand_t);
int we_setenv(const char *, const char *, int);
int non_interactive(char **buffer, size_t *n, FILE *file, cmand_t);
int __execute__(cmand_t);

#endif /* SIMPLE_SHELL */

