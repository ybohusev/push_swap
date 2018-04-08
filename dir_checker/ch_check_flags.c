/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 17:29:25 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/08 17:29:26 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	t_flags	init_struct(void)
{
	t_flags	flags;

	flags.v = 0;
	flags.s = 0;
	return (flags);
}

static	void	put_flag(char c, t_flags *flags)
{
	if (c == 'v')
		(*flags).v = 1;
	else if (c == 's')
		(*flags).s = 1;
}

extern	t_flags	check_flags(char ***argv, int *argc)
{
	int		check;
	t_flags flags;

	check = 0;
	(*argv)++;
	flags = init_struct();
	while (*argv && !check)
	{
		if (argv[0][0][0] == '-' && !ft_isdigit(argv[0][0][1]))
		{
			put_flag(argv[0][0][1], &flags);
			(*argv)++;
			(*argc)--;
		}
		else
			check = 1;
	}
	return (flags);
}
