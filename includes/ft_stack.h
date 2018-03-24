/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:07:41 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/12 15:07:43 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "libft.h"
# include <stdio.h>

typedef	struct		s_stack
{
	int				content;
	int				median;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_stcknew(int val, int median);
void				ft_stckaddtop(t_stack **stack, t_stack *new);
void				ft_stckpop(t_stack **stack);
t_stack				*ft_stckinit(char **arg, int count);
void				ft_stckswap(t_stack *s);
void				ft_stckpush(t_stack **s1, t_stack **s2);
void				ft_stckrot(t_stack **s);
void				ft_stckaddback(t_stack **stack, t_stack *new);
void				ft_stckrevrot(t_stack **s);
void				ft_stckdellast(t_stack **stack);
void				ft_stckdel(t_stack **stack);
void				ft_stckprint(t_stack *stack, char *s_name);
int					ft_stcklen(t_stack *stack);
void				ft_stckgetmedian(t_stack *stack);
int					is_sorted(t_stack *a);

void				sa_sb_ss(t_stack *a, t_stack *b, char mode, int pr);
void				pa_pb(t_stack **a, t_stack **b, char mode, int pr);
void				ra_rb_rr(t_stack **a, t_stack **b, char mode, int pr);
void				rra_rrb_rrr(t_stack **a, t_stack **b, char mode, int pr);
void				print_a_b(t_stack *a, t_stack *b);

int					is_valid_argument(t_stack *stack, char *arg);

int					median_len(t_stack *stack, int curr_median);
void				ft_stckgetmedian(t_stack *stack);

#endif
