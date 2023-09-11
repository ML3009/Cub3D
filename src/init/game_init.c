/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:10:05 by purple            #+#    #+#             */
/*   Updated: 2023/09/11 14:23:29 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void init_orientation(t_data *data);
void screen_size(t_data *data);

int init_the_game(t_data *data)
{
	ft_memset(&data->mlx, 0, sizeof(data->mlx));
	if (!(data->mlx.mlx_id = mlx_init()))
		return (MLX_ERROR);
	screen_size(data);
	init_orientation(data);
	if (!(data->mlx.mlx_window = mlx_new_window(data->mlx.mlx_id, data->mlx.size.x,  data->mlx.size.y, "Cub3D")))
		return (MLX_ERROR);
	return (0);
		
}

void screen_size(t_data *data)
{
	int screen_width;
	int screen_height;

	mlx_get_screen_size(data->mlx.mlx_id, &screen_width, &screen_height);
	if (screen_width >= 1920)
		data->mlx.size.x = 1920;
	else
		data->mlx.size.x = 848;
	if (screen_height >= 1080)
		data->mlx.size.y = 1080;
	else
		data->mlx.size.y = 480;
}

void init_orientation(t_data *data)
{
	if (data->base_orient == 'S' || data->base_orient == 'N')
	{
		data->player.direction[0] = 0;
		if (data->base_orient == 'S')
			data->player.direction[1] = -1;
		else
			data->player.direction[1] = 1;
	}
	else
	{
		data->player.direction[1] = 0;
		if (data->base_orient == 'E')
			data->player.direction[0] = -1;
		else
			data->player.direction[0] = 1;
	}
}