/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:07:24 by ilmahjou          #+#    #+#             */
/*   Updated: 2024/11/28 21:54:38 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	b;
	void	*p;

	if (nmemb == 0 || size == 0 || (nmemb > SIZE_MAX / size))
		return (malloc(0));
	b = nmemb * size;
	p = malloc(b);
	if (p == NULL)
		return (NULL);
	else
		ft_bzero(p, b);
	return (p);
}
/* #include<stdio.h>

int main()
{
	ssize_t	n = 20;
	size_t s = sizeof(int);

	int *arr = (int *)ft_calloc(n, s);

	for (size_t i = 0; i < n; i++)
	{
		printf("arr[%zu] = %d\n", i, arr[i]);
	}
	free(arr);
} */
