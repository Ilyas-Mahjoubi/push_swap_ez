/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 01:42:51 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/02/24 01:42:51 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

void sort_three(t_stack **a)
{
	t_stack *biggest_node;

	biggest_node = find_max(*a);
	//ft_printf("biggest node : %d\n", biggest_node->content);

	// Case 1: If the largest number is at the top, rotate
	if (biggest_node == *a)
		ra(a, 0);
	// Case 2: If the largest number is at the second position, reverse rotate
	else if ((*a)->next == biggest_node)
		rra(a, 0);

	// Print the stack after rotation (for debugging purposes)
	//print_stack(*a);

	// After rotating, check the stack for order and swap if necessary
	if ((*a)->content > (*a)->next->content)
	{
		sa(a, 0);
		// Print the stack after swap (for debugging purposes)
		//print_stack(*a);
	}
}

