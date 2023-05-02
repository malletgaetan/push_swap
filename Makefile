PUSH_SWAP = push_swap
CHECKER = checker
CC = gcc
SRCSDIR = srcs
HEADERSDIR = includes
CFLAGS = -Wall -Werror -Wextra -I $(HEADERSDIR)
AR = ar rcs
RM = rm -f

PUSH_SWAP_SRCS = $(wildcard $(SRCSDIR)/push_swap/*.c)
CHECKER_SRCS = $(wildcard $(SRCSDIR)/checker/*.c)
COMMON_SRCS = $(wildcard $(SRCSDIR)/common/*.c)
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
COMMON_OBJS = $(COMMON_SRCS:.c=.o)

all: $(PUSH_SWAP) $(CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CHECKER): $(CHECKER_OBJS) $(COMMON_OBJS)
	$(CC) -o $@ $^

$(PUSH_SWAP): $(PUSH_SWAP_OBJS) $(COMMON_OBJS) $(LIBFT)
	$(CC) -o $@ $^

clean:
	$(RM) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS) $(COMMON_OBJS)

fclean: clean
	$(RM) $(PUSH_SWAP) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
