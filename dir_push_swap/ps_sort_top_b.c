/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_top_b.c                                    :+:      :+:    :+:   */
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
	if ((*b)->content < (*b)->next->content)
		sa_sb_ss(*a, *b, 'b', 1);
	else if ((*b)->content > (*b)->next->content)
	{
		ra_rb_rr(a, b, 'b', 1);
		sa_sb_ss(*a, *b, 'b', 1);
		rra_rrb_rrr(a, b, 'b', 1);
		sa_sb_ss(*a, *b, 'b', 1);
	}
}

static	void	median_second(t_stack **a, t_stack **b)
{
	sa_sb_ss(*a, *b, 'b', 1);
	ra_rb_rr(a, b, 'b', 1);
	sa_sb_ss(*a, *b, 'b', 1);
	rra_rrb_rrr(a, b, 'b', 1);
	sa_sb_ss(*a, *b, 'b', 1);
}

static	void	median_last(t_stack **a, t_stack **b)
{
	if ((*b)->content < (*b)->next->content)
	{
		sa_sb_ss(*a, *b, 'b', 1);
		ra_rb_rr(a, b, 'b', 1);
		sa_sb_ss(*a, *b, 'b', 1);
		rra_rrb_rrr(a, b, 'b', 1);
	}
}

static	void	sort_three(t_stack **a, t_stack **b)
{
	if ((*b)->content == (*b)->median)
		median_first(a, b);
	else if ((*b)->next->content == (*b)->median && (*b)->content > (*b)->next->next->content)
		median_second(a, b);
	else if ((*b)->next->next->content == (*b)->median)
		median_last(a, b);
}

extern	void	sort_top_b(t_stack **a, t_stack **b)
{
	ft_stckgetmedian(*b);
	if (is_sorted_des(*b))
		return ;
	if (median_len(*b, (*b)->median) == 2)
		sa_sb_ss(*a, *b, 'b', 1);
	else if (median_len(*b, (*b)->median) > 2)
		sort_three(a, b);
}
