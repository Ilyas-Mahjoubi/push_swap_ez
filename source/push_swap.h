/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:09:41 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/02/23 20:09:41 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				push_cost;
	int			above_median;
	int			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	pa(t_stack **a, t_stack **b, int flag);
void	pb(t_stack **b, t_stack **a, int flag);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b, int flag);
void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b, int flag);
void 	move_same_direction(t_stack **a, t_stack **b, t_stack *node);// is new
void 	finish_rotations(t_stack **stack, t_stack *target, char stack_name); //_is new
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);
void	sort_stacks(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sa(t_stack **a, int flag);
void	sb(t_stack **b, int flag);
void	ss(t_stack **a, t_stack **b, int flag);
int	stack_sorted(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
void	fill_node(t_stack **stack, int nbr);
void	init_stack_a(t_stack **a, char **av, int free_needed);
t_stack	*set_cheapest(t_stack *stack);
void	set_index(t_stack *stack);
void	find_target_in_b(t_stack *a, t_stack *b);
void	calculate_cost(t_stack *a, t_stack *b);
void	mark_cheapest_node(t_stack *stack);
void	prepare_stack_a(t_stack *a, t_stack *b);
void	find_target_in_a(t_stack *a, t_stack *b);
void	prepare_stack_b(t_stack *a, t_stack *b);
int		check_arg_nbr(char *str);
int		duplicates(t_stack *a, int n);
void	free_stack(t_stack **stack);
t_stack	*find_last(t_stack *stack);
int		stack_len(t_stack *stack);
void	free_errors(t_stack **a, char **args);
void	free_args(char **args, int i);
void	print_stack(t_stack *stack);
int		ft_strcmp(const char *s1, const char *s2);

#endif
