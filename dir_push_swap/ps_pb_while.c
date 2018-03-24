/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pb_while.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:50:26 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/24 14:50:27 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		push_one(t_stack **a, t_stack **b)
{
	int		count;
	int		j;

	count = 0;
	j = 0;
	while (j < 4)
	{
		if ((*a)->content < (*a)->median)
		{
			pa_pb(a, b, 'b', 1);
			return (count);
		}
		else
		{
			ra_rb_rr(a, b, 'a', 1);
			count++;
		}
		j++;
	}
	return (count);
}

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
		if ((*a)->content < (*a)->median)
		{
			count_pb++;
			pa_pb(a, b, 'b', 1);
		}
		else
		{
			ra_rb_rr(a, b, 'a', 1);
			count++;
		}
		if (len / 2 == count_pb)
			return (count);
		curr_len--;
	}
	return (count);
}

extern	int		pb_while(t_stack **a, t_stack **b)
{
	int		len;

	ft_stckgetmedian(*a);
	len = median_len(*a, (*a)->median);
	if (len == 4)
		return (push_one(a, b));
	else if (len > 4)
		return (do_act(a, b, len));
	return (0);
}
