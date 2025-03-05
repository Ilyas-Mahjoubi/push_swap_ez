/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:40:09 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/03/05 13:07:33 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

static int	operations(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(a, 1);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(b, 1);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(a, b, 1);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(a, 1);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(b, 1);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(a, b, 1);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(a, 1);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(b, 1);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(a, b, 1);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(a, b, 1);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(b, a, 1);
	else
		return (write(2, "Error\n", 6), 0);
	return (1);
}

int	output(t_stack *a, t_stack *b)
{
	if (!b && stack_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

static void	init_from_split(t_stack **a, char **av)
{
	int		i;
	char	**args;

	args = ft_split(av[1], ' ');
	if (!args)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	while (args[i])
		i++;
	if (i == 0)
	{
		free_args(args, i);
		write(2, "Error\n", 6);
		exit(1);
	}
	init_stack_a(a, args, 1);
	free_args(args, i);
}

int	process_operations(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!operations(line, a, b))
		{
			free(line);
			free_stack(a);
			free_stack(b);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		init_from_split(&a, argv);
	else
		init_stack_a(&a, argv + 1, 0);
	if (!process_operations(&a, &b))
		return (1);
	return (output(a, b));
}
