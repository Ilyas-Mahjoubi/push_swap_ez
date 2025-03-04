/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:47:21 by ilmahjou          #+#    #+#             */
/*   Updated: 2024/11/28 17:32:33 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	actual_len;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	actual_len = s_len - start;
	if (actual_len > len)
		actual_len = len;
	p = (char *)malloc(sizeof(char) * (actual_len + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s + start, actual_len + 1);
	return (p);
}

/* #include <stdio.h>
int main()
{
	char *s = "ilyas";
	char *sub = ft_substr(s, 3, 6);
	printf("%s", sub);
	free(sub);
} */
