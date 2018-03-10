#include "ft_stack.h"

t_stack		*ft_stcknew(int val)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if(!new)
		return (NULL);
	new->content = val;
	new->next = NULL;
	return (new);
}