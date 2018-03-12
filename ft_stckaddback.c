/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckaddback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:19:45 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/12 18:19:47 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckaddback(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!new)
		return ;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
