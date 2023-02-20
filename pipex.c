/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 15:09:33 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/20 18:21:53 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// "../../usr/bin"
#include "pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <stdlib.h>
// #include "ft_printf.h"

char	*get_path(char **cmd, char **envp)
{
	char	*path;
	char	**new_paths;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path = ft_substr(envp[i], i - 2, ft_strlen(envp[i]) - 5);
	new_paths = ft_split(path, ':');
	i = 0;
	while (new_paths[i] != NULL)
	{	
		if (access(ft_strjoin(new_paths[i], cmd[0]), R_OK | W_OK | X_OK) == 0)
			return (ft_strjoin(new_paths[i], cmd[0]));
		i++;
	}
	return (NULL);
}

void	*first_child(char **argv, char **envp, int fd[])
{
	int		input;
	char	**cmd;

	cmd = ft_split(argv[2], ' ');
	close(fd[0]);
	input = open(argv[1], O_RDONLY);
	if (dup2(input, STDIN_FILENO) == -1)
		return (NULL);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (NULL);
	close(fd[1]);
	close(input);
	execve(get_path(cmd, envp), cmd, envp);
	return (NULL);
}

void	*second_child(char **argv, char **envp, int fd[])
{
	int		output;
	char	**cmd;

	cmd = ft_split(argv[2], ' ');
	close(fd[1]);
	output = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (dup2(output, STDOUT_FILENO) == -1)
		return (NULL);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		return (NULL);
	close(fd[0]);
	close(output);
	execve(get_path(cmd, envp), cmd, envp);
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc != 5)
	{	
		printf("Not enough arguments");
		exit(0);
	}
	if (pipe(fd) == -1)
	{
		perror("ERROR");
		exit(0);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("ERROR");
		exit(0);
	}
	if (pid1 == 0)
		first_child(argv, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("ERROR");
		exit(0);
	}
	if (pid2 == 0)
		second_child(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	char	**path;
// 	int i = 0;

// 	path = ft_split(find_path(envp, "PATH=", 5), ':');
// 	while (path[i] != '\0')
// 	{
// 		printf("%s\n", path[i]);
// 		i++;
// 	}
// 	return (0);
// }