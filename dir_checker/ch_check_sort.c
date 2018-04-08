/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:51:22 by ybohusev          #+#    #+#             */
/*   Updated: 2018/04/08 15:51:35 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_sort(t_stack *a, t_stack *b)
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
