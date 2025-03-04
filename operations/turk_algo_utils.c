/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:06:54 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/03/04 16:39:11 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = set_cheapest(*a);
	move_same_direction(a, b, cheapest_node);
	finish_rotations(a, cheapest_node, 'a');
	finish_rotations(b, cheapest_node->target_node, 'b');
	pb(b, a, 0);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	finish_rotations(a, (*b)->target_node, 'a');
	pa(a, b, 0);
}

void	min_to_top(t_stack **a)
{
	while ((*a)->content != find_min(*a)->content)
	{
		if (find_min(*a)->above_median)
			ra(a, 0);
		else
			rra(a, 0);
	}
}
