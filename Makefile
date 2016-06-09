# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/27 18:21:52 by mlinhard          #+#    #+#              #
#    Updated: 2016/06/09 15:01:59 by mlinhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FLAGS	= -Wall -Wextra -Werror
FLAGS	=
CC		= gcc $(FLAGS)
INCS 	= -I./incs -I./libft/includes
LIBS	= ./libft
LIBFT 	= -L$(LIBS) -lft
LIBMLX	= -L./minilibx -lmlx -framework OpenGL -framework AppKit
LIBMLX2	= -L./minilibx -lmlx -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit
LANGAGE	= c
NAME	= fdf

SRC_DIR = srcs
OBJ_DIR = objs

LIST 	= ft_fdf \
		ft_fdf_error \
		ft_fdf_free \
		ft_fdf_parse \
		ft_fdf_intro \
		ft_fdf_background \
		ft_fdf_menu \
		ft_fdf_menu_mouseover \
		ft_fdf_ascii \
		ft_fdf_log \
		ft_mlx_loop \
		ft_mlx_hook \
		ft_mlx_draw \
		ft_mlx_handler \
		ft_mlx_mouse \
		ft_mlx_log \

SRC := $(addprefix $(SRC_DIR)/, $(addsuffix .$(LANGAGE), $(LIST)))
OBJ := $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(LIST)))

C_END	= "\033[0m"
C_GOOD	= "\033[32m"
C_GREY  = "\033[1;30m"
C_BAD	= "\033[31m"
C_BLUE	= "\033[34;1m"

all: $(NAME)

$(NAME): $(OBJ)
#@make -C $(LIBS)
	$(CC) $(OBJ) -o $@ $(FLAGS) $(INCS) $(LIBFT) $(LIBMLX)
	@echo "✅  ["$(C_GOOD) $(NAME) $(C_END)"] created"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(LANGAGE)
	@mkdir -p $(dir $@)
	$(CC) $(INCS) -o $@ -c $<

test: $(NAME)
	@echo "✅  ["$(C_GOOD) $(NAME) $(C_END)"] start"
	@./$(NAME)

clean:
#@make clean -C $(LIBS)
	@/bin/rm -rf $(OBJ_DIR)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] $(OBJ_DIR) folder deleted"

clean2:
	@/bin/rm -rf $(OBJ_DIR)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] $(OBJ_DIR) folder deleted"

fclean: clean2
	@/bin/rm -rf *.dSYM
#@make fclean -C $(LIBS)
	@/bin/rm -f $(NAME)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] bin deleted"

#leaks: $(NAME) -leaks
leaks: $(NAME) test

-leaks:
	@-valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

re: fclean libft $(NAME)

.PHONY: all clean clean2 fclean re libft test leaks
