NAME			=cub3d

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

SRCFILE	= 	main.c \
			parsing/parsing.c \
			parsing/map_utils.c \
			parsing/map_create.c \
			parsing/map_search.c \
			parsing/wall_verif.c \
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
			game/draw_sprite.c \


GREEN		=	\e[92;5;118m
HGRN 		=	\e[1;92m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
PURPLE		= 	\e[4;35m
CYAN		=	\e[0;36m
CURSIVE		=	\e[33;3m

USAGE		= @printf "$(CURSIVE)$(CYAN) use $(PURPLE)./$(NAME) [maps name]$(CYAN) to start the program \n"
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


all:  $(NAME)

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


re: fclean all


.PHONY:	all clean fclean re
