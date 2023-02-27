/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 15:12:46 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/27 17:06:11 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <fcntl.h>
# include "libft/libft.h" //don't forget to change
# include "//home/mraasvel/Desktop/printf/ft_printf.h"

char	*get_path(char **cmd, char **envp);
void	ft_error(char *str, int error);
void	*first_child(char **argv, char **envp, int fd[]);
void	*second_child(char **argv, char **envp, int fd[]);
char	**split_cmd(char const *s, char c);

#endif