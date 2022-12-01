# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 13:16:56 by afrigger          #+#    #+#              #
#    Updated: 2022/12/01 13:32:18 by afrigger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_memchr.c	ft_strchr.c	ft_strrchr.c \
ft_atoi.c	ft_memcmp.c	ft_strdup.c	ft_strtrim.c \
ft_bzero.c	ft_memcpy.c	ft_striteri.c	ft_substr.c \
ft_calloc.c	ft_memmove.c	ft_strjoin.c	ft_tolower.c \
ft_isalnum.c	ft_memset.c	ft_strlcat.c	ft_toupper.c \
ft_isalpha.c	ft_putchar_fd.c	ft_strlcpy.c \
ft_isascii.c	ft_putendl_fd.c	ft_strlen.c	 \
ft_isdigit.c	ft_putnbr_fd.c	ft_strmapi.c \
ft_isprint.c	ft_putstr_fd.c	ft_strncmp.c \
ft_itoa.c	ft_split.c	ft_strnstr.c\
ft_printchar.c ft_printf.c ft_printhex.c ft_printitoa.c \
ft_printnbr.c ft_printperc.c ft_printunbr.c ft_printptr.c\
ft_printstr.c ft_printunbr.c \
get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OBJS) $(BONUS_OBJS)
		ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean: 
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
		ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re
