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
	count = 0;
	if (median_len(*a, (*a)->median) <= 3)
		return (0);
	while (len)
	{
		if ((*a)->content < (*a)->median)
			pa_pb(a, b, 'b', 1);
		else if ((*a)->content == (*a)->median && (median_len(*a, (*a)->median) % 2 != 0))
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
		printf("%d\n", tmp->median);
		pa_pb(a, b, 'a', 1);
		tmp = tmp->next;
	}
}

static	void	sort_top(t_stack **a, t_stack **b)
{
	int		count;

	if (median_len(*a, (*a)->median) == 2 && !is_sorted(*a))
	{
		sa_sb_ss(*a, *b, 'a', 1);
		return ;
	}
	else if (median_len(*a, (*a)->median) == 1)
		return ;
	ft_stckgetmedian(*a);
	count = pb_while(a, b);
	while (count)
	{
		rra_rrb_rrr(a, b, 'a', 1);
		count--;
	}
	// print_a_b(*a, *b);
}

extern	void	basic_algor(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && !b)
		return ;
	// print_a_b(a, b);
	pb_while(&a, &b);
	sort_top(&a, &b);
	
	pa_while(&a, &b);
	sort_top(&a, &b);

	// print_a_b(a, b);

	basic_algor(a, b);
}
