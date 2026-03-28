/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csekakul <csekakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:19:45 by csekakul          #+#    #+#             */
/*   Updated: 2026/03/25 08:48:58 by csekakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_index(t_stack *s)
{
	int	min_index;
	int	i;

	min_index = 0;
	if (!s || s->size_a == 0)
		return (-1);
	i = 1;
	while (i < s->size_a)
	{
		if (s->a[i] < s->a[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	push_smallest_to_b(t_stack *s)
{
	int	index;

	index = find_smallest_index(s);
	if (index == -1)
		return ;
	if (index <= s->size_a / 2)
	{
		while (index-- > 0)
			ra(s);
	}
	else
	{
		index = s->size_a - index;
		while (index-- > 0)
			rra(s);
	}
	pb(s);
}

int	find_max_index(t_stack *s)
{
	int	i;
	int	max_i;

	i = 0;
	max_i = 0;
	while (i < s->size_b)
	{
		if (s->b[i] > s->b[max_i])
			max_i = i;
		i++;
	}
	return (max_i);
}

void	push_back_max(t_stack *s)
{
	int	index;

	index = find_max_index(s);
	if (index <= s->size_b / 2)
	{
		while (index-- > 0)
			rb(s);
	}
	else
	{
		index = s->size_b - index;
		while (index-- > 0)
			rrb(s);
	}
	pa(s);
}

double	compute_disorder(t_stack *s)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < s->size_a)
	{
		j = i + 1;
		while (j < s->size_a)
		{
			total_pairs++;
			if (s->a[i] > s->a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / total_pairs);
}
