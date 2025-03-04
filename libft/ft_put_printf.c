/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:01:36 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/17 14:36:38 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_format(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		print_len += ft_print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_digit((long)va_arg(args, int), 10, 'x');
	else if (format == 'x')
		print_len += ft_print_digit((long)va_arg(args, unsigned int), 16, 'x');
	else if (format == 'X')
		print_len += ft_print_digit((long)va_arg(args, unsigned int), 16, 'X');
	else if (format == '%')
		print_len += ft_print_char('%');
	else if (format == 'u')
		print_len += ft_print_u(va_arg(args, unsigned int));
	else if (format == 'p')
		print_len += ft_print_p((long long)va_arg(args, void *));
	else
		print_len += write (1, &format, 1);
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_print_format(args, str[i + 1]);
			i++;
		}
		else
			print_len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
/* #include <stdio.h>
int main()
{
	ft_printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "Hello, World!");
	ft_printf("Decimal: %d\n", 12345);
	ft_printf("Integer: %i\n", -12345);
	ft_printf("Hexadecimal (lowercase): %x\n", 255);
	ft_printf("Hexadecimal (uppercase): %X\n", -255);
	ft_printf("Percentage: %%\n");
	ft_printf("Unsigned: %u\n", -2147483647);
	int x = 42;
	ft_printf("Pointer: %p\n", &x);
	return 0;
} */
