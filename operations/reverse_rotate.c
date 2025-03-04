/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:58:08 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/02/28 10:22:31 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **a, int flag)
{
	reverse_rotate(a);
	if (flag == 0)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int flag)
{
	reverse_rotate(b);
	if (flag == 0)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (flag == 0)
		ft_printf("rrr\n");
}
