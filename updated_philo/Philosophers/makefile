NAME    = Philosophers
CC      = gcc
FLAGS   = -Wall -Wextra -Werror  -fsanitize=address -fsanitize=undefined -g3 -pthread 
SRC     = 	main_philo.c \
			utils.c \
			utils2.c\
			routine.c \
			clean_up.c \
			initialize.c \
			parsing.c \
			simulation.c
			 
OBJ     = $(SRC:.c=.o)

all: $(NAME)
	@make -s clean
$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $^
	@echo "Philosophers are ready ...!"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re