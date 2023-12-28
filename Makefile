CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = vector
CFILES = main.c __cvector_utils_.c __cvector_utils__.c

SRCS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $^

fclean:
	rm -rf $(NAME) $(SRCS)

re: fclean all