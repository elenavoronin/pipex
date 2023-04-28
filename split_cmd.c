/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_cmd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 14:31:19 by evoronin      #+#    #+#                 */
/*   Updated: 2023/04/28 16:39:08 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "pipex.h"

static int	check_comma(const char *s, int i)
{
	while (s[i] && (s[i] != 39 || s[i] != 34))
	{
		i++;
	}
	return (i);
}

// count the length of the words
static int	ft_wordlen(const char *s, char c, int i)
{
	int		len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

// count the number of words that will be in the array
static int	ft_countwords(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == 39 || s[i] == 34)
			i = check_comma(s, i + 2);
		if ((s[i + 1] != '\0' && s[i] == c && s[i + 1] != c))
			count++;
		i++;
	}
	return (count);
}

char	**make_arr(char const *s, char c, char **arr, int j)
{
	int	i;

	i = 0;
	while (j < ft_countwords(s, c))
	{
		{
			while (s[i] == c)
					i++;
			if (s[i] == 39 || s[i] == 34)
			{
				arr[j] = ft_substr(s, i + 1, check_length(s, i) - 2);
				i = i + check_length(s, i) + 1;
			}
			else
				arr[j] = ft_substr(s, i, ft_wordlen(s, c, i));
			if (!arr[j])
				return (ft_free(arr, j), NULL);
			i = i + ft_wordlen(s, c, i);
		}
		j++;
	}
	arr[j] = 0;
	return (arr);
}

char	**split_cmd(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = make_arr(s, c, arr, j);
	return (arr);
}

// int  main(void)
// {
// 	int i;
// 	char **split;
// 	i = 0;
// 	split = split_cmd("/usr/cat", ' ');
// 	while(split[i] != NULL)
// 	{
// 		printf("[%d]: %s\n", i, split[i]);
// 		i++;
// 	}
// 	return (0);
// }
