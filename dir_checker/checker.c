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

static	t_stack	*inst(void)
{
	char	*inst;
	t_stack	*op;

	op = NULL;
	while (get_next_line(0, &inst) > 0)
	{
		get_instruction(inst, &op);
		free(inst);
	}
	if (!op)
		op = ft_stcknew(0, 0);
	return (op);
}

extern	int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*op;
	t_flags	flags;

	op = NULL;
	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	op = inst();
	flags = check_flags(&argv, &argc);
	a = ft_stckinit(argv, argc - 1);
	do_inst(&a, &b, op, flags.v);
	if (flags.s)
		stat(op);
	check_sort(a, b);
	ft_stckdel(&op);
	ft_stckdel(&a);
	system("leaks checker");
	return (0);
}
