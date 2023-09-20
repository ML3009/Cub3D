/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:20:34 by purple            #+#    #+#             */
/*   Updated: 2023/09/20 14:33:34 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static void send_ray(t_data *data);
static void dda(t_data *data);
static void draw_ray(t_data *data, int x);

void raycasting(t_data *data)
{
	
	int len;

	len = -1;
	while (++len < data->mlx.size.x)
	{
		// ray pos and dir
		data->player.cam.x = 2 * len / data->mlx.size.x - 1;
		data->player.raydir.x = data->player.dir.x + data->player.plane.x * data->player.cam.x;
		data->player.raydir.y = data->player.dir.y + data->player.plane.y * data->player.cam.x;
		
		send_ray(data);
		draw_ray(data, len);
	}
}


static void send_ray(t_data *data)
{
	
	init_dda(data);
	dda(data);
	if (data->player.sside == 0)
		data->player.wall_dist = data->player.side.x - data->player.d.x;
	else
		data->player.wall_dist = data->player.side.y - data->player.d.y;
	if (data->player.wall_dist == 0)
		data->player.wall_dist = 1e30;
	data->player.line_height = data->mlx.size.y / data->player.wall_dist;
	data->player.draw_start = -(data->player.line_height) / 2 + data->mlx.size.y / 2;
	data->player.draw_end = data->player.line_height / 2 + data->mlx.size.y / 2;
	if (data->player.draw_start < 0)
		data->player.draw_start = 0;
	if (data->player.draw_end >= data->mlx.size.y)
		data->player.draw_end = data->mlx.size.y - 1;
	check_orientation(data);
}


static void dda(t_data *data)
{
	bool hit;

	hit = false;
	while (hit == false)
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
		if (data->player.map.x > -1 && data->player.map.y > -1 \
		&& data->map[(int)data->player.map.x][(int)data->player.map.y] == '1')
			hit = true;
	}
	return;
}

static void draw_ray(t_data *data, int x)
{
	int y;

	y = -1;
	while (++y < data->mlx.size.y)
	{
		if (y < data->player.draw_start && x < data->mlx.size.x)
			mlx_pixel_put(data->mlx.mlx_id, data->mlx.mlx_window,x, y, 0x666699);
		else if (y >= data->player.draw_start && y <= data->player.draw_end)
		{
			mlx_pixel_put(data->mlx.mlx_id, data->mlx.mlx_window,x, y, 0x000000);
			y = data->player.draw_end;
		}
		else
			mlx_pixel_put(data->mlx.mlx_id, data->mlx.mlx_window,x, y, 0xFFFFFF);
			
	}
}