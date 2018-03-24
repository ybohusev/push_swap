/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:47:30 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/24 14:47:32 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort_more(t_stack **a, t_stack **b)
{
	ft_stckgetmedian(*a);
	if ((*a)->content == (*a)->median)
	{
		if ((*a)->content > (*a)->next->content)
			sa_sb_ss(*a, *b, 'a', 1);
		else if ((*a)->content < (*a)->next->content)
			rra_rrb_rrr(a, b, 'a', 1);
	}
	else if ((*a)->next->content == (*a)->median && (*a)->content > (*a)->next->next->content)
	{
			ra_rb_rr(a, b, 'a', 1);
			sa_sb_ss(*a, *b, 'a', 1);
	}
	else if ((*a)->next->next->content == (*a)->median)
	{
		if ((*a)->content > (*a)->next->content)
			ra_rb_rr(a, b, 'a', 1);
		else if ((*a)->content < (*a)->next->content)
		{
			sa_sb_ss(*a, *b, 'a', 1);
			ra_rb_rr(a, b, 'a', 1);
		}
	}
}

extern	void	sort_a(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return ;
	if (median_len(*a, (*a)->median) < 3)
		sa_sb_ss(*a, *b, 'a', 1);
	else
		sort_more(a, b);
}
