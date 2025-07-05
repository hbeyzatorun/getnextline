CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c\
	get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	ar rcs $(NAME)$(OBJS)

%.o:%.c get_next_line.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re