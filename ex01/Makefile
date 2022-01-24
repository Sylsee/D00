# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 14:54:10 by spoliart          #+#    #+#              #
#    Updated: 2022/01/24 16:16:51 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone

CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	megaphone.cpp
OBJS	=	$(SRCS:%.cpp=%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

$(OBJS): $(SRCS)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm $(OBJS)

fclean:	clean
		rm $(NAME)

re:		fclean all
