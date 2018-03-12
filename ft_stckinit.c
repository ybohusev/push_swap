/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:09:29 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/12 15:09:30 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack		*ft_stckinit(char **arg, int count)
{
	t_stack		*stack;

	stack = NULL;
	if (arg == NULL || count == 0)
		return (NULL);
	while (count > 0)
	{
		ft_stckaddtop(&stack, ft_stcknew(ft_atoi(arg[count])));
		count--;
	}
	return (stack);
}
