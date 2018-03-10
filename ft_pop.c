#include "ft_stack.h"

void	ft_pop(t_stack **stack)
{
	t_stack *tmp;

	if (!stack)
		return ; 
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp = NULL;
}