/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:47:19 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/12 16:47:20 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckswap(t_stack *s)
{
	int		a;

	if (s == NULL || s->next == NULL)
		return ;
	a = s->content;
	s->content = s->next->content;
	s->next->content = a;
}
