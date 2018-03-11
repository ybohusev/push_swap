#include "ft_stack.h"
#include <stdio.h>

int	main()
{
	int	i;
	t_stack *t;
	t_stack	*tmp;

	t = NULL;
	i = 0;
	tmp = t;
	while (i < 10)
	{
		ft_stckpush(&t, ft_stcknew(i));
		i++;
	}
	while(i > 8)
	{
		ft_stckpop(&t);
		i--;
	}
	while (t)
	{
		printf("%d\n", t->content);
		t = t->next;
	}
	return (0);
}