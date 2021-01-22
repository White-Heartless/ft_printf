NAME = libftprintf.a
HEADER = ./includes/libftprintf.h
AR = ar -rc
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = ft_printf.c ft_found_percent.c ft_found_conversion.c ./conversions/ft_di_conversion.c
#BSRCS = 
OBJS = $(SRCS:.c=.o)
#BOBJS = $(BSRCS:.c=.o)


all: libft $(NAME)

libft: 
		(cd ./libft && make bonus)

$(NAME): $(OBJS)
				$(AR) $@ ./libft/libft.a $^

#bonus: $(BOBJS) $(OBJS)
#						$(AR) $(NAME) $^

%.o : %.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

clean: 
		(cd ./libft && rm -rf *.o)
		$(RM) $(OBJS) $(BOBJS)

fclean: clean
			(cd ./libft && rm *.a)
			$(RM) $(NAME)

re: fclean all

build: 
	$(CC) $(CFLAGS) $(HEADER) $(SRCS) ./libft/libft.a

.PHONY: clean fclean re libft
