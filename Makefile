# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joe <joe@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 12:04:41 by joe               #+#    #+#              #
#    Updated: 2023/10/07 16:13:31 by joe              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
RM = rm -rf
ECHO = @printf
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread -pthread

SRC_DIR = src/
OBJ_DIR = objects/

SRC =	action \
		action_eat \
		routine \
		forks \
		times \
		get_utils \
		get_utils_2 \
		init \
		main \
		threads \
		utils

#SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))

OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJS)
	$(ECHO) "$(GRN)Compiling philo...$(EOC)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	$(ECHO) "Done!\n"
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(ECHO) "$(GRN)Cleaning objects...$(EOC)\n"
	@$(RM) $(OBJ_DIR) $(NAME)

fclean : clean
	$(ECHO) "$(GRN)Cleaning $(NAME)...$(EOC)\n"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

RED = \033[1;31m
GRN = \033[1;32m
EOC = \033[0m

