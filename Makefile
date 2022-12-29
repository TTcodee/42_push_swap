# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 14:48:37 by ppanpais          #+#    #+#              #
#    Updated: 2022/12/27 16:13:01 by ppanpais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	push_swap
SRC_DIR		=	srcs/
CONTAINER_DIR	=	${SRC_DIR}container/
ALG_DIR		=	${SRC_DIR}algorithm/
SRC_FILES	=	psw_func.c psw_utils.c
CONTAINER_FILES	=	dlist_utils.c dlist.c stack.c stack_utils.c
ALG_FILES	=	med_finding.c kawaii_sort.c sort.c
SRCS		=	$(CONTAINER_FILES:%=${CONTAINER_DIR}%)	\
				$(ALG_FILES:%=${ALG_DIR}%)	\
				$(SRC_FILES:%=${SRC_DIR}%)
MAIN		=	main.c
OBJ_FILES	=	$(SRC_FILES:.c=.o)	\
				$(CONTAINER_FILES:.c=.o)	\
				$(ALG_FILES:.c=.o)
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
LIBFT		=	libft.a
PSW_LIB		=	psw.a

all:		$(NAME)
test:		$(PSW_LIB)
			$(CC) $(CFLAGS) test.c $(PSW_LIB) -o TEST
$(NAME):	$(PSW_LIB)
			$(CC) $(CFLAGS) $(MAIN) $(PSW_LIB) -o $(NAME)
$(PSW_LIB):	$(OBJ_FILES)
			cp libft/$(LIBFT) $(PSW_LIB)
			ar -rcs $(PSW_LIB) $(OBJ_FILES)
$(OBJ_FILES):	$(LIBFT)
			$(CC) $(CFLAGS) -c $(SRCS)
$(LIBFT):
		make -C libft/
clean: 
			rm -f $(OBJ_FILES) $(PSW_LIB)
			make -C libft/ fclean
fclean:		clean
			rm -f $(NAME)
re:		fclean all
