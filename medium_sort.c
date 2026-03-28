/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csekakul <csekakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:06:02 by csekakul          #+#    #+#             */
/*   Updated: 2026/03/25 10:33:13 by csekakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (size / 5);
	else
		return (size / 8);
}

void	chunk_sort(t_stack *s)
{
	int	chunk;
	int	i;

	chunk = get_chunk_size(s->size_a);
	i = 0;
	while (s->size_a > 0)
	{
		if (s->a[0] <= i)
		{
			pb(s);
			rb(s);
			i++;
		}
		else if (s->a[0] <= i + chunk)
		{
			pb(s);
			i++;
		}
		else
			ra(s);
	}
	while (s->size_b > 0)
		push_back_max(s);
}
