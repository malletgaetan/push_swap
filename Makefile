PUSH_SWAP = push_swap
CHECKER = checker
CC = gcc
SRCSDIR = srcs
HEADERSDIR = includes
CFLAGS = -Wall -Werror -Wextra -I $(HEADERSDIR)
AR = ar rcs
RM = rm -f

COMMON_SRCS = $(wildcard $(SRCSDIR)/common/*.c)
PUSH_SWAP_SRCS = $(wildcard $(SRCSDIR)/push_swap/*.c)
CHECKER_SRCS = $(wildcard $(SRCSDIR)/checker/*.c)

all: $(PUSH_SWAP) $(CHECKER)

$(CHECKER): $(CHECKER_SRCS) $(COMMON_SRCS)
	$(CC) $(CFLAGS) -D CHECKER=1 -o $@ $^

$(PUSH_SWAP): $(PUSH_SWAP_SRCS) $(COMMON_SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:

fclean: clean
	$(RM) $(PUSH_SWAP) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
