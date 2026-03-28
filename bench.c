/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csekakul <csekakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:34:09 by csekakul          #+#    #+#             */
/*   Updated: 2026/03/25 13:43:43 by csekakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ops_top(t_stack *s)
{
	putstr_fd("sa: ", 2);
	putnbr_fd(s->sa_count, 2);
	putstr_fd(" sb: ", 2);
	putnbr_fd(s->sb_count, 2);
	putstr_fd(" ss: ", 2);
	putnbr_fd(s->ss_count, 2);
	write(2, "\n", 1);

	putstr_fd("pa: ", 2);
	putnbr_fd(s->pa_count, 2);
	putstr_fd(" pb: ", 2);
	putnbr_fd(s->pb_count, 2);
	write(2, "\n", 1);
}

void	print_ops_bottom(t_stack *s)
{
	putstr_fd("ra: ", 2);
	putnbr_fd(s->ra_count, 2);
	putstr_fd(" rb: ", 2);
	putnbr_fd(s->rb_count, 2);
	putstr_fd(" rr: ", 2);
	putnbr_fd(s->rr_count, 2);
	write(2, "\n", 1);

	putstr_fd("rra: ", 2);
	putnbr_fd(s->rra_count, 2);
	putstr_fd(" rrb: ", 2);
	putnbr_fd(s->rrb_count, 2);
	putstr_fd(" rrr: ", 2);
	putnbr_fd(s->rrr_count, 2);
	write(2, "\n", 1);
}

void	print_percentage(double d)
{
	int	value;

	value = (int)(d * 10000);
	putnbr_fd(value / 100, 2);
	write(2, ".", 1);
	if ((value % 100) < 10)
		write(2, "0", 1);
	putnbr_fd(value % 100, 2);
	write(2, "%\n", 2);
}

void	print_strategy(t_strategy strategy, double disorder)
{
	putstr_fd("Strategy: ", 2);
	if (strategy == SIMPLE)
		putstr_fd("SIMPLE (O(n^2))\n", 2);
	else if (strategy == MEDIUM)
		putstr_fd("MEDIUM (O(n√n))\n", 2);
	else if (strategy == COMPLEX)
		putstr_fd("COMPLEX (O(n log n))\n", 2);
	else
	{
		if (disorder < 0.2)
		putstr_fd("ADAPTIVE / O(n)\n", 2);
	else if (disorder < 0.5)
		putstr_fd("ADAPTIVE / O(n√n)\n", 2);
	else
		putstr_fd("ADAPTIVE / O(n log n)\n", 2);
	}
}

void	print_bench(t_stack *s, double disorder, t_strategy strategy)
{
	putstr_fd("Disorder: ", 2);
	print_percentage(disorder);
	print_strategy(strategy, disorder);
	putstr_fd("Total operations: ", 2);
	putnbr_fd(s->op_count, 2);
	write(2, "\n", 1);
	print_ops_top(s);
	print_ops_bottom(s);
}
