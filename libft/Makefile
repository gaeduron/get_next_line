# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/19 20:14:23 by gduron            #+#    #+#              #
#*   Updated: 2017/04/04 02:21:32 by bduron           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = \
ft_putchar.c \
ft_putstr.c \
ft_putnbr.c \
ft_strcmp.c \
ft_strlen.c \
ft_strncmp.c \
ft_strlen.c \
ft_strdup.c \
ft_strstr.c \
ft_strcat.c \
ft_strncat.c \
ft_strlcat.c \
ft_strcpy.c \
ft_strncpy.c \
ft_strnstr.c \
ft_strchr.c \
ft_strrchr.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isprint.c \
ft_isalnum.c \
ft_isascii.c \
ft_isspace.c \
ft_tolower.c \
ft_toupper.c \
ft_itoa.c \
ft_atoi.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_putendl.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_memalloc.c \
ft_memdel.c \
ft_strnew.c \
ft_strdel.c \
ft_strclr.c \
ft_striter.c \
ft_striteri.c \
ft_strmap.c \
ft_strmapi.c \
ft_strequ.c \
ft_strnequ.c \
ft_strsub.c \
ft_strjoin.c \
ft_strsplit.c \
ft_strtrim.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lst_push_back.c \
ft_lstmap.c \
ft_lst_at.c \
ft_lst_size.c \
ft_sqrt.c \
ft_pow.c \

CC = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

HEADER = .

VPATH = .

all: $(NAME)

$(NAME): $(SRC)
	@gcc -c $^ $(CC) -I $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compilation:\033[92m OK\033[0m"

clean:
	@echo "Deleting:\033[33m *.o\033[0m"
	@rm -f *.o

fclean: clean
	@echo "Deleting:\033[33m $(NAME)\033[0m"
	@rm -f $(NAME)

re: fclean all
