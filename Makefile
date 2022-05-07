# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/26 11:48:58 by mvan-der      #+#    #+#                  #
#    Updated: 2022/05/07 15:20:43 by mvan-der      ########   odam.nl          #
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
SRC = commands.c file_path.c gen_utils.c ft_split.c pipex.c 
BONUS_SRC = commands.c file_path.c gen_utils.c ft_split.c pipex_bonus.c 

ifdef BONUS
OBJ = $(addprefix $(OBJDIR), $(BONUS_SRC:.c=.o))
else
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
endif

all: $(NAME)
	@echo "${GRN}[Everything is up-to-date]${RST}"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "${GRN}[$(NAME)]${RST}"

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	$(MAKE) BONUS=1 all

clean:
	rm -rf $(OBJDIR)
	@echo "${GRN}[CLEAN]${RST}"

fclean: clean
	rm -f $(NAME)
	@echo "${GRN}[FCLEAN]${RST}"

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
