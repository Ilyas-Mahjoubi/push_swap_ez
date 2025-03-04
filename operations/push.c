/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 00:49:56 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/02/24 00:49:56 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

static void push(t_stack **dst, t_stack**src)
{
	// If source stack is empty, nothing to push
	if (!*src)
		return ;
	// Save the node we want to push
	t_stack *node = *src;
	// Remove node from source stack
	*src = node->next;
	if (*src)
		(*src)->prev = NULL;
	// Connect node to destination stack
	node->next = *dst;
	node->prev = NULL;
	// Update destination stack
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
