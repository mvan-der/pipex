# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/26 11:48:58 by mvan-der      #+#    #+#                  #
#    Updated: 2022/05/05 13:47:22 by mvan-der      ########   odam.nl          #
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
SRC = commands.c error.c file_handling.c gen_utils.c ft_split.c paths.c pipex.c 

all: $(NAME)
	@echo "${GRN}[Everything is up-to-date]${RST}"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "${GRN}[$(NAME)]${RST}"

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
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
