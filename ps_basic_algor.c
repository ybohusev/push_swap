/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_basic_algor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:06:35 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/17 14:06:36 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		is_sorted(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->content < a->next->content)
			a = a->next;
		else
			return (0);	
	}
	return (1);
}

static	int		pb_while(t_stack **a, t_stack **b)
{
	int		len;
	int		count;

	len = median_len(*a, (*a)->median);
	ft_stckgetmedian(*a);
	printf("MEDIAN %d\n", (*a)->median);
	count = 0;
	if (len <= 3)
		return (0);
	while (len)
	{
		if ((*a)->content < (*a)->median)
			pa_pb(a, b, 'b', 1);
		else
		{
			ra_rb_rr(a, b, 'a', 1);
			count++;
		}
		len--;
	}
	count += pb_while(a, b);
	return (count);
}

static	void	pa_while(t_stack **a, t_stack **b)
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

static	void	sort_three(t_stack **a, t_stack **b)
{
	if ((*a)->content == (*a)->median)
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
	else if ((*a)->next->content == (*a)->median)
	{
			sa_sb_ss(*a, *b, 'a', 1);
			ra_rb_rr(a, b, 'a', 1);
			sa_sb_ss(*a, *b, 'a', 1);
			rra_rrb_rrr(a, b, 'a', 1);
			sa_sb_ss(*a, *b, 'a', 1);
	}
	else if ((*a)->next->next->content == (*a)->median)
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
}

static	void	sort_top(t_stack **a, t_stack **b)
{
	int		count;
	int		len;

	len = median_len(*a, (*a)->median);
	ft_stckgetmedian(*a);
	if (len == 2 && !is_sorted(*a))
		sa_sb_ss(*a, *b, 'a', 1);
	else if (len == 3 && !is_sorted(*a))
		sort_three(a, b);
	else if (len > 3)
	{
		count = pb_while(a, b);
		while (count > 0)
		{
			rra_rrb_rrr(a, b, 'a', 1);
			count--;
		}
		sort_top(a, b);
	}
}

static	void	sort_a(t_stack **a, t_stack **b)
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

extern	void	basic_algor(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (median_len(a, a->median) > 3)
		pb_while(&a, &b);
	sort_a(&a, &b);
	while (b)
	{
		pa_while(&a, &b);
		sort_top(&a, &b);
	}
}
