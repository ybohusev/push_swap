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

static	int		get_pivot(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->content);
}

static	int		is_sorted(t_stack *stack, char mode)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (mode == 'a')
		{
			if (stack->content < stack->next->content)
				stack = stack->next;
			else
				return (0);
		}
		else if (mode == 'd')
		{
			if (stack->content > stack->next->content)
				stack = stack->next;
			else
				return (0);
		}	
	}
	return (1);
}

static	int		max_elem(t_stack *stack)
{
	int		i;

	i = stack->content;
	while (stack)
	{
		if (i < stack->content)
			i = stack->content;
		stack = stack->next;
	}
	return (i);
}

extern	void	basic_algor(t_stack **a, t_stack **b)
{
	int		pivot;
	int		len;
	int		max_a;

	pivot = get_pivot(*a);
	len = ft_stcklen(*a);
	while (len > 3 && !(is_sorted(*a, 'a') && is_sorted(*b, 'd')))
	{
		if (pivot >= (*a)->content && (len = len - 1))
		{
			if (pivot == (*a)->content)
				pivot = get_pivot(*a);
			pa_pb(a, b, 'b', 1);
		}
		else
			ra_rb_rr(a, b, 'a', 1);
		if (ft_stcklen(*b) > 1)
		{
			if ((*b)->content < get_pivot(*b) || (*b)->content < (*b)->next->content)
			{
				if ((*b)->content - get_pivot(*b) < (*b)->content - (*b)->next->content)
					ra_rb_rr(a, b, 'b', 1);
				else if ((*b)->content - get_pivot(*b) >= (*b)->content - (*b)->next->content)
					sa_sb_ss(*a, *b, 'b', 1);
			}
		}
	}
	max_a = max_elem(*a);
	while (!is_sorted(*a, 'a'))
	{
		if ((*a)->content == max_a)
			ra_rb_rr(a, b, 'a', 1);
		else if ((*a)->next->content == max_a)
			sa_sb_ss(*a, *b, 'a', 1);
		if ((*a)->content > (*a)->next->content && (*a)->content != max_a)
			sa_sb_ss(*a, *b, 'a', 1);
	}
	
	while (*b)
	{
		if (ft_stcklen(*b) > 1)
		{
			if ((*b)->content < get_pivot(*b) || (*b)->content < (*b)->next->content)
			{
				if ((*b)->content - get_pivot(*b) < (*b)->content - (*b)->next->content)
					ra_rb_rr(a, b, 'b', 1);
				else if ((*b)->content - get_pivot(*b) >= (*b)->content - (*b)->next->content)
					sa_sb_ss(*a, *b, 'b', 1);
			}
			else
				pa_pb(a, b, 'a', 1);
		}
		else
			pa_pb(a, b, 'a', 1);
	}
}
