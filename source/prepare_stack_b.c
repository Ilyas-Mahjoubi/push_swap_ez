/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_b_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:19:25 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/02/24 12:11:39 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_in_a(t_stack *a, t_stack *b)
{
	t_stack	*a_iter;
	t_stack	*target;
	long	closest_bigger;

	while (b)
	{
		closest_bigger = LONG_MAX;
		a_iter = a;
		while (a_iter)
		{
			if (a_iter->content > b->content
				&& a_iter->content < closest_bigger)
			{
				closest_bigger = a_iter->content;
				target = a_iter;
			}
			a_iter = a_iter->next;
		}
		if (closest_bigger == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	prepare_stack_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	find_target_in_a(a, b);
}
