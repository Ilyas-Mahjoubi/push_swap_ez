/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:17:10 by ilmahjou          #+#    #+#             */
/*   Updated: 2024/11/18 15:23:47 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*int main()
{
	printf("%d", ft_isalnum('a'));
	printf("%d", ft_isalnum('A'));
	printf("%d", ft_isalnum(' '));
	printf("%d", ft_isalnum('#'));
	printf("%d", ft_isalnum('8'));
}*/
