/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:26:20 by ilmahjou          #+#    #+#             */
/*   Updated: 2024/11/28 16:13:55 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/* #include <fcntl.h>
int	main(void)
{
	int fd = open("text4.txt", O_RDWR | O_CREAT);
	printf("%d", fd);
	ft_putchar_fd('F', fd);
	ft_putchar_fd('f', fd);
	close(fd);
} */
