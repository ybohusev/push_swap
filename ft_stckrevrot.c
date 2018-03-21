/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckrevrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:28:42 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/12 18:28:43 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckrevrot(t_stack **s)
{
	t_stack	*tmp;

	tmp = *s;
	if (*s == NULL || (*s)->next == NULL)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	ft_stckaddtop(s, ft_stcknew(tmp->content, tmp->median));
	ft_stckdellast(s);
}
