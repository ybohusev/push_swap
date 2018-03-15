#ifndef CHECKER_H
# define CHECKER_H

# include "ft_stack.h"

# define SA 212
# define SB 213
# define SS 230
# define PA 209
# define PB 210
# define RA 211
# define RB 212
# define RR 228
# define RRA 325
# define RRB 326
# define RRR 342

void	get_instruction(char *inst, t_stack **op);
int		is_valid_instruction(int nb);
int		nb_inst(char *inst);

#endif