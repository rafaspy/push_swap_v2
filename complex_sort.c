/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csekakul <csekakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:06:31 by csekakul          #+#    #+#             */
/*   Updated: 2026/03/25 09:10:36 by csekakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *s)
{
	int	max;
	int	bits;

	max = s->size_a - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *s)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = s->size_a;
	max_bits = get_max_bits(s);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((s->a[0] >> i) & 1) == 0)
				pb(s);
			else
				ra(s);
			j++;
		}
		while (s->size_b > 0)
			pa(s);
		i++;
	}
}
