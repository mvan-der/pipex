# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/06 13:44:38 by mvan-der      #+#    #+#                  #
#    Updated: 2022/03/17 14:12:23 by mvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADERS = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRCS = ft_conv_csdi.c ft_conv_puxX.c ft_printf.c ft_put_printf.c ft_spec_conv.c \
ft_itoa_printf.c ft_utoa_printf.c

SRCOBJ = $(SRCS:.c=.o)

all: $(NAME) $(LIBFT)

$(NAME): $(SRCOBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar crs $(NAME) $(SRCOBJ)

%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) -o $@ $<

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	rm -f $(SRCOBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft $@ 

re: fclean all

.PHONY: all libft clean fclean re
