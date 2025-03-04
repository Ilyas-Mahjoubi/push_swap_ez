/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_a_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:08:56 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/02/24 11:55:58 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	mid;

	i = 0;
	mid = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->above_median = (i <= mid);
		stack = stack->next;
		i++;
	}
}

void	find_target_in_b(t_stack *a, t_stack *b)
{
	t_stack	*b_iter;
	t_stack	*target;
	long	closest_smaller;

	while (a)
	{
		closest_smaller = LONG_MIN;
		b_iter = b;
		while (b_iter)
		{
			if (b_iter->content < a->content
				&& b_iter->content > closest_smaller)
			{
				closest_smaller = b_iter->content;
				target = b_iter;
			}
			b_iter = b_iter->next;
		}
		if (closest_smaller == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		if (a->above_median)
			a->push_cost = a->index;
		else
			a->push_cost = len_a - a->index;
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - a->target_node->index;
		a = a->next;
	}
}

void	mark_cheapest_node(t_stack *stack)
{
	t_stack	*cheapest;
	long	min_cost;

	cheapest = NULL;
	min_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < min_cost)
		{
			min_cost = stack->push_cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	if (cheapest)
		cheapest->cheapest = 1;
}

void	prepare_stack_a(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	find_target_in_b(a, b);
	calculate_cost(a, b);
	mark_cheapest_node(a);
}
