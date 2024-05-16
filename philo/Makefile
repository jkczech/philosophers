# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 21:42:05 by jkoupy            #+#    #+#              #
#    Updated: 2024/05/16 22:25:53 by jkoupy           ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -Werror -g -pthread #-fsanitize=thread
DEPFLAGS =-MT $@ -MMD -MP -MF $(OBJ_DIR)/$*.d
RM = rm -rf

SRCS =	checker.c \
		libft.c \
		main.c \
		messages.c \
		philosophers.c

OBJ_DIR = object/
OBJS =  $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: $(NAME)

object/%.o: source/%.c
	@mkdir -p $(dir $@)
	@printf "$(ORANGE). $(END)";
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS) 
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@printf "\r$(GREEN)🚀 ./$(NAME)          created                                                                     \n$(END)"

clean:
	@$(RM) $(OBJ_DIR)
	@printf "$(RED)💥 object files\t\tremoved\n$(END)"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)💥 ./$(NAME) \t\tremoved\n$(END)"

re: _rebuild fclean all

_rebuild:
	@printf "$(ORANGE)🚧 ./$(NAME)\t\trebuild\n$(END)"

nothing:
	@printf "💩$(BROWN) made $(RED)n$(ORANGE)o$(YELLOW)t$(GREEN)h$(BLUE)i$(INDIGO)n$(VIOLET)g\n$(END)"

run:
	@./$(NAME) 4 800 200 200 6

.PHONY: all bonus both clean fclean re _rebuild nothing run