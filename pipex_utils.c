/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/14 17:37:05 by evoronin      #+#    #+#                 */
/*   Updated: 2023/04/26 17:02:45 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"

void	ft_error(char *str, int error)
{
	perror(str);
	if (error == 0)
		exit(0);
	if (error == 127)
	{
		ft_putstr_fd("Command not found", 2);
		exit(127);
	}
	else
		exit(error);
}

// free memory for split_cmd
void	ft_free(char **arr, int j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free (arr);
}

int	check_length(const char *s, int i)
{
	int	len;

	len = 1;
	i++;
	while (s[i] && (s[i] != 39)) //  || s[i] != 34)
	{
		len++;
		i++;
	}
	if (s[i] == 39 || s[i] == 34)
		len++;
	return (len);
}
