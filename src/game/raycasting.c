/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:20:34 by purple            #+#    #+#             */
/*   Updated: 2023/10/04 15:01:07 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void raycasting(t_data *data)
{
	int x;

	x = -1;
	mlx_clear_window(data->mlx.mlx_id, data->mlx.mlx_window);
	while (++x  < data->mlx.size.x)
	{
		data->ray.camx = 2 * x / (double)data->mlx.size.x - 1;
		data->ray.rdir.x = data->ray.dir.x + data->ray.plane.x * data->ray.camx;
		data->ray.rdir.y = data->ray.dir.y + data->ray.plane.y * data->ray.camx;
		data->ray.map.x = (int)data->ray.pos.x;
		data->ray.map.y = (int)data->ray.pos.y;
		data->ray.hit = 0;
		init_dda(data);
		init_step(data);
		dda(data);
		wall_coo(data);
		draw(data, x);
	}
	
}

void draw(t_data *data, int x)
{
	int y;

	y = -1;
	while (++y < data->mlx.size.y)
	{
		if (y < data->ray.dstart && x < data->mlx.size.x)
			mlx_pixel_put(data->mlx.mlx_id, data->mlx.mlx_window,x, y, 0x666699);
		else if (y >= data->ray.dstart && y <= data->ray.dend)
		{
			mlx_pixel_put(data->mlx.mlx_id, data->mlx.mlx_window,x, y, 0x000000);
			y = data->ray.dend;
		}
		else
			mlx_pixel_put(data->mlx.mlx_id, data->mlx.mlx_window,x, y, 0xFFFFFF);
			
	}
}