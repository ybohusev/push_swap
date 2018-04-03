/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrb_while.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:38:14 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/24 17:38:16 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	pa_back(t_stack **a, t_stack **b)
{
	if ((*b)->content >= (*b)->median)
		pa_pb(a, b, 'a', 1);
}

extern	void	rrb_while(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	if ((*b)->median <= tmp->median)
	{
		rra_rrb_rrr(a, b, 'b', 1);
		pa_back(a, b);
	}
	else
		return ;
	rrb_while(a, b);
}
