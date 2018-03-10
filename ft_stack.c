#include "ft_stack.h"
#include <stdio.h>

int	main()
{
	int	i;
	t_stack *t;

	t = NULL;
	i = 0;
	while (i < 10)
	{
		ft_push(&t, ft_stcknew(i));
		i++;
	}
	while (t)
	{
		printf("%d\n", t->content);
		t = t->next;
	}
	return (0);
}