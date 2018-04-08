/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckissorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:52:20 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/24 14:52:23 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int		is_sorted(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->content < a->next->content)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int		is_sorted_des(t_stack *b)
{
	int		median;

	median = b->median;
	if (!b)
		return (0);
	while (b->next && b->median == median)
	{
		if (b->content > b->next->content)
			b = b->next;
		else
			return (0);
	}
	return (1);
}
