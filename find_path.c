/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 12:21:54 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/17 12:23:43 by evoronin      ########   odam.nl         */
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

char *find_path(char **envp)
{
	int i = 0;
	int j = 0;

	while(envp[i] != '\0')
	{
		if envp[i][j] = "PATH="
	}
}
