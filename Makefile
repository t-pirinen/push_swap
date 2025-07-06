

NAME = push_swap

CC = cc -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRC_PATH = src/
OBJ_PATH = obj/

SRC = main.c test.c
SRCS = $(addprefix src/, $(SRC))

OBJ = $(SRC:.c=.o)
OBJS = $(addprefix obj/, $(OBJ))


all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) -c $^ -o $@

$(LIBFT):
	make -s -C libft

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@rm -rf obj
	@make clean -s -C libft
	@echo "PUSH_SWAP: Removed object files"

fclean: clean
	@rm -rf push_swap
	@make fclean -s -C libft
	@echo "PUSH_SWAP: Removed executable"

re: clean all

.PHONY: all clean fclean re