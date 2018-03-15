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
			ft_putstr("sa");
	}
	else if (mode == 'b')
	{
		ft_stckswap(b);
		if (pr == 1)
			ft_putstr("sb");
	}
	else if (mode == 's')
	{
		ft_stckswap(a);
		ft_stckswap(b);
		if (pr == 1)
			ft_putstr("ss");
	}
}

void	pa_pb(t_stack **a, t_stack **b, char mode, int pr)
{
	if (mode == 'a')
	{
		ft_stckpush(a, b);
		if (pr == 1)
			ft_putstr("pb");
	}
	else if (mode == 'b')
	{
		ft_stckpush(b, a);
		if (pr == 1)
			ft_putstr("pa");
	}
}

void	ra_rb_rr(t_stack **a, t_stack **b, char mode, int pr)
{
	if (mode == 'a')
	{
		ft_stckrot(a);
		if (pr == 1)
			ft_putstr("ra");
	}
	else if (mode == 'b')
	{
		ft_stckrot(b);
		if (pr == 1)
			ft_putstr("rb");
	}
	else if (mode == 'r')
	{
		ft_stckrot(a);
		ft_stckrot(b);
		if (pr == 1)
			ft_putstr("rr");
	}
}

void	rra_rrb_rrr(t_stack **a, t_stack **b, char mode, int pr)
{
	if (mode == 'a')
	{
		ft_stckrevrot(a);
		if (pr == 1)
			ft_putstr("rra");
	}
	else if (mode == 'b')
	{
		ft_stckrevrot(b);
		if (pr == 1)
			ft_putstr("rrb");
	}
	else if (mode == 'r')
	{
		ft_stckrevrot(a);
		ft_stckrevrot(b);
		if (pr == 1)
			ft_putstr("rrr");
	}
}
