/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:28:13 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/15 13:28:14 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	sa_sb_ss(t_stack *a, t_stack *b, char mode, int pr)
{
	if (mode == 'a')
	{
		ft_stckswap(a);
		if (pr == 1)
			ft_putstr("sa\n");
	}
	else if (mode == 'b')
	{
		ft_stckswap(b);
		if (pr == 1)
			ft_putstr("sb\n");
	}
	else if (mode == 's')
	{
		ft_stckswap(a);
		ft_stckswap(b);
		if (pr == 1)
			ft_putstr("ss\n");
	}
}

void	pa_pb(t_stack **a, t_stack **b, char mode, int pr)
{
	if (mode == 'a')
	{
		ft_stckpush(b, a);
		if (pr == 1)
			ft_putstr("pa\n");
	}
	else if (mode == 'b')
	{
		ft_stckpush(a, b);
		if (pr == 1)
			ft_putstr("pb\n");
	}
}

void	ra_rb_rr(t_stack **a, t_stack **b, char mode, int pr)
{
	if (mode == 'a')
	{
		ft_stckrot(a);
		if (pr == 1)
			ft_putstr("ra\n");
	}
	else if (mode == 'b')
	{
		ft_stckrot(b);
		if (pr == 1)
			ft_putstr("rb\n");
	}
	else if (mode == 'r')
	{
		ft_stckrot(a);
		ft_stckrot(b);
		if (pr == 1)
			ft_putstr("rr\n");
	}
}

void	rra_rrb_rrr(t_stack **a, t_stack **b, char mode, int pr)
{
	if (mode == 'a')
	{
		ft_stckrevrot(a);
		if (pr == 1)
			ft_putstr("rra\n");
	}
	else if (mode == 'b')
	{
		ft_stckrevrot(b);
		if (pr == 1)
			ft_putstr("rrb\n");
	}
	else if (mode == 'r')
	{
		ft_stckrevrot(a);
		ft_stckrevrot(b);
		if (pr == 1)
			ft_putstr("rrr\n");
	}
}

void	print_a_b(t_stack *a, t_stack *b)
{
	ft_stckprint(a, "stack A");
	ft_putstr("\n");
	ft_stckprint(b, "stack B");
	ft_putstr("\n\n\n");
}
