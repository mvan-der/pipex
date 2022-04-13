# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/16 16:32:49 by mvan-der      #+#    #+#                  #
#    Updated: 2022/04/12 13:19:55 by mvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEADER = includes/pipex.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FTPRINTFDIR = ./ft_printf/
FTPRINTFLIB = $(FTPRINTFDIR)libftprintf.a

SRCDIR = src/
OBJDIR = obj/
SRC = pipex.c file_open.c

SRCOBJ = $(SRC:%.c=$(OBJDIR)%.o)

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

all: $(NAME)

$(NAME): $(SRCOBJ) $(FTPRINTFLIB)
	$(CC) $(SRCOBJ) -o $(NAME) $(FTPRINTFLIB)
	@echo "${GRN}[$(NAME)]${RST} done"

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(FTPRINTFLIB):
	$(MAKE) -C $(FTPRINTFDIR)
	@echo "${GRN}[FT_PRINTF + LIBFT]${RST} done"

clean:
	rm -rf $(OBJDIR)
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FTPRINTFDIR) $@
	@echo "${GRN}[FCLEAN]${RST} done"

re: fclean all

.PHONY: all pipex ft_printf clean fclean re
