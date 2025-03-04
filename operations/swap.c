/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 01:17:06 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/02/24 01:17:06 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

static void swap(t_stack **head)
{
	t_stack *first;
	t_stack *second;

	if (!*head || !(*head)->next)
		return;

	first = *head;
	second = (*head)->next;
	// Update first node connections
	first->next = second->next;
	first->prev = second;
	// Update second node connections
	second->next = first;
	second->prev = NULL;
	// Update next node's prev pointer if it exists
	if (first->next)
		first->next->prev = first;
	// Update head to point to new first node
	*head = second;
}

void	sa(t_stack **a, int flag)
{
	swap(a);
	if (flag == 0)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int flag)
{
	swap(b);
	if (flag == 0)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, int flag)
{
	swap(a);
	swap(b);
	if (flag == 0)
		ft_printf("ss\n");
}
