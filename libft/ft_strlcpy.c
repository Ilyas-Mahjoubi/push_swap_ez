/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:25:21 by ilmahjou          #+#    #+#             */
/*   Updated: 2024/11/28 17:32:54 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
		{
			i++;
		}
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
/* int	main(void)
{
	char	dst[20];
	char	src[] = "Hello, world!";
	size_t	size = 77;

	printf("Original Source: %s\n", src);

	size_t	result = ft_strlcpy(dst, src, size);

	printf("Final Destination: %s\n", dst);
	printf("Length of Source String: %zu\n", result);

	return (0);
} */
