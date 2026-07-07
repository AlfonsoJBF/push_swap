# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME        := push_swap
BONUS_NAME  := checker

CC          := cc
CFLAGS      ?= -Wall -Wextra -Werror -g
CPPFLAGS    += -Iinclude -Ilibft
AR          := ar
ARFLAGS     := rcs
RM          := rm -f

LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

OBJ_DIR     := obj
SRC_DIR     := src
BONUS_DIR   := src_bonus/src_bonus

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRCS := \
	$(SRC_DIR)/main/main.c \
	$(SRC_DIR)/parseo/parse.c \
	$(SRC_DIR)/parseo/parse_array.c \
	$(SRC_DIR)/parseo/parse_tokens.c \
	$(SRC_DIR)/parseo/parse_flags.c \
	$(SRC_DIR)/parseo/parse_validate.c \
	$(SRC_DIR)/parseo/parse_utils.c \
	$(SRC_DIR)/algorithms/simple_sort.c \
	$(SRC_DIR)/algorithms/algorithms/selection_sort.c \
	$(SRC_DIR)/algorithms/algorithms/k_sort.c \
	$(SRC_DIR)/algorithms/algorithms/chunk_sort.c \
	$(SRC_DIR)/algorithms/algorithms/adaptative_sort.c \
	$(SRC_DIR)/algorithms/utils/compute_disorder.c \
	$(SRC_DIR)/algorithms/utils/move_min_to_top.c \
	$(SRC_DIR)/algorithms/utils/move_max_to_top.c \
	$(SRC_DIR)/algorithms/utils/get_node_position.c \
	$(SRC_DIR)/algorithms/utils/find_min.c \
	$(SRC_DIR)/algorithms/utils/find_max.c \
	$(SRC_DIR)/algorithms/utils/calculate_index.c \
	$(SRC_DIR)/operations/commands/swaps.c \
	$(SRC_DIR)/operations/commands/rotates.c \
	$(SRC_DIR)/operations/commands/reverse_rotates.c \
	$(SRC_DIR)/operations/commands/pushes.c \
	$(SRC_DIR)/operations/primitives/ft_swap.c \
	$(SRC_DIR)/operations/primitives/ft_rotate.c \
	$(SRC_DIR)/operations/primitives/ft_reverse_rotate.c \
	$(SRC_DIR)/operations/primitives/ft_push.c \
	$(SRC_DIR)/stack/ft_program_init.c \
	$(SRC_DIR)/stack/ft_stack_pull.c \
	$(SRC_DIR)/stack/ft_stack_pop.c \
	$(SRC_DIR)/stack/ft_stack_last.c \
	$(SRC_DIR)/stack/ft_stack_init.c \
	$(SRC_DIR)/stack/ft_stack_delete_node.c \
	$(SRC_DIR)/stack/ft_stack_create.c \
	$(SRC_DIR)/stack/ft_stack_addfront.c \
	$(SRC_DIR)/stack/ft_stack_addback.c \
	$(SRC_DIR)/stack/ft_program_close.c \
	$(SRC_DIR)/stack/ft_node_find.c \
	$(SRC_DIR)/stack/ft_node_create.c \
	$(SRC_DIR)/stack/ft_free_stack.c \
	$(SRC_DIR)/stack/ft_bench_init.c \
	$(SRC_DIR)/debug/print_stack.c \
	$(SRC_DIR)/debug/print_program.c \
	$(SRC_DIR)/debug/print_node.c \
	$(SRC_DIR)/debug/print_benchmark.c

OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)

BONUS_SRCS := \
	$(BONUS_DIR)/checker_bonus.c \
	$(BONUS_DIR)/checker_exec_bonus.c \
	$(BONUS_DIR)/checker_read_bonus.c \
	$(BONUS_DIR)/checker_utils_bonus.c

BONUS_OBJS := $(patsubst $(BONUS_DIR)/%.c,$(OBJ_DIR)/bonus/%.o,$(BONUS_SRCS))
BONUS_COMMON_OBJS := $(filter-out $(OBJ_DIR)/src/main/main.o,$(OBJS))
BONUS_ALL_OBJS := $(BONUS_COMMON_OBJS) $(BONUS_OBJS)

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

bonus: $(BONUS_ALL_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_ALL_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/bonus/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# **************************************************************************** #
#                                   CLEAN                                      #
# **************************************************************************** #

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# **************************************************************************** #
#                                   PHONY                                      #
# **************************************************************************** #

.PHONY: all bonus clean fclean re
