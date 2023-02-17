/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 12:21:54 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/17 17:18:08 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// "../../usr/bin"
// #include "pipex.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
// #include "/Users/evoronin/Documents/libft/libft.h"
// #include "/Users/evoronin/Documents/printf/ft_printf.h"

//use env to find PATH= row, split the directories by : 
// split the commands args by -
// add command to directory (plus the flag)
// go through all possible directory combos

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

char	*find_path(char *str, char *needle, size_t len)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	if (str[size] == '\0')
		return (needle);
	while (i < len && needle[i] != '\0')
	{
		if (needle[i + size] == str[size])
		{
			while (str[size] != '\0' && needle[i + size] == str[size]
				&& (i + size) < len && needle[i + size] != '\0')
					size++;
			if (size == (size_t)ft_strlen(str))
				return (&needle[i]);
		}
		size = 0;
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char	*envp;

	printf("%s", find_path(envp, "PATH=", sizeof("PATH=")));
	return (0);
}