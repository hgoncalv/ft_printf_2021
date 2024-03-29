NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra

SRCSFD = ./
SRC = ft_printf.c  \
				ft_flagparsers.c \
				ft_setnbrstr.c \
				ft_setnbrstr_2.c \
				ft_putfunctions.c \
				ft_putfunctions_2.c
OBJSFD = objs/
OBJS = $(addprefix $(OBJSFD), $(SRC:.c=.o))

HDRSFD = ./
HDR = ft_printf.h
HRDS = $(addprefix $(HRDSFD), $(HRD))

HDR_INC = -I./
LIBFT_HDR = -I./libft
LIB_BINARY = -L./libft -lft
LIBFT = libft/libft.a

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

all: check_libft project $(HDRS) $(NAME)
	@echo "Project ready"

$(NAME): $(OBJSFD) $(OBJS) $(LIBFT) $(HDRS)
	@ar rc $(NAME) $(OBJS) libft/*.o
	@ranlib $(NAME)
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ library"

check_libft:
	@echo "Checking libft..."
	@make -C libft

project:
	@echo "Checking project"

$(OBJSFD):
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $(OBJSFD) directory"

$(OBJSFD)%.o: $(SRCSFD)%.c $(HDRS) $(LIBFT)
	@gcc $(CFLAGS) $(HDR_INC) $(LIBFT_HDR) -o $@ -c $<
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

clean:
	@/bin/rm -rf $(OBJSFD)
	@echo "\t[ $(RED)✗$(NONE) ] $(OBJSFD) directory"
	@make -C ./libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\t[ $(RED)✗$(NONE) ] $(NAME) library"
	@make -C ./libft fclean

re: fclean all

.PHONY: check_libft project all clean fclean re
