NAME1 = push_swap
NAME2 = checker

SRC = ./src
OBJ = ./obj
OBJ2 = ./obj_c
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

SRC_FILES2 = init.c\
			main_checker.c\
			check.c\
			list_operations.c\
			result.c\
			rules.c\
			gnl.c\
			check_true_sort.c\
			free.c

SRCS 		= $(addprefix $(SRC)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJ)/, $(SRC_FILES:c=o))
SRCS2 		= $(addprefix $(SRC)/, $(SRC_FILES2))
OBJS2		= $(addprefix $(OBJ2)/, $(SRC_FILES2:c=o))

INC = -I ./includes
INC_LIB = -I ./libft/includes

LIB_NAME = ./libft/libftprintf.a
LIBS_LINK = -L $(LIB)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

# ***************** targets ***************** #

all: dir swap checker

swap: $(NAME1)

checker: $(NAME2)

dir:
	@mkdir -p $(OBJ) $(OBJ2)
	@make -C $(LIB)


$(NAME1): $(OBJS)
	@gcc $(OBJS) -g $(LIB_NAME) $(LIBS_LINK) -o $(NAME1)
	@echo good compile push_swap!

$(NAME2): $(OBJS2)
	@gcc $(OBJS2) -g $(LIB_NAME) $(LIBS_LINK) -o $(NAME2)
	@echo good compile checker!

$(OBJ)/%.o:$(SRC)/%.c
	@gcc -g $(FLAGS) $(INC_LIB) $(INC) -o $@ -c $<

$(OBJ2)/%.o:$(SRC)/%.c
	@gcc -g $(FLAGS) $(INC_LIB) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ) > /dev/null
	@rm -rf $(OBJ2) > /dev/null
	@make -C $(LIB) clean > /dev/null

fclean: clean
	@rm -rf $(NAME1) > /dev/null
	@rm -rf $(NAME2) > /dev/null
	@make -C $(LIB) fclean > /dev/null

re: fclean all