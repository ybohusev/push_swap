/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:09:29 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/12 15:09:30 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack		*ft_stckinit(char **arg, int count)
{
	t_stack		*stack;

	stack = NULL;
	if (arg == NULL || count == 0)
		return (NULL);
	/*START TEMPORARY KOSTYL'*/
	if (count == 1)
	{
		arg = ft_strsplit(arg[1], ' ');
		count = 0;
		while (arg[count + 1])
			count++;
	}
	/*END TEMPORARY KOSTYL'*/
	while (count >= 0)
	{
		if (is_valid_argument(stack, arg[count]))
		{
			ft_stckaddtop(&stack, ft_stcknew(ft_atoi(arg[count])));
			count--;
		}
		else
		{
			if (stack != NULL)
				ft_stckdel(&stack);
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	return (stack);
}
