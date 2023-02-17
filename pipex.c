/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 15:09:33 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/17 17:16:04 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// "../../usr/bin"
#include "pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <fcntl.h>
// #include "ft_printf.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*find_path(char *envp, char *needle, size_t len)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	if (envp[size] == '\0')
		return (needle);
	while (i < len && needle[i] != '\0')
	{
		if (needle[i + size] == envp[size])
		{
			while (envp[size] != '\0' && needle[i + size] == envp[size]
				&& (i + size) < len && needle[i + size] != '\0')
					size++;
			if (size == (size_t)ft_strlen(envp))
				return (&envp[i]);
		}
		size = 0;
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	input;
	int	output;

	errno = 0;
	if (argc != 5)
	{	
		printf("Not enough arguments");
		return (0);
	}
	input = open("argv[1]", O_RDONLY);
	output = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC);
	if (pipe(fd) == -1)
	{
		printf("PIPE ERROR");
		return (0);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		printf("FORK ERROR");
		return (0);
	}
	if (pid1 == 0)
	{	
		if (dup2(input, STDIN_FILENO) < 0)
			return (0);
		if (dup2(fd[1], STDOUT_FILENO) < 0)
			return (0);
		close(fd[1]);
		close(input);
		execve("ls -l", &argv[2], envp);
	}
	pid2 = fork();
	if (pid2 < 0)
	{
		printf("FORK 2 ERROR");
		return (0);
	}
	if (pid2 == 0) 
	{
		if (dup2(output, STDOUT_FILENO) < 0)
			return (0);
		if (dup2(fd[0], STDIN_FILENO) < 0)
			return (0);
		close(fd[0]);
		close(output);
		execve("wc -l", &argv[4], envp);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	if (errno != 0)
		perror("ERROR");
	return (0);
}
