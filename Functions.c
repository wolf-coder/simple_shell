#include "holberton.h"
/**
 *get_input- Function that affect argv[0] from stdin.
 *
 *@argv: Poniter to A double Pointer.
 *@interactive: isatty result: interactive/Non-interactive mode.
 *@last_exit: last exit status .
 *Return:Pointer.
 */
char *get_input(char ***argv, int interactive, int *last_exit)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t  nread;
	const char delim[] = " \n";

	if (interactive)
		_puts("#cisfun$ ");
	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		if (interactive)
			_putchar('\n');
		free(line);
		free(*argv);
		exit(*last_exit);
	}
	if (strcmp(line, "exit\n") == 0)
	{
		free(line);
		free(*argv);
		exit(*last_exit);
	}

	*argv[0] = _strdup(strtok(line, delim));
	free(line);
	return (*argv[0]);
}
/**
 *Throw_Error- Function that throw error to stderr
 *
 *@command: The command that caused the Error.
 *@Line: Line Number.
 *@pr_Name: Shell executable Name.
 *@interactive: interpreter Mode ( isatty ).
 *Return: Void.
 */
void Throw_Error(char *command, int Line, char *pr_Name, int interactive)
{
	char *Err_msg = NULL, *Part1 = NULL, *Part2 = NULL;
	char *Part3 = NULL, *Part4 = NULL;

	Part1 = str_concat(pr_Name, ": ");

	if (!interactive)
	{
		Part2 = str_concat("line ", _itoi(Line));
		Part3 = str_concat(Part1, Part2);
		Part4 = str_concat(Part3, ": ");
		Err_msg = str_concat(Part4, command);
		perror(Err_msg);
		free(Part2);
		free(Part3);
		free(Part4);
	} else
	{
		Err_msg = str_concat(Part1, command);
		perror(Err_msg);
	}
	free(Err_msg);
	free(Part1);
}
