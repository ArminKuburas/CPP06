# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 06:00:58 by akuburas          #+#    #+#              #
#    Updated: 2024/10/10 06:19:35 by akuburas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11 -g

NAME = convert

SRCS = main.cpp ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(C++) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(C++) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re