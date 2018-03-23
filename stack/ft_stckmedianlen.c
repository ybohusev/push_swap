/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckmedianlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:55:56 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/21 13:57:07 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		median_len(t_stack *stack, int curr_median)
{
	int		len;

	len = 0;
	while (stack && (stack->median == curr_median))
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
