# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -rf

INCLUDES    = -Iinclude -Ilibft

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

OBJ_DIR     = obj

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

# Todos los .c excepto los del bonus
SRC = $(shell find src -type f -name "*.c" ! -path "src/checker_bonus/*")

# Solo bonus
BONUS_SRC = $(shell test -d src/checker_bonus && find src/checker_bonus -type f -name "*.c" || true)
# Objetos
OBJ = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))
BONUS_OBJ = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(BONUS_SRC))

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

# Compilar libft
$(LIBFT):
	@if [ -d "$(LIBFT_DIR)" ]; then \
		$(MAKE) -C $(LIBFT_DIR); \
	else \
		echo "libft not found, skipping..."; \
	fi
# Compilar objetos manteniendo estructura
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# **************************************************************************** #
#                                   CLEAN                                      #
# **************************************************************************** #

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# **************************************************************************** #
#                                   PHONY                                      #
# **************************************************************************** #

.PHONY: all bonus clean fclean re
