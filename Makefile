# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/26 11:48:58 by mvan-der      #+#    #+#                  #
#    Updated: 2022/04/26 13:09:27 by mvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

BLU = \033[0;34m
GRN = \033[0;32m
RED = \033[0;31m
RST = \033[0m
END = \e[0m

NAME = pipex

HEADER = includes/pipex.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCDIR = src/
OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
SRC = commands.c error.c file_handling.c paths.c pipex.c

FTPRINTFDIR = ./ft_printf/
FTPRINTFLIB = $(FTPRINTFDIR)libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(FTPRINTFLIB)
	$(CC) $(CFLAGS) $(OBJ) $(FTPRINTFLIB) -o $(NAME)
	@echo "${GRN}[$(NAME)]${RST} done"

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	@mkdir -p $(dir $@)
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

.PHONY: all pipex ft_printf clean flcean re
