NAME=so_long

NAME_BONUS=so_long_bonus

CC=@cc

CFLAGS= -Wall -Wextra -Werror -g3

MFLAGS = -L -lft -lXext -lX11 -lm -lbsd

PATH_SRC = src
PATH_SRC_BONUS = src_bonus
SRC= $(PATH_SRC)/ft_check_map_utils.c\
	 $(PATH_SRC)/ft_check_map.c\
	 $(PATH_SRC)/ft_check_path.c\
	 $(PATH_SRC)/ft_gestion_error.c\
	 $(PATH_SRC)/ft_gestion_init.c\
	 $(PATH_SRC)/ft_hook.c\
	 $(PATH_SRC)/ft_moves.c\
	 $(PATH_SRC)/ft_put_map.c\
	 $(PATH_SRC)/ft_read_map_utils.c\
	 $(PATH_SRC)/ft_read_map.c\
	 $(PATH_SRC)/main.c\

SRC_BONUS = $(PATH_SRC_BONUS)/ft_check_map_utils_bonus.c\
			$(PATH_SRC_BONUS)/ft_check_map_bonus.c\
			$(PATH_SRC_BONUS)/ft_check_path_bonus.c\
			$(PATH_SRC_BONUS)/ft_gestion_error_bonus.c\
			$(PATH_SRC_BONUS)/ft_gestion_init_bonus.c\
			$(PATH_SRC_BONUS)/ft_hook_bonus.c\
			$(PATH_SRC_BONUS)/ft_moves_bonus.c\
			$(PATH_SRC_BONUS)/ft_put_map_bonus.c\
			$(PATH_SRC_BONUS)/ft_read_map_utils_bonus.c\
			$(PATH_SRC_BONUS)/ft_read_map_bonus.c\
			$(PATH_SRC_BONUS)/ft_string_window.c\
			$(PATH_SRC_BONUS)/main_bonus.c\

PATH_MLX = mlx_linux

LIBX = -L mlx_linux -lmlx_Linux
LIBXFLAGS = -lmlx -lXext -lX11

PATH_LIB = lib_dil
LIB = $(PATH_LIB)/libft.a

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all:  $(NAME) $(NAME_BONUS)

bonus:  $(NAME_BONUS)

$(NAME) : $(OBJ)
	@make -s -C $(PATH_MLX)
	@make -s -C $(PATH_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(LIBX) $(LIBXFLAGS) -o $(NAME) -g
	@echo "\nCompilation OK\n"

$(NAME_BONUS) : $(OBJ_BONUS)
	@make -s -C $(PATH_MLX)
	@make -s -C $(PATH_LIB)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB) $(LIBX) $(LIBXFLAGS) -o $(NAME_BONUS) -g
	@echo "\nCompilation Bonus OK\n"

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_MLX)

clean:
	make -C $(PATH_MLX) clean
	make -C $(PATH_LIB) clean
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	make -C $(PATH_LIB) fclean
	make -C $(PATH_MLX) clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY:	all clean fclean re
