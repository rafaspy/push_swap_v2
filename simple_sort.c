/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csekakul <csekakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:05:31 by csekakul          #+#    #+#             */
/*   Updated: 2026/03/25 12:50:51 by csekakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack *a)
{
	if (!a || is_sorted(a))
		return ;
	while (a->size_a > 5)
		push_smallest_to_b(a);
	if (a->size_a <= 3)
		sort_small(a);
	else if (a->size_a <= 5)
		sort_four_or_five(a);
	while (a->size_b > 0)
		pa(a);
}
