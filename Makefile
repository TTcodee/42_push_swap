# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 14:48:37 by ppanpais          #+#    #+#              #
#    Updated: 2022/12/15 14:52:22 by ppanpais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	push_swap
SRC_DIR		=	srcs/
CONTAINER_DIR	=	${SRC_DIR}container/
SRC_FILES	=	
OBJ_FILES	=	$(SRC_FILES:.c=.o)
BONUS_OBJ	=	$(BONUS_FILES:.c=.o)
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g -D

all:		$(NAME)
$(NAME):	$(OBJ_FILES)
			ar rc $(NAME) $(OBJ_FILES)
$(OBJ_FILES): 
			$(CC) $(CFLAGS) -c $(SRC_FILES)
$(BONUS_OBJ):
			$(CC) $(CFLAGS) -c $(BONUS_FILES)
clean: 
			rm -f $(OBJ_FILES) $(BONUS_OBJ)
fclean:		clean
			rm -f $(NAME)
re:		fclean all

TEST:		all
			$(CC) -g main.c libft.a -o TEST
bonus:		all $(BONUS_OBJ)
			ar rcs $(NAME) $(BONUS_OBJ)
