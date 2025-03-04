/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:19:42 by ilmahjou          #+#    #+#             */
/*   Updated: 2024/11/28 17:32:25 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*srt;
	size_t	i;

	i = 0;
	srt = (char *)s;
	while (i < n)
	{
		if ((unsigned char)srt[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
/*  #include <stdio.h>
int main()
{
	 char str[] = "hello world";
	 char *ch = ft_memchr(str, 'l' , 3);

	 printf("%s",(unsigned char*)ch);
	 return 0;
} */
