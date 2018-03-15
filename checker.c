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

// void	do_inst(t_stack *a, t_stack *inst)
// {
// 	t_stack *b;

// 	b = NULL;

// }

int		main(int argc, char **argv)
{
	char	*inst;
	t_stack	*op;
	t_stack	*stack;
	int yr;

	op = NULL;
	stack = NULL;
	if (argc == 1)
		return (0);
	stack = ft_stckinit(argv, argc - 1);
	while ((yr = get_next_line(0, &inst)) > 0)
	{
		printf("%d\n", yr);
		get_instruction(inst, &op);
		free(inst);
	}
	printf("%d\n", op->content);
	// do_inst(stack, op);
	ft_stckdel(&op);
	ft_stckdel(&stack);
	return (0);
}
