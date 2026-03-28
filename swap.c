/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csekakul <csekakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 09:53:24 by csekakul          #+#    #+#             */
/*   Updated: 2026/03/25 10:28:14 by csekakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_a_internal(t_stack *s)
{
	int	tmp;

	if (!s || s->size_a < 2)
		return (0);
	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
	return (1);
}

static int	swap_b_internal(t_stack *s)
{
	int	tmp;

	if (!s || s->size_b < 2)
		return (0);
	tmp = s->b[0];
	s->b[0] = s->b[1];
	s->b[1] = tmp;
	return (1);
}

void	sa(t_stack *s)
{
	if (!swap_a_internal(s))
		return ;
	write(1, "sa\n", 3);
	s->op_count++;
	s->sa_count++;
}

void	sb(t_stack *s)
{
	if (!swap_b_internal(s))
		return ;
	write(1, "sb\n", 3);
	s->op_count++;
	s->sb_count++;
}

void	ss(t_stack *s)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = swap_a_internal(s);
	swapped_b = swap_b_internal(s);
	if (!swapped_a && !swapped_b)
		return ;
	write(1, "ss\n", 3);
	s->op_count++;
	s->ss_count++;
}
