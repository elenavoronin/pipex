/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 15:12:46 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/20 18:11:13 by evoronin      ########   odam.nl         */
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

int		main(int argc, char **argv, char **envp);

#endif