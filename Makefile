# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilmahjou <ilmahjou@student.42firenze.it>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 02:29:03 by ilmahjou          #+#    #+#              #
#    Updated: 2025/02/24 02:29:03 by ilmahjou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = push_swap
NAME_BONUS = checker
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I/usr/include -Ilibft
LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a

SRCDIR = source
OPSDIR = operations
BONUSDIR = bonus
OBJ_DIR = obj
OBJ_SRC_DIR = $(OBJ_DIR)/source
OBJ_OPS_DIR = $(OBJ_DIR)/operations
OBJ_BONUS_DIR = $(OBJ_DIR)/bonus

SRC = $(SRCDIR)/finded.c \
      $(SRCDIR)/free.c \
      $(SRCDIR)/initiate.c \
      $(SRCDIR)/prepare_stack_a.c \
      $(SRCDIR)/prepare_stack_b.c \
      $(SRCDIR)/parsing.c \
      $(SRCDIR)/push_swap.c \
      $(OPSDIR)/push.c \
      $(OPSDIR)/reverse_rotate.c \
      $(OPSDIR)/rotate.c \
      $(OPSDIR)/turk_algo.c \
      $(OPSDIR)/sort_three.c \
      $(OPSDIR)/swap.c

BONUS_SRC = $(BONUSDIR)/checker.c \
            $(SRCDIR)/finded.c \
            $(SRCDIR)/free.c \
            $(SRCDIR)/initiate.c \
            $(SRCDIR)/prepare_stack_a.c \
            $(SRCDIR)/prepare_stack_b.c \
            $(SRCDIR)/parsing.c \
            $(OPSDIR)/push.c \
            $(OPSDIR)/reverse_rotate.c \
            $(OPSDIR)/rotate.c \
            $(OPSDIR)/turk_algo.c \
            $(OPSDIR)/sort_three.c \
            $(OPSDIR)/swap.c  # ❌ Removed push_swap.c from here

OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJ_SRC_DIR)/%.o,$(filter $(SRCDIR)/%, $(SRC))) \
          $(patsubst $(OPSDIR)/%.c,$(OBJ_OPS_DIR)/%.o,$(filter $(OPSDIR)/%, $(SRC)))

BONUS_OBJECTS = $(patsubst $(BONUSDIR)/%.c,$(OBJ_BONUS_DIR)/%.o,$(filter $(BONUSDIR)/%, $(BONUS_SRC))) \
                $(patsubst $(SRCDIR)/%.c,$(OBJ_SRC_DIR)/%.o,$(filter $(SRCDIR)/%, $(BONUS_SRC))) \
                $(patsubst $(OPSDIR)/%.c,$(OBJ_OPS_DIR)/%.o,$(filter $(OPSDIR)/%, $(BONUS_SRC)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LIBFT)

$(NAME_BONUS): $(LIBFT) $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) -o $(NAME_BONUS) $(LIBFT)

bonus: $(NAME_BONUS)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(OBJ_SRC_DIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJ_SRC_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_OPS_DIR)/%.o: $(OPSDIR)/%.c
	mkdir -p $(OBJ_OPS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJ_BONUS_DIR)/%.o: $(BONUSDIR)/%.c
	mkdir -p $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
