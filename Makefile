CC = cc
CFLAGS = -Wall -Werror -Wextra
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
		$(SRCS_DIR)/main.c \



OBJ = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))



.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

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
