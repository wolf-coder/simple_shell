#ifndef SHELL_HEADER
#define SHELL_HEADER

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int _putchar(char c);
void _puts(char *str);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
char *get_input(char ***argv, int interactive, int *last_exit);
void Throw_Error(char *command, int Line, char *pr_Name, int interactive);
char *_itoi(long long num);
#endif
