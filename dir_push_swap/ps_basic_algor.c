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

static	void	stage_one(t_stack **a, t_stack **b, int flag)
{
	int		count;

	while (median_len(*a, (*a)->median) > 3)
	{
		count = 0;
		ft_stckgetmedian(*a);
		count = pb_while(a, b);
		if (flag)
			rra_while(a, b, count);
		if (*b)
			ft_stckgetmedian(*b);
	}
	if (!flag)
		sort_a(a, b);
	else
		sort_top_a(a, b);
	if (*b)
		ft_stckgetmedian(*b);
}

static	void	stage_two(t_stack **a, t_stack **b)
{
	int		count;

	count = 0;
	if (!(*b))
		return ;
	if (median_len(*b, (*b)->median) <= 3)
		pa_all(a, b);
	else
		count += pa_while(a, b);
	if (median_len(*a, (*a)->median) > 3)
		stage_one(a, b, 1);
	else
		sort_top_a(a, b);
	if (*b && ft_stcklen(*b) != median_len(*b, (*b)->median))
		rrb_while(a, b);
}

extern	void	basic_algor(t_stack *a, t_stack *b, int flag)
{
	if (is_sorted(a) && !b)
		return ;
	// print_a_b(a, b);
	stage_one(&a, &b, flag);
	// print_a_b(a, b);
	stage_two(&a, &b);
	// print_a_b(a, b);
	basic_algor(a, b, 1);
}


/*711*/