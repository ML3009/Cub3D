/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:20:34 by purple            #+#    #+#             */
/*   Updated: 2023/09/18 13:06:53 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"
void raycasting(t_data *data)
{
	
	int len;

	len = -1;
	while (++len < data->mlx.size.x)
	{
		// ray pos and dir
		data->player.cam.x = 2 * len / (double)data->mlx.size.x - 1;
		data->player.raydir.x = data->player.dir.x + data->player.plane.x * data->player.cam.x;
		data->player.raydir.y = data->player.dir.y + data->player.plane.y * data->player.cam.x;

		// whitch square of the map
		data->player.map.x = data->player.pos.x;
		data->player.map.y = data->player.pos.y;

		// delta distance
		if (data->player.raydir.x == 0)
			data->player.d.x = 1e30;
		else
			data->player.d.x = fabs(1/data->player.raydir.x);
		
		if (data->player.raydir.y == 0)
			data->player.d.y = 1e30;
		else
			data->player.d.y = fabs(1/data->player.raydir.y);

		// step and side dist ?

		if (data->player.raydir.x < 0)
		{
			data->player.step.x = -1;
			data->player.side.x = (data->player.pos.x - data->player.map.x) * data->player.d.x;		
		}
		else
		{
			data->player.step.x = 1;
			data->player.side.x = (data->player.pos.x - data->player.map.x + 1) * data->player.d.x;		
		}

		if (data->player.raydir.y < 0)
		{
			data->player.step.y = -1;
			data->player.side.y = (data->player.pos.y - data->player.map.y) * data->player.d.y;		
		}
		else
		{
			data->player.step.y = 1;
			data->player.side.y = (data->player.pos.y - data->player.map.y + 1) * data->player.d.y;		
		}

		// DDA
		
		while (true)
		{
			if (data->player.side.x < data->player.side.y)
			{
				data->player.side.x += data->player.d.x;
				data->player.map.x += data->player.step.x;
				data->player.sside = 0;
			}
			else
			{
				data->player.side.y += data->player.d.y;
				data->player.map.y += data->player.step.y;
				data->player.sside = 1;
			}
			if (data->map[(int)data->player.map.x][(int)data->player.map.y])
			{
				//set texture
				break;
			}
		}
		// distance perpendicular ray
		if (data->player.sside == 0)
			data->player.wall_dist = data->player.side.x - data->player.d.x;
		else
			data->player.wall_dist = data->player.side.y - data->player.d.y;
		// line height
		data->player.line_height = data->mlx.size.y / data->player.wall_dist;
		//calculate lowest and highest pixel to fill in current stripe
		data->player.draw_start = (data->player.line_height * (-1)) / 2 + data->mlx.size.x / 2;
		data->player.draw_end = data->player.line_height / 2 + data->mlx.size.x / 2;
		if (data->player.draw_start < 0)
			data->player.draw_start = 0;
		if (data->player.draw_end >= data->mlx.size.y)
			data->player.draw_end = data->mlx.size.y - 1;
		 //calculate value of wallX
		if (data->player.sside == 0)
			data->player.wall_x = data->player.pos.y + data->player.wall_dist * data->player.raydir.y;
		else
			data->player.wall_x = data->player.pos.x + data->player.wall_dist * data->player.raydir.x;
		data->player.wall_x -= floor(data->player.wall_x);
		data->player.texture.x = data->player.wall_x * (double)TEXTURE;
		if (data->player.sside == 0 && data->player.raydir.x > 0)
			data->player.texture.x = TEXTURE - data->player.texture.x - 1;
		if (data->player.sside == 1 && data->player.raydir.y < 0)
			data->player.texture.x = TEXTURE - data->player.texture.x - 1;
		// start drawing
		double step = 0;
		double tex_pos = 0;
		int y = 0;

		step = 1 * TEXTURE / data->player.line_height;
		tex_pos = (data->player.draw_start - data->mlx.size.y / 2 + data->player.line_height / 2 ) * step;	
		y = data->player.draw_start;
		while (y < data->player.draw_end)
		{
			data->player.texture.y = (int)tex_pos & (TEXTURE - 1);
			tex_pos += step;
			data->player.color = 0xd50054;
			if (data->player.sside == 1)
			data->player.color = (data->player.color >> 1) & 8355711;
			printf("[X] = %d | [Y] = %d\n", len, y);
			mlx_pixel_put(data->mlx.mlx_id,data->mlx.mlx_window,len, y, data->player.color);
			y++;
		}
	}
}