/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:32:22 by ilmahjou          #+#    #+#             */
/*   Updated: 2024/11/24 19:43:40 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (s != NULL && *s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}
/* int	main(void)
{
	char *str = "hello";
	ft_putstr_fd(str, 1);
} */
