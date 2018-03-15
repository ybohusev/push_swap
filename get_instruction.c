#include "checker.h"

int		nb_inst(char *inst)
{
	int		nb;
	int		count;

	count = 0;
	nb = 0;
	while (inst[count])
	{
		nb += inst[count];
		count++;
	}
	return (nb);
}

int		is_valid_instruction(char *i)
{
	if (!ft_strcmp(i, "sa") || !ft_strcmp(i, "sb") ||
		!ft_strcmp(i, "ss") || !ft_strcmp(i, "pa") ||
		!ft_strcmp(i, "pb") || !ft_strcmp(i, "ra") ||
		!ft_strcmp(i, "rb") || !ft_strcmp(i, "rr") ||
		!ft_strcmp(i, "rra") || !ft_strcmp(i, "rrb") ||
		!ft_strcmp(i, "rrr") || *i == '\0')
		return (1);
	return (0);
}

void	get_instruction(char *inst, t_stack **op)
{
	if (is_valid_instruction(inst))
		ft_stckaddback(op, ft_stcknew(nb_inst(inst)));
	else
	{
		if (*op != NULL)
			ft_stckdel(op);
		write(2, "Error\n", 6);
		exit(1);
	}
}