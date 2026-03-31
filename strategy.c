/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csekakul <csekakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 09:00:29 by csekakul          #+#    #+#             */
/*   Updated: 2026/03/25 13:53:25 by csekakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*static int	is_flag(char *arg)
{
	return (!ft_strcmp(arg, "--simple")
		|| !ft_strcmp(arg, "--medium")
		|| !ft_strcmp(arg, "--complex")
		|| !ft_strcmp(arg, "--adaptive")
		|| !ft_strcmp(arg, "--bench"));
}*/

t_flags	parse_strategy(int argc, char **argv, int *start)
{
	t_flags		flags;
	int			i;

	flags.strategy = ADAPTIVE;
	flags.bench = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if (!ft_strcmp(argv[i], "--simple"))
			flags.strategy = SIMPLE;
		else if (!ft_strcmp(argv[i], "--medium"))
			flags.strategy = MEDIUM;
		else if (!ft_strcmp(argv[i], "--complex"))
			flags.strategy = COMPLEX;
		else if (!ft_strcmp(argv[i], "--adaptive"))
			flags.strategy = ADAPTIVE;
		else if (!ft_strcmp(argv[i], "--bench"))
			flags.bench = 1;
		else
			break ;
		i++;
	}
	*start = i;
	return (flags);
}

void	sort_stack(t_stack *a, t_stack *b, t_strategy strategy)
{
	(void)b;
	if (!a || is_sorted(a))
		return ;
	if (a->size_a <= 3)
		return (sort_small(a));
	else if (a->size_a <= 5)
		return (sort_four_or_five(a));
	if (strategy == SIMPLE)
		simple_sort(a);
	else if (strategy == MEDIUM)
	{
		index_stack(a);
		chunk_sort(a);
	}
	else if (strategy == COMPLEX)
	{
		index_stack(a);
		radix_sort(a);
	}
	else if (strategy == ADAPTIVE)
		adaptive_sort(a);
}
