#include "ft_stack.h"

void	ft_stckpush(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (!(*stack))
	{
		*stack = ft_stcknew(new->content);
		return ;
	}
	new->next = *stack;
	*stack = new;
}