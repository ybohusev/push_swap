#ifndef FT_STACK_H
# define FT_STACK_H

# include "libft.h"
# include <stdio.h>

typedef	struct		s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_stcknew(int val);
void				ft_stckpush(t_stack **stack, t_stack *new);
void				ft_stckpop(t_stack **stack);

#endif