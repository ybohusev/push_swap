/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:53:24 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/17 13:53:25 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_stack.h"

void	basic_algor(t_stack *a, t_stack *b, int flag);
void	sort_a(t_stack **a, t_stack **b);
int		pb_while(t_stack **a, t_stack **b);
int		pa_while(t_stack **a, t_stack **b);
void	rra_while(t_stack **a, t_stack **b, int count);
void	rrb_while(t_stack **a, t_stack **b, int count);
void	pa_all(t_stack **a, t_stack **b);
void	sort_top_a(t_stack **a, t_stack **b);

#endif
