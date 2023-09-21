#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

/* to read&write buffer */
#define READ_BUF_SIZE 1024
#define PRINTBUFF_SIZE 1024
#define FLSHBUFF -1

/* other def includes */
#define RTINCMD 0
#define CMDOR_ 1
#define CMD_AND 2
#define CMDCHAINN_ 3
/* converting number function */
#define LOWERCASE_	1
#define UNSIGNED__	2
/* use system getline */
#define GET_LINE 0
#define STRTOKEN 0

#define HIST_FILE	".simple_shell_history"
#define MAXHISTOR	4096

extern char **environ;

/**
 * struct string_lst - singly linked list
 * @num: num field
 * @str: string
 * @next: points to the next node
 */
typedef struct string_lst
{
	int num;
	char *str;
	struct string_lst *next;
} list_t;

/**
 * struct infoGetway - Contains function arguments
 * for uniform function pointer prototype
 * @arg: String containing arguments from getline
 * @argv: Array of strings generated from arg
 * @path: String path for the current command
 * @argc: Argument count
 * @line_count: Error count
 * @err_num: Error code for exit() calls
 * @linecount_flag: Indicates if this line of input should be counted
 * @fname: Program filename
 * @env: Linked list local copy of environ
 * @environ: Custom modified copy of environ from LL env
 * @history: History node
 * @alias: Alias node
 * @env_changed: Indicates if environ was changed
 * @status: Return status of the last executed command
 * @cmd_buffa: Address of pointer to cmd_buffa, used for chaining
 * @buffaferType: CMD_type (||, &&, ;)
 * @readfd: File descriptor from which to read line input
 * @histcount: History line number count
 */
typedef struct infoGetway
{
	char *arg;
	char **argv;
	char *fname;
	int readfd;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *path;
	char **cmd_buffa;
	int env_changed;
	int status;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int buffaferType;
	int argc;
	int histcount;
} info_t;

#define INITIALDATA \
{NULL, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, \
0, 0, 0}

/**
 * struct builtin - contains a builtin str & related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} buitinStruc_ble;


/* loop.c */
int _ex(info_t *, char **);
int find_builtin(info_t *);
void cfind(info_t *);
void cfork(info_t *);

/* parse.c */
int is_cmd(info_t *, char *);
char *dupcateChar(char *, int, int);
char *fi_ndpath(info_t *, char *, char *);

/* loop_ex.c */
int loop_ex(char **);

/* exit.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int fd_puts(char *str, int fd);

/* string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *beginWth(const char *, const char *);
char *_strcat(char *, char *);

/* string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* token.c */
char **tokstr(char *, char *);
char **tokstr2(char *, char);

/* realloc.c */
char *set_mem(char *, char, unsigned int);
void _let_free(char **);
void *__rrealloC(void *, unsigned int, unsigned int);

/* mem.c */
int we_free(void **);

/* atoi.c */
int active(info_t *);
int _isdelim(char, char *);
int is_alpha(int);
int __atoi_(char *);

/* errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* history.c */
char *histopast_file(info_t *info);
int past_write(info_t *info);
int readH(info_t *info);
int creatH(info_t *info, char *buffa, int linecount);
int renumH(info_t *info);

/* builtin.c */
int check_exit(info_t *);
int check_cd(info_t *);
int check_help(info_t *);

/* builtin1.c */
int past_histori(info_t *);
int theAlias(info_t *);

/* getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* getinfo.c */
void informedEx(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* environ.c */
char *_getenv(info_t *, const char *);
int __env(info_t *);
int __setenv(info_t *);
int __unsetevv(info_t *);
int __envList(info_t *);

/* vars.c */
int tag_c(info_t *, char *, size_t *);
void chaintag(info_t *, char *, size_t *, size_t, size_t);
int alternativeAlias(info_t *);
int alternativeVar(info_t *);
int alternativeStr(char **, char *);

/* getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *plusNode_end(list_t **, const char *, int);
size_t listStr_print(const list_t *);

/* list3.c */
int remov_nodeAtIndex(list_t **, unsigned int);
void free_list(list_t **);

/* lists1.c */
size_t list_len(const list_t *);
char **str_listed(list_t *);
size_t print_list(const list_t *);

/* list4.c */
list_t *node_beginWth(list_t *, char *, char);
ssize_t nodeIndex(list_t *, list_t *);

#endif /* SIMPLE_SHELL */

