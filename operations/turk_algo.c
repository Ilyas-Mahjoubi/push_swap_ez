/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:04:00 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/03/03 23:04:00 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

void move_same_direction(t_stack **a, t_stack **b, t_stack *node)
{
    if (node->above_median && node->target_node->above_median) // If both elements are above median, rotate both stacks together
    {
        while (*a != node && *b != node->target_node)
            rr(a, b, 0);
    }
    else if (!node->above_median && !node->target_node->above_median) // If both elements are below median, reverse rotate both stacks together
    {
        while (*a != node && *b != node->target_node)
            rrr(a, b, 0);
    }
    // Update indices after rotations
    set_index(*a);
    set_index(*b);
}

void finish_rotations(t_stack **stack, t_stack *target, char stack_name)
{
    // Complete remaining rotations to get target to top
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

void move_a_to_b(t_stack **a, t_stack **b)
{
    // Find cheapest node to move
    t_stack *cheapest_node = set_cheapest(*a);
    
    // First do paired rotations when possible
    move_same_direction(a, b, cheapest_node);
    
    // Finish remaining rotations for each stack
    finish_rotations(a, cheapest_node, 'a');
    finish_rotations(b, cheapest_node->target_node, 'b');
    
    // Push from a to b
    pb(b, a, 0);
}

void move_b_to_a(t_stack **a, t_stack **b)
{
    // Position a to receive the element
    finish_rotations(a, (*b)->target_node, 'a');
    
    // Push from b to a
    pa(a, b, 0);
}

void sort_stacks(t_stack **a, t_stack **b)
{
    int len_a = stack_len(*a);
    
    // Push until 3 elements remain in stack a
    if (len_a-- > 3 && !stack_sorted(*a))
        pb(b, a, 0); // Push first element to get b started
    if (len_a-- > 3 && !stack_sorted(*a))
        pb(b, a, 0);
    while (len_a-- > 3 && !stack_sorted(*a))
    {
        prepare_stack_a(*a, *b);  // Calculate costs and targets
        move_a_to_b(a, b);        // Move cheapest element to b
    }
    
    // Sort the remaining 3 elements in stack a
    sort_three(a);
    
    // Move all elements back to a in sorted order
    while (*b)
    {
        prepare_stack_b(*a, *b);  // Update targets
        move_b_to_a(a, b);        // Move elements back
    }
    // Put minimum on top to finish
    set_index(*a);
    while ((*a)->content != find_min(*a)->content)
    {
        if (find_min(*a)->above_median)
            ra(a, 0);
        else
            rra(a, 0);
    }
}