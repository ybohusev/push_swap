/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_b.c                                        :+:      :+:    :+:   */
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
	ft_stckgetmedian(*b);
	if ((*b)->content == (*b)->median)
	{
		if ((*b)->content < (*b)->next->content)
			sa_sb_ss(*a, *b, 'b', 1);
		else if ((*b)->content > (*b)->next->content)
			rra_rrb_rrr(a, b, 'b', 1);
	}
	else if ((*b)->next->content == (*b)->median &&
			(*b)->content < (*b)->next->next->content)
	{
		ra_rb_rr(a, b, 'b', 1);
		sa_sb_ss(*a, *b, 'b', 1);
	}
	else if ((*b)->next->next->content == (*b)->median)
	{
		if ((*b)->content < (*b)->next->content)
			ra_rb_rr(a, b, 'b', 1);
		else if ((*b)->content > (*b)->next->content)
		{
			sa_sb_ss(*a, *b, 'b', 1);
			ra_rb_rr(a, b, 'b', 1);
		}
	}
}

extern	void	sort_b(t_stack **a, t_stack **b)
{
	if (is_sorted_des(*b))
		return ;
	if (median_len(*b, (*b)->median) < 3)
		sa_sb_ss(*a, *b, 'b', 1);
	else
		sort_more(a, b);
}
