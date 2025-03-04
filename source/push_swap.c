/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:23:57 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/03/02 18:55:03 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_arguments(t_stack **a, int argc, char **argv, char ***args)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		*args = ft_split(argv[1], ' ');
		if (!(*args))
			return (1);
		init_stack_a(a, *args, 1);
	}
	else
		init_stack_a(a, argv + 1, 0);
	return (0);
}

static int	execute_sort(t_stack **a, t_stack **b)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, 0);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			turk_algo(a, b);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		i;

	a = NULL;
	b = NULL;
	args = NULL;
	if (parse_arguments(&a, argc, argv, &args))
		return (1);
	execute_sort(&a, &b);
	if (argc == 2 && args)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
	free_stack(&a);
	return (0);
}
