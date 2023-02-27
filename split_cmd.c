#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "pipex.h"

// free memory
static void	ft_free(char **arr, int j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free (arr);
}

static int	check_length(const char *s, char c, int i)
{
	int	len;

	len = 1;
	i++;
	while (s[i] && s[i] != 39)
	{
		len++;
		i++;
	}
	return (len);
}

static int	check_comma(const char *s, char c, int i)
{
	while (s[i] && s[i] != 39)
	{
		i++;
	}
	if (s[i] == c)
		i++;
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
	count = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == 39)
			i = check_comma(s, 39, i + 2);
		if ((s[i + 1] != '\0' && s[i] == c && s[i + 1] != c))
			count++;
		i++;
	}
	return (count);
}

char	**split_cmd(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;


	j = 0;
	i = 0;
	arr = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (j < ft_countwords(s, c))
	{
		{
			while (s[i] == c)
					i++;
			if (s[i] == 39)
			{
				arr[j] = ft_substr(s, i, check_length(s, c, i));
				i = i + check_length(s, c, i) + 1;
			}
			else
				arr[j] = ft_substr(s, i, ft_wordlen(s, c, i));
			if (!arr[j])
			{
				ft_free(arr, j);
				return (NULL);
			}
			i = i + ft_wordlen(s, c, i);
			printf("[3]i is: %d\n", i);
		}
		j++;
	}
	arr[j] = 0;
	return (arr);
}

// int  main(void)
// {
// 	int i;
// 	char **split;
// 	i = 0;
// 	split = split_cmd("awk '{ print }'", 32);
// 	while(split[i] != NULL)
// 	{
// 		printf("[%d]: %s\n", i, split[i]);
// 		i++;
// 	}
// 	return (0);
// }
