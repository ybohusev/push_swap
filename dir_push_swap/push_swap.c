/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:53:33 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/17 13:53:34 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL; 
	b = NULL;
	if (argc == 1)
		return (0);
	a = ft_stckinit(argv, argc - 1);
	basic_algor(a, b);
	return (0);
}
