/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:33:06 by ilmahjou          #+#    #+#             */
/*   Updated: 2024/11/24 20:02:23 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		--i;
	}
	if (s[0] == (char)c)
		return ((char *)s);
	return (NULL);
}
/* #include <stdio.h>
int main()
{
	char str[] = "ilsyass";
	int c = 'a';
	printf("%s\n", ft_strrchr(str, c));
	printf("%s", strrchr(str, c));
}*/
