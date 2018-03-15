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

int		main(int argc, char **argv)
{
	char	*inst;
	t_stack	*op;
	t_stack	*stack;

	if (argc == 1)
		return (0);
	while (get_next_line(0, &inst) > 0 && *inst != '\0')
	{
		get_instruction(inst, &op);
		free(inst);
	}
	while (op->next)
	{
		printf("%d\n", op->content);
		op = op->next;
	}
	return (0);
}
