/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbres.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:51:52 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/17 14:36:34 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_digit(long nbr, int base, char x_or_X)
{
	int		count;
	char	*symb;

	if (x_or_X == 'X')
		symb = "0123456789ABCDEF";
	else
		symb = "0123456789abcdef";
	if (nbr < 0)
	{
		ft_print_char('-');
		return (ft_print_digit(-nbr, base, x_or_X) + 1);
	}
	else if (nbr < base)
	{
		return (ft_print_char(symb[nbr]));
	}
	else
		count = (ft_print_digit(nbr / base, base, x_or_X));
	return (count + ft_print_digit(nbr % base, base, x_or_X));
}

int	ft_print_u(unsigned int u)
{
	int	count;

	count = 0;
	if (u >= 10)
		count += ft_print_u(u / 10);
	count += ft_print_char(u % 10 + '0');
	return (count);
}

int	ft_print_p(size_t	p)
{
	int		count;
	char	str[25];
	int		i;
	char	*base_char;

	count = 0;
	base_char = "0123456789abcdef";
	i = 0;
	if (p == 0)
	{
		count += ft_print_str("(nil)");
		return (count);
	}
	count += write(1, "0x", 2);
	while (p != 0)
	{
		str[i++] = base_char[p % 16];
		p = p / 16;
	}
	while (i--)
		count += ft_print_char(str[i]);
	return (count);
}
