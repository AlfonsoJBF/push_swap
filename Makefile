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
BONUS_DIR = src_bonus/src_bonus
BONUS_COMMON_SRC = $(shell find src -type f -name "*.c" ! -name "main.c")
BONUS_SRC = $(shell test -d $(BONUS_DIR) && find $(BONUS_DIR) -type f -name "*.c" || true)

# Objetos
OBJ = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))
BONUS_COMMON_OBJ = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(BONUS_COMMON_SRC))
BONUS_OBJ = $(patsubst $(BONUS_DIR)/%.c,$(OBJ_DIR)/bonus/%.o,$(BONUS_SRC))

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_COMMON_OBJ) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_COMMON_OBJ) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

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
$(OBJ_DIR)/bonus/%.o: $(BONUS_DIR)/%.c
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
