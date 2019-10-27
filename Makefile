NAME = push_swap

SRC = ./src
OBJ = ./obj
LIB = ./libft

SRC_FILES = main.c\
			init.c\
			check.c\
			list_operations.c\
			result.c\
			rules.c\
			sort.c\
			turns.c\
			steps.c\
			pre_sort.c\
			final_sort.c\
			check_true_sort.c\
			free.c

SRCS 		= $(addprefix $(SRC)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJ)/, $(SRC_FILES:c=o))

INC = -I ./includes
INC_LIB = -I ./libft/includes

LIB_NAME = ./libft/libftprintf.a
LIBS_LINK = -L $(LIB)

FLAGS = #-Wall -Wextra -Werror

.PHONY: all clean fclean re

all: DIR $(NAME)

DIR:
	@mkdir -p $(OBJ)
	@make -C $(LIB)

$(NAME): $(OBJS)
	@gcc $(OBJS) -g $(LIB_NAME) $(LIBS_LINK) -o $(NAME)
	@echo good compile!


$(OBJ)/%.o:$(SRC)/%.c
	@gcc -g $(FLAGS) $(INC_LIB) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ) > /dev/null
	@make -C $(LIB) clean > /dev/null

fclean: clean
	@rm -rf $(NAME) > /dev/null
	@make -C $(LIB) fclean > /dev/null

re: fclean all