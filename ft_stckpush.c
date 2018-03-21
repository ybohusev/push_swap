/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:05:11 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/12 17:05:12 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stckpush(t_stack **src, t_stack **dst)
{
	if (*src == NULL)
		return ;
	ft_stckaddtop(dst, ft_stcknew((*src)->content, (*src)->median));
	ft_stckpop(src);
}
