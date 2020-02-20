# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhaired <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 18:37:53 by lhaired           #+#    #+#              #
#    Updated: 2019/11/26 17:48:05 by lhaired          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra
NAME=libft.a

SRC = ft_atoi.c ft_bzero.c ft_dup.c ft_ftoa.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c  ft_isdigit.c ft_islower.c ft_isprint.c \
	ft_isspace.c ft_isupper.c ft_itoa.c ft_itoa_base.c ft_itoa_long.c \
	ft_itoa_longlong.c ft_itoa_unsigned.c ft_lstadd.c ft_lstdel.c \
	ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
	ft_memset.c ft_numaddone.c ft_numsubone.c ft_putchar.c ft_putchar_fd.c \
	ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	ft_strjoin.c ft_strjoin_free.c ft_strlcat.c ft_strlen.c ft_strmap.c \
	ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
	ft_strnew.c ft_strnstr.c ft_strnumfirstchar.c ft_strnumlastchar.c \
	ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	ft_tolower.c ft_toupper.c ft_swap.c ft_iszero.c ft_ftoa_long.c\

INCLUDES=libft.h
OBJ_DIR=obj
OBJ=$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@ranlib $@

$(OBJ_DIR)/%.o: %.c $(INCLUDES)
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
