CC = cc -fsanitize=address
CFLAGS = -Wall -Werror -Wextra -g
INCLUDES = -I$(INCLUDES_DIR)

NAME = push_swap

SRCS_DIR = ./src
UTILS_DIR = ./utils
PRINTF_DIR = ./printf
INCLUDES_DIR = ./includes

OBJDIR = ./obj





SRCS =	$(PRINTF_DIR)/ft_printf.c \
		$(PRINTF_DIR)/ft_putchar.c \
		$(PRINTF_DIR)/ft_puthex.c \
		$(PRINTF_DIR)/ft_putnbr.c \
		$(PRINTF_DIR)/ft_putptr.c \
		$(PRINTF_DIR)/ft_putstr.c \
		$(PRINTF_DIR)/ft_putunsigned.c \
		$(UTILS_DIR)/list_utils.c \
		$(UTILS_DIR)/input_utils.c \
		$(UTILS_DIR)/push_instructions.c \
		$(UTILS_DIR)/rotate_instructions.c \
		$(UTILS_DIR)/rotate_reverse_instructions.c \
		$(UTILS_DIR)/swap_instructions.c \
		$(UTILS_DIR)/count_moves.c \
		$(UTILS_DIR)/move_node_to_correct_pos.c \
		$(UTILS_DIR)/move_node_helperfunctions.c \
		$(SRCS_DIR)/sorting_algo.c \
		$(SRCS_DIR)/main.c \



OBJ = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))



.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: $(PRINTF_DIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCS_DIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(UTILS_DIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
