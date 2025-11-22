# =========================
#         push_swap
# =========================

NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -I includes -I $(LIBFT_DIR)/includes

SRC_DIR     = src
LIBFT_DIR   = 42_libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = \
			$(SRC_DIR)/stack/access.c \
			$(SRC_DIR)/stack/push_pop.c \
			$(SRC_DIR)/stack/stack_utils.c \
			$(SRC_DIR)/ops/op_push.c \
			$(SRC_DIR)/ops/op_swap.c \
			$(SRC_DIR)/ops/op_rotate.c \
			$(SRC_DIR)/ops/op_reverse.c \
			$(SRC_DIR)/main.c \
			$(SRC_DIR)/parse.c

OBJS        = $(SRCS:.c=.o)

# =========================
#         rules
# =========================

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Generic compile rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
