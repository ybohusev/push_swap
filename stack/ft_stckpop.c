/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:08:18 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/12 15:08:19 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckpop(t_stack **stack)
{
	t_stack *tmp;

	if (!(*stack))
		return ;
	tmp = *stack;
	free(tmp);
	*stack = tmp->next;
}
