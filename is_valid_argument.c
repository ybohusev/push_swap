/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:58:54 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/15 14:58:58 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		is_valid_argument(t_stack *stack, char *arg)
{
	int		i;
	int		nb;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	nb = ft_atoi(arg);
	if (nb > MAX_INT || nb < MIN_INT)
		return (0);
	while (stack)
	{
		if (stack->content == nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}
