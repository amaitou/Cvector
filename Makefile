CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = cvector.a
CFILES = __cvector_utils_.c __cvector_utils__.c __cvector_utils___.c

SRCS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	@$(AR) rcs $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(SRCS)

fclean:
	rm -rf $(NAME) $(SRCS) *.out

re: fclean all
