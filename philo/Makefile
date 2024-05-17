# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 21:42:05 by jkoupy            #+#    #+#              #
#    Updated: 2024/05/17 20:45:28 by jkoupy           ###   ########.fr        #
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
RM = rm -rf

SRCS =	checker.c \
		libft.c \
		main.c \
		messages.c \
		philosophers.c \
		tasks.c

OBJ_DIR = object/
OBJS =  $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: $(NAME)

object/%.o: source/%.c
	@mkdir -p $(dir $@)
	@printf "$(ORANGE). $(END)";
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS) 
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@printf "\r$(GREEN)🚀 ./$(NAME)      created                                                                     \n$(END)"

clean:
	@$(RM) $(OBJ_DIR)
	@printf "$(RED)💥 object files\tremoved\n$(END)"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)💥 ./$(NAME) \tremoved\n$(END)"

re: _rebuild fclean all

_rebuild:
	@printf "$(ORANGE)🚧 ./$(NAME)\trebuild\n$(END)"

nothing:
	@printf "💩$(BROWN) made $(RED)n$(ORANGE)o$(YELLOW)t$(GREEN)h$(BLUE)i$(INDIGO)n$(VIOLET)g\n$(END)"

run1:
	@printf "noone should die\n"
	@printf "./philo 4 800 300 300\n"
	@./$(NAME) 4 800 300 300

run2:
	@printf "should stop after everyone ate 6 times\n"
	@printf "./philo 4 800 300 300 6\n"
	@./$(NAME) 4 800 300 300 6

run3:
	@printf "one should die\n"
	@printf "./philo 3 800 300 300\n"
	@./$(NAME) 3 800 300 300

run4:
	@printf "one should die right away\n"
	@printf "./philo 4 200 300 300\n"
	@./$(NAME) 4 200 300 300

run5:
	@printf "one should die because of to close to time to die\n"
	@printf "./philo 5 900 500 400\n"
	@./$(NAME) 5 900 500 400

.PHONY: all bonus both clean fclean re _rebuild nothing run