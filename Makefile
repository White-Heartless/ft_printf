NAME = libftprintf.a
HEADER = ./includes/libftprintf.h
AR = ar -rcs
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = ft_printf.c ft_found_conversion.c ft_found_percent.c ./conversions/ft_di_conversion.c
#BSRCS = 
OBJS = $(SRCS:.c=.o)
#BOBJS = $(BSRCS:.c=.o)


all: libft $(NAME)

libft: 
		(cd ./libft && make object)

$(NAME): 
		$(CC) -r -nostdlib $(CFLAGS) $(SRCS) $(BSRCS) -o libftprintf.o
		ar -rc libftprintf.a libftprintf.o ./libft/libft.o

#bonus: $(BOBJS) $(OBJS)
#						$(AR) $(NAME) $^

%.o : %.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

clean:
		(cd ./libft && rm -rf *.o)
		$(RM) $(OBJS) $(BOBJS) libftprintf.o

fclean: clean
			(cd ./libft && rm -rf *.a)
			$(RM) $(NAME)

re: fclean all

build: 
	$(CC) $(CFLAGS) $(NAME) $(SRCS) ./libft/libft.a

.PHONY: clean fclean re libft
