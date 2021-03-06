/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:07:24 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/16 18:07:25 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckprint(t_stack *stack, char *s_name)
{
	char	*tmp;

	ft_putstr("\033[33m*******\033[37m\n");
	if (!stack)
		ft_putstr("\033[36mempty\033[37m\n");
	while (stack)
	{
		tmp = ft_itoa(stack->content);
		ft_putstr(tmp);
		ft_putstr("\n");
		free(tmp);
		stack = stack->next;
	}
	ft_putstr("\033[33m_______\033[31m\n");
	ft_putstr(s_name);
	ft_putstr("\033[37m\n");
}
