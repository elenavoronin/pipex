/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 15:09:33 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/27 17:10:40 by mraasvel      ########   odam.nl         */
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
#include "libft/libft.h"
// #include "ft_printf.h"

void	ft_error(char *str, int error)
{
	error = errno;
	perror(str);
	exit(error);
}

char	*get_path(char **cmd, char **envp)
{
	char	**new_paths;
	char	*path;
	int		i;
	char	*cmd_path;

	i = 0;
	cmd_path = NULL;
	path = NULL;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	new_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (*new_paths[i] != '\0')
	{
		path = ft_strjoin(new_paths[i], "/");
		cmd_path = ft_strjoin(path, cmd[0]);
		if (cmd_path == 0)
			ft_error("Strjoin error", errno);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		i++;
	}
	return (NULL);
}

void	*first_child(char **argv, char **envp, int fd[])
{
	int		input;
	char	**cmd;

	cmd = split_cmd(argv[2], ' ');
	close(fd[0]);
	input = open(argv[1], O_RDONLY);
	if (dup2(input, STDIN_FILENO) == -1)
		ft_error("dup2", errno);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("dup2", errno);
	close(fd[1]);
	close(input);
	execve(get_path(cmd, envp), cmd, envp);
	return (NULL);
}

void	*second_child(char **argv, char **envp, int fd[])
{
	int		output;
	char	**cmd;

	cmd = split_cmd(argv[3], ' ');
	close(fd[1]);
	output = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 00700); //change back to 0644
	if (dup2(output, STDOUT_FILENO) == -1)
		ft_error("dup2", errno);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error("dup2", errno);
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
		ft_error("Not enough arguments", 127);
	if (pipe(fd) == -1)
		ft_error("pipe", errno);
	pid1 = fork();
	if (pid1 == -1)
		ft_error("fork 1", errno);
	if (pid1 == 0)
		first_child(argv, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
		ft_error("fork 2", errno);
	if (pid2 == 0)
		second_child(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
