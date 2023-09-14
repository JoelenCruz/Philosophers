# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joe <joe@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 12:04:41 by joe               #+#    #+#              #
#    Updated: 2023/09/14 13:05:33 by joe              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	main

CC = cc

ECHO = @printf

HEADERS	= includes

CFLAGS	=	-Wall -Wextra -Werror  -Ofast -march=native -fno-builtin -ftree-vectorize -fstrict-aliasing

OBJ_PATH =	obj

SRC =	main.c	./src/ultis.c

OBJ = $(SRC:.c=.o)


all : $(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@


$(NAME) : $(LIBS) $(OBJ)
	$(ECHO) "$(GRN)Linking $(NAME)...$(EOC)\n"
	$(CC) $^ -o $@ $(CFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(ECHO) "$(GRN)Making $@ with \"$(CFLAGS) 
	@mkdir -p $(OBJ_PATH) 2> /dev/null

clean :
	$(ECHO) "$(RED)Cleaning objects...$(EOC)\n"
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	$(ECHO) "$(RED)Cleaning $(NAME)...$(EOC)\n"
	rm -f $(NAME)

re : fclean all

.PHONY: all clean re fclean

#COLORS
RED = \033[1;31m
GRN = \033[1;32m
EOC = \033[0m
