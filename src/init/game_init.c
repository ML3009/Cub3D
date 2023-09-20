/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:10:05 by purple            #+#    #+#             */
/*   Updated: 2023/09/20 13:59:37 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void init_orientation(t_data *data);
void screen_size(t_data *data);

int init_the_game(t_data *data)
{
	init_orientation(data);
	if (!(data->mlx.mlx_id = mlx_init()))
		return (MLX_ERROR);
	screen_size(data);
	if (!(data->mlx.mlx_window = mlx_new_window(data->mlx.mlx_id, data->mlx.size.x,  data->mlx.size.y, "Cub3D")))
		return (MLX_ERROR);
	data->base_img[0].image = mlx_new_image(data->mlx.mlx_id,data->mlx.size.x, data->mlx.size.y);
	data->base_img[0].adress = mlx_get_data_addr(data->base_img[0].image , &data->base_img[0].bpp, &data->base_img[0].line_lenght, &data->base_img[0].endian);
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
		data->player.dir.x = 1;
		if (data->base_orient == 'S')
			data->player.dir.y = 1;
		else
			data->player.dir.y = -1;
	}
	else
	{
		data->player.dir.y = 1;
		if (data->base_orient == 'E')
			data->player.dir.y = 1;
		else
			data->player.dir.y = -1;
	}
	data->player.plane.x = -(data->player.dir.y) *0.66;
	data->player.plane.y = data->player.dir.y * 0.66;
}