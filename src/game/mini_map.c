/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:40:41 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/10 17:21:07 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static void	draw_square(t_data *data, int y, int x, int color);

void	draw_mini_map(t_data *data)
{
	int	y;
	int x;
	int y_bis;
	int x_bis;

	y = -1;
	y_bis = 0;
	while (++y < data->mlx.size.y && y < data->row)
	{
		x = -1;
		x_bis = 0;
		while (++x < data->mlx.size.x && x < data->col)
		{
			if (x < data->col && y < data->row)
			{
				if (data->map && data->map[y][x] && data->map[y][x] == '1')
					draw_square(data, y_bis, x_bis, 0x1A6303);
				else if (data->map && data->map[y][x] && (data->map[y][x] == '0' || is_dir(data->map[y][x])))
					draw_square(data, y_bis, x_bis, 0xF0D5F8);
			}
			x_bis+=5;
		}
		y_bis+=5;
	}
	draw_square(data, (int)data->ray.pos.y * 5, (int)data->ray.pos.x * 5, 0x00000000);
}

static void	draw_square(t_data *data, int y, int x, int color)
{
	int	y_temp;
	int	x_temp;
	int save_x;

	y_temp = y + 5;
	x_temp = x + 5;
	save_x = x;
	while (y < y_temp)
	{
		x = save_x;
		while (x < x_temp)
		{
			img_pix_put(&data->base_img,x, y, color);
			x++;
		}
		y++;
	}
	return ;
}
