/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 17:43:27 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/08 17:43:29 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	void	total(t_stack *inst)
{
	char	*c;

	c = ft_itoa(ft_stcklen(inst));
	ft_putstr("\033[31m_______________________________\n");
	ft_putstr("Total count of operations: ");
	ft_putendl(c);
	ft_putstr("-------------------------------\033[37m\n");
	free(c);
}

static	void	count_ops(t_stack *inst, int *ops)
{
	if (inst->content == SA)
		ops[0]++;
	else if (inst->content == SB)
		ops[1]++;
	else if (inst->content == SS)
		ops[2]++;
	else if (inst->content == PB)
		ops[3]++;
	else if (inst->content == PA)
		ops[4]++;
	else if (inst->content == RA)
		ops[5]++;
	else if (inst->content == RB)
		ops[6]++;
	else if (inst->content == RR)
		ops[7]++;
	else if (inst->content == RRA)
		ops[8]++;
	else if (inst->content == RRB)
		ops[9]++;
	else if (inst->content == RRR)
		ops[10]++;
	if ((inst = inst->next))
		count_ops(inst, ops);
}

static	void	print(char *str, char *c)
{
	ft_putstr("\033[33m");
	ft_putstr(str);
	ft_putendl(c);
	ft_putstr("\033[37m\n");
	free(c);
}

static	void	rel(int *ops)
{
	print("count of sa: ", ft_itoa(ops[0]));
	print("count of sb: ", ft_itoa(ops[1]));
	print("count of ss: ", ft_itoa(ops[2]));
	print("count of pb: ", ft_itoa(ops[3]));
	print("count of pa: ", ft_itoa(ops[4]));
	print("count of ra: ", ft_itoa(ops[5]));
	print("count of rb: ", ft_itoa(ops[6]));
	print("count of rr: ", ft_itoa(ops[7]));
	print("count of rra: ", ft_itoa(ops[8]));
	print("count of rrb: ", ft_itoa(ops[9]));
	print("count of rrr: ", ft_itoa(ops[10]));
}

extern	void	stat(t_stack *inst)
{
	int		*ops;
	int		count;

	total(inst);
	count = 0;
	ops = (int*)malloc(sizeof(int) * 11);
	while (count < 11)
	{
		ops[count] = 0;
		count++;
	}
	count_ops(inst, ops);
	rel(ops);
	free(ops);
}
