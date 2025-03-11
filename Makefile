CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRCS =	libft_utils/ft_atol.c \
		libft_utils/ft_substr.c \
		libft_utils/ft_strdup.c \
		libft_utils/ft_strjoin.c \
		libft_utils/ft_strlcpy.c \
		libft_utils/ft_error.c \
		libft_utils/ft_printf.c \
		libft_utils/ft_split.c \
		libft_utils/ft_strcpy.c \
		libft_utils/ft_strchr.c \
		libft_utils/ft_strlen.c \
		src/main.c \
		src/input_handler.c \
		src/stack_utils.c \
		src/operations.c \
		src/operations_2.c \
		src/turk_sort.c \
		src/sort_utils.c \
		src/cost_a_to_b.c \

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		rm -f $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re