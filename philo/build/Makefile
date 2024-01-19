# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 15:00:45 by jkoupy            #+#    #+#              #
#    Updated: 2024/01/19 16:08:18 by jkoupy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[38;5;196;1m
ORANGE = \033[38;5;208;1m
YELLOW = \033[38;5;226;1m
GREEN = \033[38;5;082;1m
BLUE = \033[38;5;027;1m
INDIGO = \033[38;5;093;1m
VIOLET = \033[38;5;163;1m
WHITE = \033[38;5;231;1m
BROWN = \033[38;5;137;1m
END = \033[0m

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
#DEPFLAGS =-MT $@ -MMD -MP -MF $(OBJ_DIR)/$*.d
RM = rm -rf

SRCS = ft_atoi.c main.c messages.c philo.c
OBJ_DIR = ../object/
OBJS =  $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
#DEPS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.d))

all: $(NAME)

../object/%.o: ../source/%.c 
	@mkdir -p $(dir $@)
	@printf "$(ORANGE).$(END)";
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS) 
	@$(CC) $(OBJS) $(CC_FLAGS) -o $(NAME)
	@printf "\r$(GREEN)🚀 ./$(NAME)       created              \n$(END)"

clean:
	@$(RM) $(OBJ_DIR)
	@printf "$(RED)💥 object files\t removed\n$(END)"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)💥 ./$(NAME) \t removed\n$(END)"

re: _rebuild fclean all

_rebuild:
	@printf "$(ORANGE)🚧 ./$(NAME)\t rebuild\n$(END)"

nothing:
	@printf "💩$(BROWN) made $(RED)n$(ORANGE)o$(YELLOW)t$(GREEN)h$(BLUE)i$(INDIGO)n$(VIOLET)g\n$(END)"

#-include $(DEPS)

.PHONY: all clean fclean re _rebuild nothing