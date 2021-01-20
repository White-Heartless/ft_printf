NAME = ft_printf.a
HEADER = ./includes/ft_printf.h
AR = ar -rc
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = ft_printf.c
#BSRCS = 
OBJS = $(SRCS:.c=.o)
#BOBJS = $(BSRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
				$(AR) $@ $^

#bonus: $(BOBJS) $(OBJS)
#						$(AR) $(NAME) $^

%.o : %.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

clean: 
		$(RM) $(OBJS) $(BOBJS)

fclean: clean
			$(RM) $(NAME)

re: fclean all

build: 
	$(CC) $(CFLAGS) $(HEADER) $(SRCS) ./libft/libft.a

.PHONY: clean fclean re
