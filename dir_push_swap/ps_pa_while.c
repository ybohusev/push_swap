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
		if (len / 2 == count_pb)
			return (count);
		curr_len--;
	}
	return (count);
}

static	int		push_one(t_stack **a, t_stack **b)
{
	int		count;
	int		j;

	count = 0;
	j = 0;
	while (j < 4)
	{
		if ((*b)->content > (*b)->median)
		{
			pa_pb(a, b, 'a', 1);
			return (count);
		}
		else
		{
			ra_rb_rr(a, b, 'b', 1);
			count++;
		}
		j++;
	}
	return (count);
}

int		pa_while(t_stack **a, t_stack **b)
{
	int		len;

	ft_stckgetmedian(*b);
	len = median_len(*b, (*b)->median);
	if (len == 4)
		return (push_one(a, b));
	if (len > 4)
		return (do_act(a, b, len));
	return (0);
}
