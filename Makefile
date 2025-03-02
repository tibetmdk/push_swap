CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	libft_utils/ft_atol.c \
		libft_utils/ft_substr.c \
		libft_utils/ft_strdup.c \
		libft_utils/ft_strlcpy.c \
		libft_utils/ft_error.c \
		libft_utils/ft_printf.c \
		libft_utils/ft_split.c \
		libft_utils/ft_strcpy.c \
		libft_utils/ft_strchr.c \
		libft_utils/ft_strlen.c \
		src/main.c \
		src/number_handler.c\

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