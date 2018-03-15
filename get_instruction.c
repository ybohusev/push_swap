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

int		is_valid_instruction(int nb)
{
	printf("HERE %d\n", nb);
	if (!nb || nb != SA || nb != SB ||
		nb != SS || nb != PA ||
		nb != PB || nb != RA ||
		nb != RB || nb != RR ||
		nb != RRA || nb != RRB ||
		nb != RRR)
		return (0);
	return (1);
}

void	get_instruction(char *inst, t_stack **op)
{
	int		nb;

	nb =  nb_inst(inst);
	if (is_valid_instruction(nb))
		ft_stckaddback(op, ft_stcknew(nb));
	else
	{
		if (*op != NULL)
			ft_stckdel(op);
		write(2, "Error\n", 6);
		exit(1);
	}
}