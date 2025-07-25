

NAME = push_swap
HEADER = libpushswap.h

CC = cc -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRC_PATH = src/
OBJ_PATH = obj/

SRC = main.c checks_and_exit.c push_swap_rotate.c sorting.c stacks.c
SRCS = $(addprefix src/, $(SRC))

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix obj/, $(OBJ))


all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) -c $^ -o $@

$(LIBFT):
	make -C libft -s

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -rf obj
	make clean -C libft -s

fclean: clean
	rm -rf push_swap
	make fclean -C libft -s

re: clean all

.PHONY: all clean fclean re