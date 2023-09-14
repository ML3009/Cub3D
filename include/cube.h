/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:20:34 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/14 14:43:34 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/libft/include/libft.h"
#include "../library/minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <math.h>
#include "struct.h"
#include "define.h"
#include "color.h"



/*----[ PARSING ]----*/

int		parsing(int ac, char **av, t_data *map);
int		file_extension(char *file);
int		open_file(char *file, t_data *map);
void	init_map(t_data *map);
int		create_map(char *file, t_data *map, int fd);
bool	search_map(char *line);
void	count_row(char *file, t_data *map);
void	count_col(char *file, t_data *map);
int		check_map(t_data *map);
int		check_wall(t_data *map, int pos);


/*----[ GAME ]----*/
int		init_the_game(t_data *data);
void	game_start(t_data *data);
int		launch_menu(t_data *data);
/*KEY*/
int key_drop(int keycode, t_data *tmp);
int key_press(int keycode, t_data *tmp);
void ft_key(t_data *data);
int escape(t_data *data);
void vision_left(t_data *data);
void vision_right(t_data *data);
void go_fwd(t_data *data);
void go_bck(t_data *data);
void go_left(t_data *data);
void go_right(t_data *data);

/*Raycasting*/
void raycasting(t_data *data);

int	draw_void(t_data *data);
