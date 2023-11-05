NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address -g

RM = rm -rf

SRCS = 	src/pipex.c \
		libft/libft.a

$(NAME) :
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all
