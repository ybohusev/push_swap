/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stckgetmedian.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:13:30 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/19 14:13:32 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

static	void	sort_array(int *ar, int len)
{
	int		i;
	int		tmp;
	int		flag;

	i = 0;
	flag = 1;
	while (i < len - 1)
	{
		if (ar[i] > ar[i + 1])
		{
			flag = 0;
			tmp = ar[i];
			ar[i] = ar[i + 1];
			ar[i + 1] = tmp;
		}
		i++;
	}
	if (flag == 0)
		sort_array(ar, len);
}

static	void	put_median(t_stack *stack, int median, int curr_median)
{
	while (stack && (stack->median == curr_median))
	{
		stack->median = median;
		stack = stack->next;
	}
}

extern	void	ft_stckgetmedian(t_stack *stack)
{
	int		len;
	int		count;
	int		*a;
	t_stack	*tmp;
	int		curr_median;

	if (!stack)
		return ;
	count = 0;
	tmp = stack;
	curr_median = stack->median;
	len = median_len(stack, curr_median);
	a = (int*)malloc(sizeof(int) * len);
	while (tmp && (tmp->median == curr_median))
	{
		a[count] = tmp->content;
		count++;
		tmp = tmp->next;
	}
	sort_array(a, len);
	put_median(stack, a[len / 2], curr_median);
	free(a);
}
