/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_top_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:56:39 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/24 14:56:41 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	median_first(t_stack **a, t_stack **b)
{
	if ((*a)->content > (*a)->next->content)
		sa_sb_ss(*a, *b, 'a', 1);
	else if ((*a)->content < (*a)->next->content)
	{
		ra_rb_rr(a, b, 'a', 1);
		sa_sb_ss(*a, *b, 'a', 1);
		rra_rrb_rrr(a, b, 'a', 1);
		sa_sb_ss(*a, *b, 'a', 1);
	}
}

static	void	median_second(t_stack **a, t_stack **b)
{
	sa_sb_ss(*a, *b, 'a', 1);
	ra_rb_rr(a, b, 'a', 1);
	sa_sb_ss(*a, *b, 'a', 1);
	rra_rrb_rrr(a, b, 'a', 1);
	sa_sb_ss(*a, *b, 'a', 1);
}

static	void	median_last(t_stack **a, t_stack **b)
{
	if ((*a)->content > (*a)->next->content)
	{
		sa_sb_ss(*a, *b, 'a', 1);
		ra_rb_rr(a, b, 'a', 1);
		sa_sb_ss(*a, *b, 'a', 1);
		rra_rrb_rrr(a, b, 'a', 1);
	}
	else if ((*a)->content < (*a)->next->content)
	{
		ra_rb_rr(a, b, 'a', 1);
		sa_sb_ss(*a, *b, 'a', 1);
		rra_rrb_rrr(a, b, 'a', 1);
	}
}

static	void	sort_three(t_stack **a, t_stack **b)
{
	if ((*a)->content == (*a)->median)
		median_first(a, b);
	else if ((*a)->next->content == (*a)->median &&
			(*a)->content > (*a)->next->next->content)
		median_second(a, b);
	else if ((*a)->next->next->content == (*a)->median)
		median_last(a, b);
}

extern	void	sort_top_a(t_stack **a, t_stack **b)
{
	ft_stckgetmedian(*a);
	if (is_sorted(*a))
		return ;
	if (median_len(*a, (*a)->median) < 3)
		sa_sb_ss(*a, *b, 'a', 1);
	else
		sort_three(a, b);
}
