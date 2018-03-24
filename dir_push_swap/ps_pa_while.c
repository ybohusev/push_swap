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

int		pa_while(t_stack **a, t_stack **b)
{
	int		len;
	int		count;

	ft_stckgetmedian(*b);
	len = median_len(*b, (*b)->median);
	count = 0;
	while (len)
	{
		if ((*b)->content > (*b)->median)
			pa_pb(a, b, 'a', 1);
		else
		{
			ra_rb_rr(a, b, 'b', 1);
			count++;
		}
		len--;
	}
	return (count);
}
