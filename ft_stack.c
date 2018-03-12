/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:07:47 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/12 15:07:48 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdio.h>

int	main(int argc, char **argv)
{

	t_stack *a;
	t_stack	*b;
	t_stack	*tmp;

	a = ft_stckinit(argv, argc - 1);
	ft_stckpush(&a, &b);
	tmp = a;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("_\na\n");
	tmp = b;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("_\nb\n");
	ft_stckdel(&a);
	system("leaks test");
	return (0);
}
