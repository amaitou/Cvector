CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = cvector.a
SRC_DIR = ./sources
INCLUDE_DIR = ./includes

CFILES = $(wildcard $(SRC_DIR)/*.c)
SRCS = $(CFILES:.c=.o)

all: $(INCLUDE_DIR)/cvector_v.h $(NAME)

$(NAME): $(SRCS)
	@echo "\033[1;37mArchiving\033[0m \033[1;30m*.o to cvector.a\033[0m"
	@$(AR) rcs $@ $^

./$(SRC_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDE_DIR)/cvector_v.h
	@echo "Compiling --> \033[1;35m$?\033[0m"
	@$(CC) $(CFLAGS) $< -c -o $@

clean:
	@echo "\033[1;31mDeleting only *.o\033[0m"
	@rm -rf $(SRC_DIR)/*.o a.out

fclean: clean
	@echo "\033[38;2;224;17;95mDeleting cvector.a\033[0m"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean

