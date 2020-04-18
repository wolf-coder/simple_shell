#include "holberton.h"

/**
 *main- A simple shell Program  providing an interface that
 *allows you to interact with the kernel of an operating system.
 *
 *@ac:Number of arguments.
 *@av:A Null terminating array of arguments.
 *Return:Success.
*/
int main(int ac, char **av)
{
	pid_t frk, child_PID;
	char **argv = malloc(2 * sizeof(char *));
	int interactive = isatty(STDIN_FILENO), last_exit = 0, Line = 1, status;

	argv[0] = NULL;
	while (1)
	{
		argv[0] = get_input(&argv, interactive, &last_exit);
		if (argv[0] != NULL)
		{
			argv[1] = NULL;
			frk = fork();
			if (frk == -1)
			{
				perror("Fork failure");
				exit(EXIT_FAILURE);
			}
			if (frk == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					Throw_Error(argv[0], Line, av[0], interactive);
					free(argv[0]);
					free(argv);
					exit(127);
				}
			} else
			{
				child_PID = wait(&status);
				Line += 1;
				free(argv[0]);
				last_exit = WEXITSTATUS(status);
			}
		} else
			free(argv[0]);
	}
	(void)ac;
	(void)child_PID;
	return (0);
}
