/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 12:21:54 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/17 14:31:59 by evoronin      ########   odam.nl         */
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

// int	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*src;
	char		*find;
	size_t		i;
	size_t		size;

	src = (char *)haystack;
	find = (char *)needle;
	i = 0;
	size = 0;
	if (find[size] == '\0')
		return (src);
	while (i < len && src[i] != '\0')
	{
		if (src[i + size] == find[size])
		{
			while (find[size] != '\0' && src[i + size] == find[size]
				&& (i + size) < len && src[i + size] != '\0')
					size++;
			if (size == (size_t)ft_strlen(find))
				return (&src[i]);
		}
		size = 0;
		i++;
	}
	return (NULL);
}


char	*find_path(char **envp)
{
	char	*find;
	size_t	size;
	int		fd;

	fd = open(path, O_RDONLY);
	size = sizeof("PATH=");
	find = ft_strnstr(path, "PATH=", size);
	close(fd);
	return (*&find);
}

int	main(void)
{
	int		fd;
	int 	size;
	char 	*path = "/usr/bin/env";
	char	*env;

	size = sizeof("PATH=");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return(0);
	env = malloc(sizeof(fd));
	if (!env)
		return(0);
	while(get_next_line(fd))
	{
		env = get_next_line(fd);
		if (!env)
		{
			free(env);
			return (0);
		}
	}
	
	printf("%s", ft_strnstr(env, "PATH=", size));
	close(fd);
	free(env);
	return (0);
	// printf("%s", env);
	// printf("%s\n", find_path(path));
	// return (0);
}