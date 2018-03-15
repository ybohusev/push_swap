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

#include "ft_stack.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*inst;
	t_stack	*op;
	t_stack	*stack;
	int		eof;

	if (argc == 1)
		return (0);
	while ((eof = get_next_line(0, &inst)) > 0 && *inst != '\0')
	{
		if (is_valid_instriction)
			
		free(inst);
	}
	return (0);
}
