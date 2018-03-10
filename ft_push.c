#include "ft_stack.h"

void	ft_push(t_stack **stack, t_stack *new)
{
	t_stack *tmp;

	tmp = *stack;
	if (!new)
		return ;
	while (tmp)
		tmp = tmp->next;
	tmp = new;
}