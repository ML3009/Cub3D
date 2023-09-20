/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:03:26 by purple            #+#    #+#             */
/*   Updated: 2023/09/20 14:32:59 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"
void put_mlx_color(t_data *data, int x);

void draw_sprite(t_data *data, int x)
{
	double wall_x;

	if (data->player.sside == 0)
		wall_x = data->player.pos.y + data->player.wall_dist * data->player.raydir.y;
	else
		wall_x = data->player.pos.x + data->player.wall_dist * data->player.raydir.x;
	wall_x = -floor(wall_x);
	data->player.texture.x = wall_x * TEXTURE;
	if (data->player.sside == 0 && data->player.raydir.x > 0)
		data->player.texture.x = TEXTURE - data->player.texture.x - 1;
	if (data->player.sside == 1 && data->player.raydir.y < 0)
		data->player.texture.x = TEXTURE - data->player.texture.x - 1;
	data->player.sstep = TEXTURE / data->mlx.size.y;
	data->player.text_pos = (data->player.draw_start - data->mlx.size.y / 2 + data->player.line_height / 2) * data->player.sstep;
	put_mlx_color(data, x);
}

void put_mlx_color(t_data *data, int x)
{
	int y;
	int color;
	
	y = data->player.draw_start;
	while (y < data->player.draw_end)
	{
		data->player.texture.y = (int)data->player.text_pos % (63);
		data->player.text_pos += data->player.sstep;
		color = 0xFF0000;
		mlx_pixel_put(data->mlx.mlx_id, data->mlx.mlx_window, x, y, 0xFF0000);
	}
}