/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:36:36 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/12 17:36:38 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckrot(t_stack **s)
{
	if (*s == NULL || (*s)->next == NULL)
		return ;
	ft_stckaddback(s, ft_stcknew((*s)->content));
	ft_stckpop(s);
}
