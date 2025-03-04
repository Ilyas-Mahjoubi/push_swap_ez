/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:19:45 by ilmahjou          #+#    #+#             */
/*   Updated: 2024/11/22 23:29:51 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		ptr[--n] = c;
	}
	return (s = ptr);
}
/*#include <stdio.h>
int main()
{
	char str[50];
	char c = 'c';
	int n = 5;
	ft_memset(str, c, n);
	printf("%s", str);
}*/
