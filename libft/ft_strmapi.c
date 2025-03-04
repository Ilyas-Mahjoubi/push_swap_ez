/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:48:15 by ilmahjou          #+#    #+#             */
/*   Updated: 2024/11/22 23:29:30 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*#include <stdio.h>
char to_upper(unsigned int i, char c)
{
    (void)i; // Suppress unused variable warning
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

char to_lower(unsigned int i, char c)
{
    (void)i;
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}
int main()
{
    char *str1;
    char *str2;

    str1 = ft_strmapi("jil", to_upper);
    str2 = ft_strmapi("JIL", to_lower);

    if (str1 && str2)
    {
        printf("Upper: %s\n", str1);
        printf("Lower: %s\n", str2);
    }
    free(str1);
    free(str2);

    return 0;
} */
