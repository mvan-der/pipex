# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/26 11:48:58 by mvan-der      #+#    #+#                  #
#    Updated: 2022/05/13 14:20:21 by mvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

BLU = \033[0;34m
GRN = \033[0;32m
RED = \033[0;31m
RST = \033[0m
END = \e[0m

NAME = pipex

HEADER = pipex.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I includes

SRCDIR = src/
OBJDIR = obj/
SRC = str_utils.c ft_split.c main.c parsing.c pipex.c
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)
	@echo "${GRN}[Everything is up-to-date]${RST}"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "${GRN}[$(NAME)]${RST}"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	@echo "${GRN}[CLEAN]${RST}"

fclean: clean
	rm -f $(NAME)
	@echo "${GRN}[FCLEAN]${RST}"

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
