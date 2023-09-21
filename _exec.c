#include "shell.h"

/**
 * __execute__ - starts execution based command type
 * @varComnd: command variables
 * Return: Nothing
 */
int __execute__(cmand_t varComnd)
{
int status = 0; /**DON'T FORGET TO COME BACK*/
if (is_builtin(varComnd.cmd[0]))
status = exec_builtin(varComnd);
else
status = run_cmd(varComnd);
twodfre(varComnd.cmd);
return (status);
}

/**
 * exec_builtin - __execute__s buitlin command
 * @varComnd: command variables
 * Return: void
 */
int exec_builtin(cmand_t varComnd)
{
int status = 0;
int (*built_command)(cmand_t varComnd);
built_command = get_builtin(varComnd.cmd);
if (built_command == NULL)
{
perror("builtin failed");
varComnd.status = 127;
return (127);
}
else
status = built_command(varComnd);
return (status);
}

/**
 * is_builtin - checks if command is a builtin command
 * @command: first token of command passed
 * Return: 1 if command is a built else 0
 */
int is_builtin(char *command)
{
char *builtins[] = {"cd", "exit", "env", NULL};
int i = 0;

for (; builtins[i] != NULL; i++)
{
if (_strcmp(command, builtins[i]) == 0)
return (1);
}
return (0);
}

/**
 * _prompt - prompts user for commands
 * @varComnd: command variables
 * Return: 0
 */
int _prompt(cmand_t varComnd)
{
char *command = NULL;
size_t n = 0;
ssize_t characters_read;
int status = 0;
/* loop for the shell's prompt */
while (1)
{
write(STDOUT_FILENO, PROMPT, 2);
characters_read = getline(&command, &n, stdin);
/* check if the getline function failed or reached EOF or user use CTRL + D*/
if (characters_read == -1)
{
break;
}
if (_strlen(command) <= 1 || _strspn(command, " \t\n")
== (size_t)_strlen(command) || command[0] == '#')
continue;
/*Tokenize command*/
varComnd.cmd = tokenize(command, DELIMITER);
/* __execute__ the command */
varComnd.cmand_no += 1;
status = __execute__(varComnd);
}
free(command);
return (status);
}

/**
 * main - entry point
 * @ac: number of command line args
 * @argv: array of args
 * @envp: environ var
 * Return: 0 on success, else fail
 */
int main(int ac, char **argv, char **envp)
{
cmand_t varComnd = {0};
char *buffer = NULL;
size_t n = 0;
FILE *stream = stdin;
varComnd.f_name = argv[0];
varComnd.env = envp;
/*checks interactiveness.*/
if (isatty(STDIN_FILENO))
{
if (ac == 2)
{
int accs = access(argv[1], R_OK);

stream = fopen(argv[1], "r");
if (accs != -1 && stream != NULL)
{
varComnd.status = non_interactive(&buffer, &n, stream, varComnd);
fclose(stream);
}
else
{
dprintf(STDERR_FILENO, "%s: 0: Can't open %s\n",
varComnd.f_name, argv[1]);
return (127);
}
}
else
varComnd.status = _prompt(varComnd);
}
/*checks non-interactive*/
else
{
varComnd.status = non_interactive(&buffer, &n, stream, varComnd);
}
return (varComnd.status);
}
