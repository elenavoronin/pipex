/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 13:23:25 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/20 15:48:18 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] != '\0' && str1[i] == str2[i] && i < n - 1)
	{
			i++;
	}
	return (str1[i] - str2[i]);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char			*s1;
// 	char			*s2;
// 	size_t			i;
// 	size_t			size;

// 	s1 = (char *)s;
// 	size = ft_strlen(s1);
// 	if (s1 == NULL)
// 		return (NULL);
// 	if (len >= size)
// 		s2 = (char *)malloc((size + 1) * sizeof(char));
// 	else
// 		s2 = (char *)malloc((len + 1) * sizeof(char));
// 	if (!s2)
// 		return (NULL);
// 	i = 0;
// 	while (len > 0 && s1 && start <= size)
// 	{
// 		s2[i] = s1[start];
// 		len--;
// 		start++;
// 		i++;
// 	}
// 	s2[i] = 0;
// 	return (s2);
// }
