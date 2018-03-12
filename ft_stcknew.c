/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcknew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:07:56 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/12 15:07:58 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack		*ft_stcknew(int val)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if(!new)
		return (NULL);
	new->content = val;
	new->next = NULL;
	return (new);
}
