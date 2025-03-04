/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:17:06 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/02/27 10:05:11 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
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
