# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/16 16:32:49 by mvan-der      #+#    #+#                  #
#    Updated: 2022/04/10 16:23:48 by mvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEADERS = pipex.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FTPRINTFDIR = ./ft_printf/
FTPRINTFLIB = $(FTPRINTFDIR)libftprintf.a

SRCS = pipex.c

SRCOBJ = $(SRCS:.c=.o)

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

all: $(NAME) $(FTPRINTFLIB)

$(NAME): $(SRCOBJ) $(FTPRINTFLIB)
	$(CC) $(SRCOBJ) -o $(NAME) $(FTPRINTFLIB)
	@echo "${GRN}[$(NAME)]${RST} done"
	
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(FTPRINTFLIB):
	$(MAKE) -C $(FTPRINTFDIR)
	@echo "${GRN}[FT_PRINTF + LIBFT]${RST} done"

clean:
	rm -f $(SRCOBJ)
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FTPRINTFDIR) $@
	@echo "${GRN}[FCLEAN]${RST} done"

re: fclean all

.PHONY: all pipex ft_printf clean fclean re
