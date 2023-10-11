NAME			= cub3d

NAME_BONUS		= cub3d_bonus

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -g3

MFLAGS 			=  -L -lft -lXext -lX11 -lbsd -lm

PATH_MLX 		= library/minilibx-linux
LIBX 			= -L library/minilibx-linux -lmlx_Linux
LIBXFLAGS 		= -lmlx -lXext -lX11

PATH_LIBFT		= library/libft
LIBFT 			= library/libft/libft.a

OBJDIR	= obj/
OBJFILE = $(SRCFILE:.c=.o)
OBJS	= $(addprefix $(OBJDIR), $(OBJFILE))
SRCDIR	= src/
SRCS	= $(addprefix $(SRCDIR), $(SRCFILE))

OBJDIR_BONUS = obj_bonus/
OBJFILE_BONUS = $(SRCFILE_BONUS:.c=.o)
OBJS_BONUS = $(addprefix $(OBJDIR_BONUS), $(OBJFILE_BONUS))
SRCDIR_BONUS = src_bonus/
SRCS_BONUS = $(addprefix $(SRCDIR_BONUS) $(SRCFILE))

SRCFILE	= 	main.c \
			parsing/parsing.c \
			parsing/map_utils.c \
			parsing/map_create.c \
			parsing/map_search.c \
			parsing/map_verif.c \
			parsing/wall_verif.c \
			parsing/player_verif.c \
			parsing/file_verif.c \
			parsing/color.c \
			parsing/texture.c \
			init/init.c \
			init/game_init.c \
			game/game.c \
			game/key_utils.c \
			game/movement.c \
			game/extra_key.c \
			game/raycasting.c \
			game/raycasting_utils.c \
			game/texture.c \
#			game/mini_map.c \
#			game/mouse.c \

SRCFILE_BONUS = main_bonus.c \
			parsing_bonus/parsing_bonus.c \
			parsing_bonus/map_utils_bonus.c \
			parsing_bonus/map_create_bonus.c \
			parsing_bonus/map_search_bonus.c \
			parsing_bonus/map_verif_bonus.c \
			parsing_bonus/wall_verif_bonus.c \
			parsing_bonus/player_verif_bonus.c \
			parsing_bonus/file_verif_bonus.c \
			parsing_bonus/color_bonus.c \
			parsing_bonus/texture_bonus.c \
			init_bonus/init_bonus.c \
			init_bonus/game_init_bonus.c \
			game_bonus/game_bonus.c \
			game_bonus/key_utils_bonus.c \
			game_bonus/movement_bonus.c \
			game_bonus/extra_key_bonus.c \
			game_bonus/raycasting_bonus.c \
			game_bonus/raycasting_utils_bonus.c \
			game_bonus/texture_bonus.c \
			game_bonus/mini_map_bonus.c \
			game_bonus/mouse_bonus.c\

GREEN		=	\e[92;5;118m
HGRN 		=	\e[1;92m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
PURPLE		= 	\e[4;35m
CYAN		=	\e[0;36m
CURSIVE		=	\e[33;3m

USAGE		= @printf "$(CURSIVE)$(CYAN) use $(PURPLE)./$(NAME) [maps name]$(CYAN) to start the program \n"
USAGE_BONUS		= @printf "$(CURSIVE)$(CYAN) use $(PURPLE)./$(NAME_BONUS) [maps name]$(CYAN) to start the program \n"
#--------------------------------------------------------------------------#


$(NAME) : $(OBJS)
	@printf "$(CURSIVE)$(GRAY) 	- [Compiling] minilibx object ... $(RESET)"
	@make -s -C $(PATH_MLX)
	@printf "$(CURSIVE)$(GREEN)\t done\n$(RESET)"
	@printf "$(CURSIVE)$(GRAY) 	- [Compiling] libft object... $(RESET)"
	@make -s -C $(PATH_LIBFT)
	@printf "$(CURSIVE)$(GREEN)\t\t done\n$(RESET)"
	@printf "$(CURSIVE)$(GRAY) 	- [Compiling] $(NAME) object ... $(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBX) $(LIBXFLAGS) -o $(NAME) -g $(MFLAGS)
	@printf "$(CURSIVE)$(GREEN)\t\t done\n$(RESET)"
	@$(USAGE)


$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_MLX)

$(NAME_BONUS) : $(OBJS_BONUS)
	@printf "$(CURSIVE)$(GRAY) 	- [Compiling] minilibx object ... $(RESET)"
	@make -s -C $(PATH_MLX)
	@printf "$(CURSIVE)$(GREEN)\t done\n$(RESET)"
	@printf "$(CURSIVE)$(GRAY) 	- [Compiling] libft object... $(RESET)"
	@make -s -C $(PATH_LIBFT)
	@printf "$(CURSIVE)$(GREEN)\t\t done\n$(RESET)"
	@printf "$(CURSIVE)$(GRAY) 	- [Compiling] $(NAME_BONUS) object bonus ... $(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(LIBX) $(LIBXFLAGS) -o $(NAME_BONUS) -g $(MFLAGS)
	@printf "$(CURSIVE)$(GREEN)\t\t done\n$(RESET)"
	@$(USAGE_BONUS)

$(OBJDIR_BONUS)%.o: $(SRCDIR_BONUS)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_MLX)


all:  $(NAME)

bonus: $(NAME_BONUS)

clean:
	@printf "$(CURSIVE)$(GRAY) 	- [Removing] minilibx object ... $(RESET)"
	@make -s -C $(PATH_MLX) clean
	@printf "$(CURSIVE)$(GREEN)\t done\n$(RESET)"
	@printf "$(CURSIVE)$(GRAY) 	- [Removing] libft object ... $(RESET)"
	@make -s -C $(PATH_LIBFT) clean
	@printf "$(CURSIVE)$(GREEN) \t\t done\n$(RESET)"
	@printf "$(CURSIVE)$(GRAY) 	- [Removing] $(NAME) object ... $(RESET)"
	@rm -f $(OBJS)
	@printf "$(CURSIVE)$(GREEN)\t\t done\n$(RESET)"
	@printf "$(CURSIVE)$(GRAY) 	- [Removing] $(NAME_BONUS) object bonus ... $(RESET)"
	@rm -f $(OBJS_BONUS)
	@printf "$(CURSIVE)$(GREEN)\t\t done\n$(RESET)"

fclean: clean
	@printf "$(CURSIVE)$(GRAY) 	- [Removing] libft library ... $(RESET)"
	@make -s -C $(PATH_LIBFT) fclean
	@printf "$(CURSIVE)$(GREEN) \t done\n$(RESET)"
	@printf "$(CURSIVE)$(GRAY) 	- [Removing] mlx library ... $(RESET)"
	@make -s -C $(PATH_MLX) clean
	@printf "$(CURSIVE)$(GREEN)\t\t done\n$(RESET)"
	@printf "$(CURSIVE)$(GRAY) 	- [Removing] $(NAME) executable ... $(RESET)"
	@rm -f $(NAME)
	@printf "$(CURSIVE)$(GREEN)\t done\n$(RESET)\n"
	@printf "$(CURSIVE)$(GRAY) 	- [Removing] $(NAME_BONUS) executable ... $(RESET)"
	@rm -f $(NAME_BONUS)
	@printf "$(CURSIVE)$(GREEN)\t done\n$(RESET)\n"


re: fclean all


.PHONY:	all clean fclean re
