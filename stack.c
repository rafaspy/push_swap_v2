/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csekakul <csekakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 08:45:18 by csekakul          #+#    #+#             */
/*   Updated: 2026/03/25 13:32:29 by csekakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_stack_struct(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->total = 0;
	stack->op_count = 0;
	stack->sa_count = 0;
	stack->sb_count = 0;
	stack->ss_count = 0;
	stack->pa_count = 0;
	stack->pb_count = 0;
	stack->ra_count = 0;
	stack->rb_count = 0;
	stack->rr_count = 0;
	stack->rra_count = 0;
	stack->rrb_count = 0;
	stack->rrr_count = 0;
	return (stack);
}

void	stack_add_back(t_stack **stack, int n)
{
	int	*new_array;
	int	i;

	if (!*stack)
		*stack = init_stack_struct();
	if (!*stack)
		error_exit(NULL, NULL, NULL);
	new_array = malloc(sizeof(int) * ((*stack)->size_a + 1));
	if (!new_array)
		error_exit(stack, NULL, NULL);
	i = 0;
	while (i < (*stack)->size_a)
	{
		new_array[i] = (*stack)->a[i];
		i++;
	}
	new_array[i] = n;
	free((*stack)->a);
	(*stack)->a = new_array;
	(*stack)->size_a++;
	(*stack)->total++;
}

int	is_duplicate(t_stack **stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*stack)->size_a)
	{
		j = i + 1;
		while (j < (*stack)->size_a)
		{
			if ((*stack)->a[j] == (*stack)->a[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
