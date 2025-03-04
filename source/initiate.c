/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:01:41 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/02/24 13:19:16 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_to_stack(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (0);
	node->content = nbr;
	node->next = NULL;
	node->cheapest = 0;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = find_last(*stack);
		last->next = node;
		node->prev = last;
	}
	return (1);
}

static int	validate_and_add(t_stack **a, char *str)
{
	long	nbr;

	if (check_arg_nbr(str))
		return (0);
	nbr = ft_atoi(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	if (duplicates(*a, (int)nbr))
		return (0);
	return (add_to_stack(a, (int)nbr));
}

void	init_stack_a(t_stack **a, char **av, int free_needed)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!validate_and_add(a, av[i]))
		{
			if (free_needed)
				free_errors(a, av);
			else
				free_errors(a, NULL);
		}
		i++;
	}
}

t_stack	*set_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
