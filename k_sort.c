/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafsanch <rafsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 22:38:11 by rafsanch          #+#    #+#             */
/*   Updated: 2026/03/31 22:38:18 by rafsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_sqrt_up(int size)
{
	int	root;

	root = 0;
	while ((root + 1) * (root + 1) <= size)
		root++;
	if (root * root < size)
		root++;
	return (root);
}

static int	get_decision_median(int size)
{
	int	median;

	median = (int_sqrt_up(size) * 13) / 10;
	if (median < 1)
		return (1);
	return (median);
}

void	k_sort(t_stack *s)
{
	int	decision_median;

	decision_median = get_decision_median(s->total);
	while (s->size_a > 0)
	{
		if (s->a[0] <= s->size_b)
		{
			pb(s);
			rb(s);
		}
		else if (s->a[0] <= s->size_b + decision_median)
			pb(s);
		else
			ra(s);
	}
	while (s->size_b > 0)
		push_back_max(s);
}
