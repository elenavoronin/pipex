/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 15:09:33 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/16 15:23:16 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// "../../usr/bin"
#include "pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
// #include "ft_printf.h"

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
	output = open(argv[5], O_CREAT, O_WRONLY);
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
		execve("wc -l", &argv[5], envp);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	if (errno != 0)
		perror("ERROR");
	return (0);
}
