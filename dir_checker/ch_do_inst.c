/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_do_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:47:32 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/08 15:47:35 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	void	flag(t_stack *a, t_stack *b, int v)
{
	if (v)
		print_a_b(a, b);
}

extern	void	do_inst(t_stack **a, t_stack **b, t_stack *inst, int v)
{
	if (inst->content == SA)
		sa_sb_ss(*a, *b, 'a', v);
	else if (inst->content == SB)
		sa_sb_ss(*a, *b, 'b', v);
	else if (inst->content == SS)
		sa_sb_ss(*a, *b, 's', v);
	else if (inst->content == PB)
		pa_pb(a, b, 'b', v);
	else if (inst->content == PA)
		pa_pb(a, b, 'a', v);
	else if (inst->content == RA)
		ra_rb_rr(a, b, 'a', v);
	else if (inst->content == RB)
		ra_rb_rr(a, b, 'b', v);
	else if (inst->content == RR)
		ra_rb_rr(a, b, 'r', v);
	else if (inst->content == RRA)
		rra_rrb_rrr(a, b, 'a', v);
	else if (inst->content == RRB)
		rra_rrb_rrr(a, b, 'b', v);
	else if (inst->content == RRR)
		rra_rrb_rrr(a, b, 'r', v);
	flag(*a, *b, v);
	if ((inst = inst->next))
		do_inst(a, b, inst, v);
}
