/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:04:00 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/03/03 22:36:17 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

void	move_same_direction(t_stack **a, t_stack **b, t_stack *node)
{
	if (node->above_median && node->target_node->above_median)
	{
		while (*a != node && *b != node->target_node)
			rr(a, b, 0);
	}
	else if (!node->above_median && !node->target_node->above_median)
	{
		while (*a != node && *b != node->target_node)
			rrr(a, b, 0);
	}
	set_index(*a);
	set_index(*b);
}

void	finish_rotations(t_stack **stack, t_stack *target, char stack_name)
{
	while (*stack != target)
	{
		if (target->above_median)
		{
			if (stack_name == 'a')
				ra(stack, 0);
			else
				rb(stack, 0);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

void	turk_algo(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, 0);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, 0);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		prepare_stack_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		prepare_stack_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_to_top(a);
}
