/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pa_while.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:54:03 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/24 14:54:04 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		do_act(t_stack **a, t_stack **b, int len)
{
	int	curr_len;
	int	count_pb;
	int	count;

	curr_len = len;
	count_pb = 0;
	count = 0;
	while (curr_len)
	{
		if ((*b)->content > (*b)->median)
		{
			count_pb++;
			pa_pb(a, b, 'a', 1);
		}
		else
		{
			ra_rb_rr(a, b, 'b', 1);
			count++;
		}
		if ((len / 2 == count_pb && len % 2 != 0) ||
			((len / 2) - 1 == count_pb && len % 2 == 0))
			return (count);
		curr_len--;
	}
	return (count);
}

static	int		search_min(t_stack *stack)
{
	int		min;
	int		median;

	median = stack->median;
	min = stack->content;
	while (stack && stack->median == median)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

static	int		push_one(t_stack **a, t_stack **b, int min)
{
	int		count;
	int		j;
	int		count_pb;

	count = 0;
	count_pb = 0;
	j = 0;
	while (j < 4)
	{
		if ((*b)->content > min)
		{
			pa_pb(a, b, 'a', 1);
			count_pb++;
		}
		else
		{
			ra_rb_rr(a, b, 'b', 1);
			count++;
		}
		if (count_pb == 3)
			return (count);
		j++;
	}
	return (count);
}

extern	int		pa_while(t_stack **a, t_stack **b)
{
	int		len;

	len = median_len(*b, (*b)->median);
	if (len == 4)
		return (push_one(a, b, search_min(*b)));
	if (len > 4)
		return (do_act(a, b, len));
	return (0);
}
