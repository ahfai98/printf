CLFAGS = -Wall -Wextra -Werror
RM = rm -rf
CC = cc
AR = ar rcs
SRC_DIR = src
SRCB_DIR = srcb
INC_DIR = inc
OBJ_DIR = obj
OBJB_DIR = objb
LIBFT = libft.a
LIBFT_DIR = libft
NAME = libftprintf.a

SRC = 	ft_printf.c\
		ft_format.c\
		ft_parse.c\
		ft_print_chars.c\
		ft_print_numbers.c\
		ft_print_unsigned_numbers.c\
		ft_print_pointer.c\
		ft_print_hex.c

SRCB = 	ft_printf_bonus.c\
		ft_format_bonus.c\
		ft_parse_bonus.c\
		ft_print_chars_bonus.c\
		ft_print_numbers_bonus.c\
		ft_print_unsigned_numbers_bonus.c\
		ft_print_pointer_bonus.c\
		ft_print_hex_bonus.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJB = $(addprefix $(OBJB_DIR)/, $(SRCB:.c=.o))

all : $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJ) $(OBJB)
	$(AR) $(NAME) $(OBJ) $(OBJB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c | $(OBJB_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJB_DIR):
	mkdir -p $(OBJB_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) .
	mv $(LIBFT) $(NAME)

clean:
	$(RM) $(OBJ_DIR) $(OBJB_DIR)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
