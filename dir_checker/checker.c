/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:47:11 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/15 13:47:12 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

static	void	check_sort(t_stack *a, t_stack *b)
{
	if (b)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (a->next)
	{
		if (a->content < a->next->content)
			a = a->next;
		else
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	write(1, "OK\n", 3);
}

static	void	do_inst(t_stack **a, t_stack **b, t_stack *inst)
{
	if (inst->content == SA)
		sa_sb_ss(*a, *b, 'a', 0);
	else if (inst->content == SB)
		sa_sb_ss(*a, *b, 'b', 0);
	else if (inst->content == SS)
		sa_sb_ss(*a, *b, 's', 0);
	else if (inst->content == PB)
		pa_pb(a, b, 'b', 0);
	else if (inst->content == PA)
		pa_pb(a, b, 'a', 0);
	else if (inst->content == RA)
		ra_rb_rr(a, b, 'a', 0);
	else if (inst->content == RB)
		ra_rb_rr(a, b, 'b', 0);
	else if (inst->content == RR)
		ra_rb_rr(a, b, 'r', 0);
	else if (inst->content == RRA)
		rra_rrb_rrr(a, b, 'a', 0);
	else if (inst->content == RRB)
		rra_rrb_rrr(a, b, 'b', 0);
	else if (inst->content == RRR)
		rra_rrb_rrr(a, b, 'r', 0);
	if ((inst = inst->next))
		do_inst(a, b, inst);
}

extern	int		main(int argc, char **argv)
{
	char	*inst;
	t_stack	*op;
	t_stack	*a;
	t_stack	*b;

	op = NULL;
	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	a = ft_stckinit(argv, argc - 1);
	while (get_next_line(0, &inst) > 0)
	{
		get_instruction(inst, &op);
		free(inst);
	}
	if (!op)
		op = ft_stcknew(0, 0);
	do_inst(&a, &b, op);
	check_sort(a, b);
	ft_stckdel(&op);
	ft_stckdel(&a);
	return (0);
}
