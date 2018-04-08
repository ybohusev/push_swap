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

static	void		delete_alloc(char **data)
{
	int	j;

	j = 0;
	while (data[j])
	{
		free(data[j]);
		data[j] = NULL;
		j++;
	}
	free(data);
	data = NULL;
}

static	t_stack		*init_one_arg(char **arg, int count, t_stack *stack)
{
	arg = ft_strsplit(arg[0], ' ');
	count = 0;
	while (arg[count + 1])
		count++;
	while (count >= 0)
	{
		if (is_valid_argument(stack, arg[count]))
		{
			ft_stckaddtop(&stack, ft_stcknew(ft_atoi(arg[count]), 0));
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
	delete_alloc(arg);
	return (stack);
}

static	t_stack		*init_many_arg(char **arg, int count, t_stack *stack)
{
	while (count >= 0)
	{
		if (is_valid_argument(stack, arg[count]))
		{
			ft_stckaddtop(&stack, ft_stcknew(ft_atoi(arg[count]), 0));
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

extern	t_stack		*ft_stckinit(char **arg, int count)
{
	t_stack		*stack;

	stack = NULL;
	if (arg == NULL || count == 0)
		return (NULL);
	if (count == 1)
		stack = init_one_arg(arg, count, stack);
	else
		stack = init_many_arg(arg, count - 1, stack);
	return (stack);
}
