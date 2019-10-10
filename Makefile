NAME = fillit

CC = gcc

FLAGS = -Wall -Werror -Wextra

INC = fillit.h

SRCS =  calc.c\
		convert.c\
		crop.c\
		init.c\
		map.c\
		solve.c\
		main.c\
		free.c

OBJS = $(SRCS:.c=.o)

LIB = Libft/

all: $(NAME)

$(NAME): $(OBJS) 
	@make -C $(LIB)
	@$(CC) -L$(LIB) -lft $^ -o $@

clean: 
	@make clean -C $(LIB)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS) -I$(INC)
