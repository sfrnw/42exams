#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void ft_putstr_fd2(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
		while(*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
}

void ft_fatal_error(void)
{
	ft_putstr_fd2("error: fatal", NULL);
	exit(1);
}

void ft_execute(char **argv, int i, int tmp_fd, char **env)
{
	argv[i] = NULL;
	if (dup2(tmp_fd, 0) == -1)
		ft_fatal_error();
	close(tmp_fd);
	execve(argv[0], argv, env);
	ft_putstr_fd2("error:cannot execute ", argv[0]);
	exit(1);
}

int main (int argc, char **argv, char **env)
{
	int i = 0;
	int tmp_fd;
	pid_t pid;
	int fd[2];

	(void)argc;
	tmp_fd = dup(0);
	while (argv[1] && argv[i+1])
	{
		argv = &argv[i+1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				ft_putstr_fd2("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) != 0)
				ft_putstr_fd2("error: cd: cannot change directory to ", argv[1]);
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			pid = fork();
			if (pid == -1)
				ft_fatal_error();
			if (pid == 0)
				ft_execute(argv, i, tmp_fd, env);
			else
			{
				close(tmp_fd);
				while (waitpid(-1, NULL, 2) != -1)
					;
				tmp_fd = dup(0);
				if (tmp_fd == -1)
					ft_fatal_error();
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			if (pipe(fd) == -1)
				ft_fatal_error();
			pid = fork();
			if (pid == -1)
				ft_fatal_error();
			if (pid == 0)
			{
				if (dup2(fd[1], 1) == -1)
					ft_fatal_error();
				close(fd[0]);
				close(fd[1]);
				ft_execute(argv, i, tmp_fd, env);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
	}
	close(tmp_fd);
	return(0);
}
