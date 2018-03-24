/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pa_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:51:53 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/24 16:51:54 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_all(t_stack **a, t_stack **b)
{
	int		top_median;
	t_stack	*tmp;

	top_median = (*b)->median;
	tmp = *b;
	while (tmp && tmp->median == top_median)
	{
		pa_pb(a, b, 'a', 1);
		tmp = tmp->next;
	}
}
