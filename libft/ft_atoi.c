/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:34:34 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/03/01 18:09:39 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	res;
	int	sgin;
	int	i;

	res = 0;
	sgin = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgin *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10 + (str[i] - '0'));
		i++;
	}
	return (res * sgin);
}
/*#include<stdio.h>
int main ()
{
    char *s;

    s = "92237476746765876848484678466878764";
    printf ("you %d\n", ft_atoi (s));
    printf ("origin  %d\n", atoi (s));
}*/
