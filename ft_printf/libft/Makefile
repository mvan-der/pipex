# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/06 13:44:38 by mvan-der      #+#    #+#                  #
#    Updated: 2022/01/26 14:03:04 by mvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
ft_toupper.c

SRCOBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCOBJ)
	ar crs $(NAME) $(SRCOBJ)

%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(SRCOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
