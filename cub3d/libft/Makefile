# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/15 16:48:11 by anatashi          #+#    #+#              #
#    Updated: 2020/10/13 19:19:56 by anatashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

DIR	= srcs/
LIST =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_strdup_gnl.c get_next_line.c ft_strjoin_gnl.c read_new_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c	ft_lstmap.c\
		ft_lstdelone_f.c ft_putendl.c ft_putstr.c ft_putchar.c ft_strndup.c \
		ft_strlenchar.c ft_strnjoin.c ft_free_tmp.c ft_str_add_char.c ft_freearrpoint.c \
		ft_isspace.c ft_min.c ft_binary_tree_sorting.c ft_strnstrindex.c

SOURCE = $(addprefix $(DIR), $(LIST))
OBJ	= $(patsubst %.c, %.o, $(SOURCE))
D_FILE = $(patsubst %.c, %.d, $(SOURCE))

CC = gcc
OPFLAGS = -O2
FLAGS = -Wall -Wextra -Werror
HEADER = header/

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(OPFLAGS) -I$(HEADER) -c $< -o $@ -MD

include $(wildcard $(D_FILE))

clean:
	rm -rf $(OBJ) $(D_FILE)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	
test: 
	@gcc -g main.c -L. libft.a -o prog
	@./prog

grind:
	@gcc -g main.c -L. libft.a -o prog
	@valgrind --leak-check=full ./prog
