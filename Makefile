# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgomez-b <dgomez-b@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 00:00:00 by dgomez-b          #+#    #+#              #
#    Updated: 2024/09/15 00:00:00 by dgomez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
INC			=	./includes/
BIN			=	./.bin/
SRC			=	./src/
SRCS		=	main.c \
				stack_functions.c \
				stack_error_functions.c \
				argument_functions.c \
				argument_error_functions.c \
				move_functions.c \
				order_functions.c \
				order_functions2.c
OBJS		=	$(addprefix $(BIN), $(SRCS:.c=.o))
LIBFT		=	$(INC)libft/libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3

all			:	$(NAME)
$(BIN)%.o	:	$(SRC)%.c
				@ mkdir -p $(BIN)
				@ $(CC) $(CFLAGS) -c -o $@ $^ -I$(INC)
%.a			:
				@ make -sC $(dir $@)
$(NAME)		:	$(LIBFT) $(OBJS)
				@ $(CC) $(CFLAGS) -o $@ $^ -L$(dir $(LIBFT)) -lft
				@ echo Program compilled
clean		:
				@ make -sC $(dir $(LIBFT)) clean
				@ rm -f $(OBJS)
				@ rm -rf $(BIN)
				@ echo Program object files deleted
fclean		:
				@ make -sC $(dir $(LIBFT)) fclean
				@ rm -f $(OBJS)
				@ echo Program object files deleted
				@ rm -f $(NAME)
				@ rm -rf $(BIN)
				@ echo Program deleted
re			:	fclean all
.PHONY		:	all clean fclean re
