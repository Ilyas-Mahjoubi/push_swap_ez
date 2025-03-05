/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 00:49:56 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/03/01 11:05:55 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*node;

	node = *src;
	if (!*src)
		return ;
	*src = node->next;
	if (*src)
		(*src)->prev = NULL;
	node->next = *dst;
	node->prev = NULL;
	if (*dst)
		(*dst)->prev = node;
	*dst = node;
}

void	pa(t_stack **a, t_stack **b, int flag)
{
	push(a, b);
	if (flag == 0)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a, int flag)
{
	push(b, a);
	if (flag == 0)
		ft_printf("pb\n");
}
