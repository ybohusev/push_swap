/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:53:58 by ybohusev          #+#    #+#             */
/*   Updated: 2018/03/16 19:54:00 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_stack.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef	struct	s_flags
{
	int			v;
	int			s;
}				t_flags;

void			get_instruction(char *inst, t_stack **op);
void			do_inst(t_stack **a, t_stack **b, t_stack *inst, int v);
void			check_sort(t_stack *a, t_stack *b);
t_flags			check_flags(char ***argv, int *argc);
void			stat(t_stack *inst);

#endif
