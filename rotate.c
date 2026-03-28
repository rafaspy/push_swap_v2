/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csekakul <csekakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:01:52 by csekakul          #+#    #+#             */
/*   Updated: 2026/03/25 10:29:17 by csekakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_a_internal(t_stack *s)
{
	int	first;
	int	i;

	if (!s || s->size_a < 2)
		return (0);
	first = s->a[0];
	i = 0;
	while (i < s->size_a - 1)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[i] = first;
	return (1);
}

static int	rotate_b_internal(t_stack *s)
{
	int	first;
	int	i;

	if (!s || s->size_b < 2)
		return (0);
	first = s->b[0];
	i = 0;
	while (i < s->size_b - 1)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[i] = first;
	return (1);
}

void	ra(t_stack *s)
{
	if (!rotate_a_internal(s))
		return ;
	write(1, "ra\n", 3);
	s->op_count++;
	s->ra_count++;
}

void	rb(t_stack *s)
{
	if (!rotate_b_internal(s))
		return ;
	write(1, "rb\n", 3);
	s->op_count++;
	s->rb_count++;
}

void	rr(t_stack *s)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate_a_internal(s);
	rotated_b = rotate_b_internal(s);
	if (!rotated_a && !rotated_b)
		return ;
	write(1, "rr\n", 3);
	s->op_count++;
	s->rr_count++;
}
