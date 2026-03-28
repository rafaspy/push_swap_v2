/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csekakul <csekakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 08:58:24 by csekakul          #+#    #+#             */
/*   Updated: 2026/03/25 13:47:43 by csekakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	int		total;
	int		op_count;
	int		sa_count;
	int		sb_count;
	int		ss_count;
	int		pa_count;
	int		pb_count;
	int		ra_count;
	int		rb_count;
	int		rr_count;
	int		rra_count;
	int		rrb_count;
	int		rrr_count;
}	t_stack;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_flags
{
	t_strategy	strategy;
	int			bench;
}	t_flags;

size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
long		ft_atoi(const char *str);
int			input_is_correct(char *str);
void		get_numbers(char *current_arg, t_stack **a);
void		error_exit(t_stack **a, t_stack **b, char **split);
int			is_duplicate(t_stack **stack);
void		stack_add_back(t_stack **stack, int n);
void		free_stack(t_stack **stack);
void		free_split(char **split);
void		sa(t_stack *s);
void		sb(t_stack *s);
void		ss(t_stack *s);
void		pa(t_stack *s);
void		pb(t_stack *s);
void		ra(t_stack *s);
void		rb(t_stack *s);
void		rr(t_stack *s);
void		rra(t_stack *s);
void		rrb(t_stack *s);
void		rrr(t_stack *s);
int			is_sorted(t_stack *s);
void		sort_two(t_stack *s);
void		sort_three(t_stack *s);
void		sort_small(t_stack *s);
void		sort_four_or_five(t_stack *s);
void		push_smallest_to_b(t_stack *s);
double		compute_disorder(t_stack *s);
void		index_stack(t_stack *s);
void		simple_sort(t_stack *a);
void		chunk_sort(t_stack *s);
void		k_sort(t_stack *s);
void		radix_sort(t_stack *s);
void		push_back_max(t_stack *s);
t_flags		parse_strategy(int argc, char **argv, int *start);
void		sort_stack(t_stack *a, t_stack *b, t_strategy strategy);
int			ft_strcmp(char *s1, char *s2);
void		adaptive_sort(t_stack *s);
void		print_bench(t_stack *s, double disorder, t_strategy strategy);
void		putstr_fd(char *s, int fd);
void		putnbr_fd(int n, int fd);
void		print_bench(t_stack *s, double disorder, t_strategy strategy);
void		print_strategy(t_strategy strategy, double disorder);
void		print_ops_top(t_stack *s);
void		print_ops_bottom(t_stack *s);
void		print_percentage(double d);

#endif
