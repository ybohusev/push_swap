/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 19:04:39 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/12 19:04:41 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckdel(t_stack **stack)
{
	if (!(*stack))
		return ;
	if ((*stack)->next == NULL)
	{
		free(*stack);
		return ;
	}
	while ((*stack)->next)
		ft_stckdellast(stack);
	free(*stack);
}
