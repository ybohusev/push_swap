/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:08:12 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/12 17:03:32 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckaddtop(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}
