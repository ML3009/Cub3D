/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:20:34 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/08 17:32:21 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/libft/include/libft.h"
#include "../library/minilibx-linux/mlx.h"
#include "struct.h"
#include "define.h"



/*----[ PARSING ]----*/

int		parsing(int ac, char **av, t_data *map);
int		file_extension(char *file);
void	init_map(t_map *map);
int		open_file(char *file, t_map *map);
void	count_row(char *file, t_map *map);
void	count_col(char *file, t_map *map);


/*----[ GAME ]----*/
int init_the_game(t_data *data);
void game_start(t_data *data);
int launch_menu(t_data *data);
