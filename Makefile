# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 12:10:58 by afrigger          #+#    #+#              #
#    Updated: 2022/12/05 18:15:52 by afrigger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREENGREEN = \033[38;5;46m
RED = \033[0;31m
BLUE = \033[0;34m
GREY = \033[38;5;240m
RESET = \033[0m

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -g
RM = rm -f

DIR_H = headers/
DIR_S =	srcs/
DIR_O =	objs/

# Compile la Libft
DIR_LIBFT = libft/
LIBFT_INC = -I ${DIR_LIBFT}
LIBFT =	${DIR_LIBFT}libft.a
FT_LNK = -L ${DIR_LIBFT} -l ft


LIBS = $(FT_LNK) 

SRCS_LIST = push_swap.c swap.c push.c rotate.c

SRCS = $(addprefix $(DIR_S), $(SRCS_LIST))

OBJS = $(SRCS:$(DIR_S)%.c=$(DIR_O)%.o)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(GREY) ______   __  __     ______     __  __     ______     __     __     ______     ______ $(RESET)"
	@echo "$(RED)/\  == \ /\ \/\ \   /\  ___\   /\ \_\ \   /\  ___\   /\ \  _ \ \   /\  __ \   /\  == \ $(RESET)"
	@echo "$(RED)\ \  _-/ \ \ \_\ \  \ \___  \  \ \  __ \  \ \___  \  \ \ \/  .\ \  \ \  __ \  \ \  _-/ $(RESET)"
	@echo "$(RED) \ \_\    \ \_____\  \/\_____\  \ \_\ \_\  \/\_____\  \ \__/\_ \ \  \_\ \_\ \  \_\ \ $(RESET)"
	@echo "$(GREY)  \/_/     \/_____/   \/_____/   \/_/\/_/   \/_____/   \/_/   \/_/   \/_/\/_/   \/_/ $(RESET)"
	@echo "$(BLUE)                                                                                       $(RESET)"
	${CC} ${LIBS} ${OBJS} -o ${NAME}

$(LIBFT):
	$(MAKE) -sC $(@D)

all: $(NAME)

${DIR_O}%.o:${DIR_S}%.c
	${CC} ${CFLAGS} -I ${DIR_H} ${LIBFT_INC} -o $@ -c $<

clean:
	@echo "$(RED)╔═╗╔═╗╔═╗╔╦╗╔╗ ╦ ╦╔═╗$(RESET)"
	@echo "$(RED)║ ╦║ ║║ ║ ║║╠╩╗╚╦╝║╣$(RESET)"
	@echo "$(RED)╚═╝╚═╝╚═╝═╩╝╚═╝ ╩ ╚═╝$(RESET)"
	$(RM) $(OBJS)

libclean:
	@echo "Clean de libft"
	${MAKE} -sC ${DIR_LIBFT} fclean
	
fclean: clean libclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re