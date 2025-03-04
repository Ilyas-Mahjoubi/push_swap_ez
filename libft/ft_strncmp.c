/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:35:57 by ilmahjou          #+#    #+#             */
/*   Updated: 2024/11/23 17:42:27 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/* #include <stdio.h>
int main()
{

    unsigned int n = 6;
    char str1[] = "ilyaS", str2[] = "ilyas";
    int result;

  // comparing strings str1 and str2
    result = ft_strncmp(str1, str2, n);
    printf("ft_strcmp(str1, str2, n) = %d\n", result);

  // comparing strings str1 and str3
    result = strncmp(NULL, str2, n);
    printf("ft_strcmp real(str1, str2, n) = %d\n", result);

    return 0;
} */
