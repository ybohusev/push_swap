#include "ft_stack.h"

void	ft_stckpop(t_stack **stack)
{
	t_stack *tmp;

	if (!(*stack))
		return ;
	tmp = *stack;
	*stack = tmp->next;
}