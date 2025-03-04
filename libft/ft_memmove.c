/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:37:38 by ilmahjou          #+#    #+#             */
/*   Updated: 2024/11/24 20:08:02 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dest;
	if (!dest && !src)
		return (NULL);
	else if (!n)
		return (dest);
	if (d > s)
	{
		while (n-- > 0)
		{
			d[n] = s[n];
		}
	}
	else
	{
		ft_memcpy(d, s, n);
	}
	return (dest);
}

/*#include <stdio.h>
int main()
{
	{
		char s[] = "Hello";
		char d[10] = {0};

		memmove(d, s, 5);
		printf("%s\n", d);

	}
	{
		char s[] = "Hello";
		char d[10] = {0};

		ft_memmove(d, s, 5);
		printf("%s\n", d);
	}
}
#include <stdio.h>

#include <string.h>

int main()
{
	{

		char

		sr[] = "ciaoooooo";

		//char des [5];

		char *d;

		//des = sr - 3;

		d = ft_memmove (sr + 5, sr, 5);

		printf("%s\n", d);

		printf("%s\n", sr);

	}

	{

		char sr1[] = "ciaoooooo";

		//char des1[5];

		char *d1;

		d1 = memmove (sr1 + 5, sr1, 5);

		printf("%s\n", d1);

		printf("%s", sr1);

	}
}*/
