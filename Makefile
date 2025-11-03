# =========================
#         push_swap
# =========================

NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC_DIR     = src
LIBFT_DIR   = 42_libft
LIBFT       = $(LIBFT_DIR)/libft.a

# --- sources (explicit, no wildcards) ---
SRC         = $(SRC_DIR)/push_swap.c
OBJ         = $(SRC:.c=.o)

# =========================
#         rules
# =========================

all: $(LIBFT) $(NAME)

# Always ensure libft is built with BONUS.
# This command runs every time, but it only updates libft.a if needed.
$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIR) bonus

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compile .c -> .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

# Convenience target if you want to call it explicitly
bonus: all

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

FORCE:

.PHONY: all bonus clean fclean re FORCE
