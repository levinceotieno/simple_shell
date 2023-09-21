#ifndef SHELL_PRINTS_H
#define SHELL_PRINTS_H

/* header files */
#include <stdarg.h>
#include <stdlib.h>

int _puts(char *str, int fd);
int _putchar(char c);
int intprnt(int num);
void random_prnt(int commands_no, char *program_name, char *, char *);
int __printf(int fd, const char *format, ...);

#endif /* SHELL_PRINTS_H */

