# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/06 13:44:38 by mvan-der      #+#    #+#                  #
#    Updated: 2022/04/18 12:39:08 by mvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = includes/ft_printf.h
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRCS = ft_conv_csdi.c ft_conv_puxX.c ft_printf.c ft_put_printf.c ft_spec_conv.c \
ft_itoa_printf.c ft_utoa_printf.c

SRCDIR = src/
OBJDIR = obj/
SRCOBJ = $(SRCS:%.c=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(SRCOBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar crs $(NAME) $(SRCOBJ)

$(OBJDIR)%.o : $(SRCDIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft $@ 

re: fclean all

.PHONY: all libft clean fclean re
