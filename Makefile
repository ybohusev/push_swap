# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 15:25:37 by ybohusev          #+#    #+#              #
#    Updated: 2018/01/15 15:25:38 by ybohusev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, get_lib get_stack_o

CHECKER = checker

PUSH_SWAP = push_swap

C = gcc

FLAGS += -Wall -Wextra -Werror

LIBFT = ./libft

LIB = ./libft/libft.a

DIR_CHECKER = dir_checker
DIR_PUSH = dir_push_swap
DIR_STACK = stack

DIR_CHECKER_O = ./dir_checker/temporary
DIR_PUSH_O = ./dir_push_swap/temporary
DIR_STACK_O = ./stack/temporary

INCLUDES = ./includes

INCLUDES += -I ./includes
INCLUDES += -I ./libft

SRC_CHECKER = 

SRC_CHECKER += checker.c
SRC_CHECKER += get_instruction.c
SRC_CHECKER += ch_do_inst.c
SRC_CHECKER += ch_check_sort.c
SRC_CHECKER += ch_check_flags.c
SRC_CHECKER += ch_stat.c

SRC_PUSH_SWAP = 

SRC_PUSH_SWAP += ps_basic_algor.c
SRC_PUSH_SWAP += push_swap.c
SRC_PUSH_SWAP += ps_pa_while.c
SRC_PUSH_SWAP += ps_pb_while.c
SRC_PUSH_SWAP += ps_sort_a.c
SRC_PUSH_SWAP += ps_sort_top_a.c
SRC_PUSH_SWAP += ps_pa_all.c
SRC_PUSH_SWAP += ps_rra_while.c
SRC_PUSH_SWAP += ps_rrb_while.c
SRC_PUSH_SWAP += ps_sort_b.c
SRC_PUSH_SWAP += ps_sort_top_b.c

STACK = 

STACK += ft_stckaddback.c
STACK += ft_stckaddtop.c
STACK += ft_stckdel.c
STACK += ft_stckdellast.c
STACK += ft_stckgetmedian.c
STACK += ft_stckinit.c
STACK += ft_stcklen.c
STACK += ft_stckmedianlen.c
STACK += ft_stcknew.c
STACK += ft_stckpop.c
STACK += ft_stckprint.c
STACK += ft_stckpush.c
STACK += ft_stckrevrot.c
STACK += ft_stckrot.c
STACK += ft_stckswap.c
STACK += is_valid_argument.c
STACK += operations.c
STACK += ft_stckissorted.c

SRCS_PUSH = $(addprefix $(DIR_PUSH)/,$(SRC_PUSH_SWAP))
SRCS_CHECKER = $(addprefix $(DIR_CHECKER)/,$(SRC_CHECKER))
SRCS_STACK = $(addprefix $(DIR_STACK)/,$(STACK))

OBJS_PUSH = $(addprefix $(DIR_PUSH_O)/,$(SRC_PUSH_SWAP:.c=.o))
OBJS_STACK = $(addprefix $(DIR_STACK_O)/,$(STACK:.c=.o))
OBJS_CHECKER = $(addprefix $(DIR_CHECKER_O)/,$(SRC_CHECKER:.c=.o))

all: get_lib $(PUSH_SWAP) $(CHECKER)

get_lib:
	@make -C $(LIBFT)

# get_stack_o: $(OBJS_STACK)

$(DIR_STACK_O)/%.o: $(DIR_STACK)/%.c
	@mkdir -p $(DIR_STACK_O)
	@$(C) $(FLAGS) -c -I $(INCLUDES) -o $@ -c $<

$(PUSH_SWAP): $(OBJS_STACK) $(OBJS_PUSH)
	@$(C) $(FLAGS) -o $(PUSH_SWAP) $(OBJS_PUSH) $(OBJS_STACK) $(LIB) -I $(INCLUDES)

$(DIR_PUSH_O)/%.o: $(DIR_PUSH)/%.c
	@mkdir -p $(DIR_PUSH_O)
	@$(C) $(FLAGS) -c -I $(INCLUDES) -o $@ -c $<

$(CHECKER): $(OBJS_STACK) $(OBJS_CHECKER)
	@$(C) $(FLAGS) -o $(CHECKER) $(OBJS_CHECKER) $(OBJS_STACK) $(LIB) -I $(INCLUDES)

$(DIR_CHECKER_O)/%.o: $(DIR_CHECKER)/%.c
	@mkdir -p $(DIR_CHECKER_O)
	@$(C) $(FLAGS) -c -I $(INCLUDES) -o $@ -c $<

clean:
	@rm -rf $(DIR_CHECKER_O)
	@rm -rf $(DIR_PUSH_O)
	@rm -rf $(DIR_STACK_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(PUSH_SWAP) $(CHECKER)
	@make fclean -C $(LIBFT)

re: fclean all