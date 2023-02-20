/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 15:12:46 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/20 16:51:58 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <fcntl.h>
# include "/Users/evoronin/Documents/libft/libft.h"
# include "/Users/evoronin/Documents/printf/ft_printf.h"

// int		main(int argc, char **argv, char **envp);
char	**find_paths(char **envp, char *needle, size_t len);
char	**get_cmd(char *str);
char	*get_path(int argc, char **argv, char **envp);
void	*first_child(int argc, char **argv, char **envp, int fd[]);
int		main(int argc, char **argv, char **envp);
void	*second_child(int argc, char **argv, char **envp, int fd[]);

#endif