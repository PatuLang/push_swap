# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plang <plang@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 10:08:48 by plang             #+#    #+#              #
#    Updated: 2024/08/05 14:49:14 by plang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= @cc

CFLAGS		= -Werror -Wextra -Wall

LIBFT_PATH	= ./libft

LIBFT		= $(LIBFT_PATH)/libft.a

SRCS		= src/push_swap.c \
				src/actions.c \
				src/a_actions.c \
				src/b_actions.c \
				src/check_input.c \
				src/make_stack.c \
				src/sort_stack.c \
				src/short_sort.c \
				src/error_functions.c

OBJS		= $(SRCS:.c=.o)

all:			$(NAME)

$(LIBFT):
	@make -C		$(LIBFT_PATH)

$(NAME):		$(LIBFT) $(OBJS)
	$(CC)		$(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Program compiled!"

clean:
	@rm -f		$(OBJS)
	@make -C	$(LIBFT_PATH) fclean
	@echo "Removed -o files"

fclean:	clean
	@rm -f		$(NAME)
	@echo "Removed program!"

re:	fclean		$(NAME)

.PHONY:	all clean fclean re libft
