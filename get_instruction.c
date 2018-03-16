/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:51:14 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/16 19:51:16 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_valid_instruction(char *i)
{
	if (!ft_strcmp(i, "sa"))
		return (1);
	else if (!ft_strcmp(i, "sb"))
		return (2);
	else if (!ft_strcmp(i, "ss"))
		return (3);
	else if (!ft_strcmp(i, "pa"))
		return (4);
	else if (!ft_strcmp(i, "pb"))
		return (5);
	else if (!ft_strcmp(i, "ra"))
		return (6);
	else if (!ft_strcmp(i, "rb"))
		return (7);
	else if (!ft_strcmp(i, "rr"))
		return (8);
	else if (!ft_strcmp(i, "rra"))
		return (9);
	else if (!ft_strcmp(i, "rrb"))
		return (10);
	else if (!ft_strcmp(i, "rrr"))
		return (11);
	else if (*i == '\0')
		return (0);
	return (-1);
}

void	get_instruction(char *inst, t_stack **op)
{
	int		nb;

	nb = is_valid_instruction(inst);
	if (nb != -1)
		ft_stckaddback(op, ft_stcknew(nb));
	else
	{
		if (*op != NULL)
			ft_stckdel(op);
		write(2, "Error\n", 6);
		exit(1);
	}
}
