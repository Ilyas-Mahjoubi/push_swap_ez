/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:32:14 by ilmahjou          #+#    #+#             */
/*   Updated: 2024/11/19 14:06:48 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*#include <stdio.h>
int main()
{
    char str[50] = "ciao"; 
    int n = 5;           
    ft_bzero(str, n);
    printf("ft_bzero: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", str[i]);
    }
    printf("\n");

    bzero(str, n);
    
    printf("bzero: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", str[i]); 
    }
    printf("\n");

    return 0;
}*/
