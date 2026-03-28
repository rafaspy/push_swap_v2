/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csekakul <csekakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 08:43:58 by csekakul          #+#    #+#             */
/*   Updated: 2026/03/25 08:51:49 by csekakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_is_correct(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	get_numbers(char *current_arg, t_stack **a)
{
	char	**param;
	long	n;
	int		i;

	i = 0;
	param = ft_split(current_arg, ' ');
	if (!param || !param[0])
		error_exit(a, NULL, param);
	while (param[i])
	{
		if (!input_is_correct(param[i]))
			error_exit(a, NULL, param);
		n = ft_atoi(param[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_exit(a, NULL, param);
		stack_add_back(a, (int) n);
		i++;
	}
	free_split(param);
}
