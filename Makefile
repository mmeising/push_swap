# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 22:33:42 by mmeising          #+#    #+#              #
#    Updated: 2021/12/16 03:42:47 by mmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := gcc
CFLAGS := -Wall -Wextra -Werror -fsanitize=address

SRCS :=	\
	push_swap.c error.c list.c utilities.c assign_vals.c is_sorted.c \
	op_pb.c op_pa.c op_ra.c op_rra.c op_sa.c count_a.c sort_small.c \
	util_get_min_max.c radix.c free_list.c

SRCS := $(SRCS:%=src/%)
OBJ := $(SRCS:src/%.c=obj/%.o)

LIBFT_NAME := libft/lib/libft.a

HEADER := ./header/
LIBFT_HEADER := ./libft/header/

HEADER_FLAGS := -I $(HEADER) -I $(LIBFT_HEADER)
HEADER_FILES := $(HEADER)push_swap.h

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_NAME)
	@$(CC) $(CFLAGS) $(HEADER_FLAGS) $(OBJ) $(LIBFT_NAME) -o $(NAME)

$(LIBFT_NAME):
	@echo Compiling libft
	@make -C ./libft/
	@echo Finished compiling libft

obj/%.o: src/%.c $(HEADER_FILES)
	@echo Compiling $@
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $<)
	@$(CC) $(CFLAGS) $(HEADER_FLAGS) -c $< -o $@
	@echo Finished compiling $@

clean:
	@echo Cleaning...
	@rm -rf obj/
	@printf $(UP)$(CUT)
	@echo Cleaned!
	@echo Cleaning libft...
	@make -C ./libft/ clean
	@printf $(UP)$(CUT)
	@echo Cleaned libft!

fclean: clean
	@echo Cleaning...
	@rm -f $(NAME)
	@printf $(UP)$(CUT)
	@echo Cleaned!
	@echo Cleaning libft...
	@make -C ./libft/ fclean
	@printf $(UP)$(CUT)
	@echo Cleaned libft!

re: fclean all

.PHONY: all clean fclean re