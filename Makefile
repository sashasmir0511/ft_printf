# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhaired <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 10:47:29 by lhaired           #+#    #+#              #
#    Updated: 2020/02/04 10:47:32 by lhaired          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = analysis.c date_iso.c digit_double_processing.c digit_int_processing.c \
	digit_uint_processing.c ft_printf.c output_parameter.c \
	transfer_o_x_b.c type_s_c.c digit_redactor.c color.c str_redactor.c\

OBJ = $(SRC:.c=.o)

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
TST_DIR = test

SRCS=$(addprefix $(SRC_DIR)/,$(SRC))

OBJS=$(addprefix $(OBJ_DIR)/,$(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@ar rcs $@ $^
	@ranlib $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -I $(INC_DIR) $< -o $@


clean:
	@make clean -C libft
	@/bin/rm -rf $(OBJ)
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

test: all
	@mv $(TST_DIR)/main.c .
	@$(CC) $(CFLAGS) main.c -L. -lftprintf
	@mv main.c $(TST_DIR)/.

norme:
	norminette ./libft
	@echo
	norminette ./src
	@echo
	norminette ./include

git: fclean
	git add *
	git commit -m "auto git"
	git push
