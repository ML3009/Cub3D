/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:20:34 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/11 18:13:14 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_BONUS_H
# define CUBE_BONUS_H

# include <math.h>
# include "../library/libft/include/libft.h"
# include "../library/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "struct_bonus.h"
# include "define_bonus.h"

/*----[ PARSING ]----*/
int			parsing(int ac, char **av, t_data *map);
int			file_extension(char *file);
int			open_file(char *file);
void		init_map(t_data *map);
int			create_map(char *file, t_data *map, char *size);
bool		search_map(char *line);
bool		search_wall(char *line);
void		count_row(char *file, t_data *map);
int			count_col(char *file, t_data *map, char *size);
int			check_map(t_data *map);
char		**copy_map(t_data *map);
int			check_wall(t_data *map, char **map_cp, int y, int x);
int			search_texture(t_data *map, char *line);
int			search_color(t_data *map, char *line, int i, int j);
int			check_player(char **map);

/*----[ GAME ]----*/
int			init_the_game(t_data *data);
void		game_start(t_data *data);
int			launch_menu(t_data *data);
void		draw_mini_map(t_data *data, int y, int x, int y_bis);
void		mouse_pov(t_data *data);

/*----[key]----*/
int			key_drop(int keycode, t_data *tmp);
int			key_press(int keycode, t_data *tmp);
void		ft_key(t_data *data);
int			escape(t_data *data);
void		vision_left(t_data *data);
void		vision_right(t_data *data);
void		go_fwd(t_data *data);
void		go_bck(t_data *data);
void		go_left(t_data *data);
void		go_right(t_data *data);

/*----[raycasting]----*/
void		raycasting(t_data *data);
void		init_dda(t_data *data);
void		wall_coo(t_data *data);
void		dda(t_data *data);
void		init_step(t_data *data);
void		draw_void(t_data *data);
void		check_orientation(t_data *data);

t_img		select_text(t_data *data);
double		define_wx(t_data *data);
t_texture	init_draw_wall(t_data *data);
void		draw_wall(t_data *data, int x);
void		img_pix_put(t_img *img, int x, int y, int color);
bool		is_dir(char c);


/*animation*/
int init_anim(t_data *data);
void free_mlx_b(t_data *data);
void	free_all_map(t_data *map);

#endif
