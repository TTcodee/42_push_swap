# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 18:30:06 by ppanpais          #+#    #+#              #
#    Updated: 2022/09/14 13:14:59 by ppanpais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRC_FILES	=	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c \
				ft_memset.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
				ft_memcmp.c ft_toupper.c ft_tolower.c ft_strchr.c \
				ft_strrchr.c ft_memchr.c ft_strncmp.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
				ft_putendl_fd.c ft_putnbr_fd.c
BONUS_FILES	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c
OBJ_FILES	=	$(SRC_FILES:.c=.o)
BONUS_OBJ	=	$(BONUS_FILES:.c=.o)
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

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
