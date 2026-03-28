/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csekakul <csekakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:02:32 by csekakul          #+#    #+#             */
/*   Updated: 2026/03/25 10:30:20 by csekakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_a_internal(t_stack *s)
{
	int	last;
	int	i;

	if (!s || s->size_a < 2)
		return (0);
	last = s->a[s->size_a - 1];
	i = s->size_a - 1;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[0] = last;
	return (1);
}

static int	reverse_rotate_b_internal(t_stack *s)
{
	int	last;
	int	i;

	if (!s || s->size_b < 2)
		return (0);
	last = s->b[s->size_b - 1];
	i = s->size_b - 1;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[0] = last;
	return (1);
}

void	rra(t_stack *s)
{
	if (!reverse_rotate_a_internal(s))
		return ;
	write(1, "rra\n", 4);
	s->op_count++;
	s->rra_count++;
}

void	rrb(t_stack *s)
{
	if (!reverse_rotate_b_internal(s))
		return ;
	write(1, "rrb\n", 4);
	s->op_count++;
	s->rrb_count++;
}

void	rrr(t_stack *s)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = reverse_rotate_a_internal(s);
	rotated_b = reverse_rotate_b_internal(s);
	if (!rotated_a && !rotated_b)
		return ;
	write(1, "rrr\n", 4);
	s->op_count++;
	s->rrr_count++;
}
