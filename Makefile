# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 17:47:16 by zjaddad           #+#    #+#              #
#    Updated: 2023/01/14 02:01:12 by zjaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
# CFLAGS= -Wall -Wextra -Werror
AR= ar -rc

SRCS=pipex.c Libft/ft_split.c Libft/ft_strncmp.c Libft/ft_substr.c \
	Libft/libft_utils.c parcing.c

NAME=pipex

OBJS= $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	
fclean:
	rm -f $(NAME) $(OBJS)
	
re: fclean all

.PHONY: clean fclean all re