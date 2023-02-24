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

int	check_comma(const char *s, char c, int i)
{
	while (s[i] && s[i] != c)
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

	while (s[i])
	{
		if (s[i] == 39)
		{
			while (s[i] != 39)
				len++;
		}
		else if (s[i] != 39)
		{
			while (s[i] != c)
				len++;
		}
		i++;
	}
	len++;
	return (len);
}

// count the number of words that will be in the array
static char	ft_countwords(const char *s, char c)
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
			i = check_comma(s, 39, i + 1);
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
			if (s[i] == 39)
			{
				arr[j] = ft_substr(s, i, ft_wordlen(s, c, i));
				i = check_comma(s, 39, i);
			}
			while (s[i] == c)
				i++;
			arr[j] = ft_substr(s, i, ft_wordlen(s, c, i));
			if (!arr[j])
			{
				ft_free(arr, j);
				return (NULL);
			}
			i = i + ft_wordlen(s, c, i);
		}
		j++;
	}
	arr[j] = 0;
	return (arr);
}

int  main(void)
{
	int i;
	char **split;
	i = 0;
	split = split_cmd("awk '{ print }'", ' ');
	while(split[i] != NULL)
	{
		printf("[%d]: %s\n", i, split[i]);
		i++;
	}
	return (0);
}
