/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:01:22 by ybohusev          #+#    #+#             */
/*   Updated: 2017/11/05 20:24:23 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	void	check_extr(long long res, int is_negative)
{
	res = res * is_negative;
	if (res > MAX_INT || res < MIN_INT)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

extern	int		ft_atoi(char *str)
{
	long long	res;
	int			i;
	int			is_negative;

	res = 0;
	is_negative = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		is_negative = -1;
		i++;
	}
	if (str[i] == '+' && is_negative == 1)
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - 48);
	check_extr(res, is_negative);
	return ((int)res * is_negative);
}
