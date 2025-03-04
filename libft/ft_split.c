/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:46:25 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/19 17:45:05 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freestrs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (word);
}

static char	*ft_stralloc(char *str, char c, int *index)
{
	char	*word;
	int		len;
	int		start;

	while (str[*index] != '\0' && str[*index] == c)
		(*index)++;
	start = *index;
	len = 0;
	while (str[*index] != '\0' && str[*index] != c)
	{
		len++;
		(*index)++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	len = 0;
	while (start < *index)
		word[len++] = str[start++];
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		index;

	if (s == NULL)
		return (NULL);
	j = ft_wordcount((char *)s, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	index = 0;
	while (i < j)
	{
		strs[i] = ft_stralloc((char *)s, c, &index);
		if (strs[i] == NULL)
		{
			ft_freestrs(strs);
			return (NULL);
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
/* #include <stdio.h>

int main(int ac, char **av)
{
	char **dest;
	dest = ft_split(av[1], av[2][0]);
	int i = 0;
	if (ac != 3)
		return 1;
	while (dest[i])
	{
		printf("%s\n", dest[i]);
		free(dest[i]);
		i++;
	}
	free(dest);
	return 0;
} */
/////////////////////////////////////////////
/* #include <stdio.h>

int main(void)
{
	char str[] = "hello!zzzzzzzz";
	char dest = 'z';
	char **result = ft_split(str, dest);
	int i = 0;
	while (result[i] != NULL)
	{
		printf("Token[%d]: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}

	free(result);
	return 0;
} */
