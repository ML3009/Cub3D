/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:47:04 by purple            #+#    #+#             */
/*   Updated: 2023/09/13 16:38:08 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"
int loop_game(t_data *data);

void game_start(t_data *data)
{
	if (init_the_game(data) < 0)
		return ;
	data->player.pos.x = data->mlx.size.x / 2;
	data->player.pos.y = data->mlx.size.y / 2;
	mlx_hook(data->mlx.mlx_window,2, KeyPressMask, &key_press, data);
	mlx_hook(data->mlx.mlx_window,3, KeyReleaseMask, &key_drop, data);
	mlx_loop_hook(data->mlx.mlx_id, loop_game, data);
	mlx_hook(data->mlx.mlx_window, ClientMessage, 0, escape, data);
	mlx_hook(data->mlx.mlx_window, DestroyNotify, 0, escape, data);
	mlx_loop(data->mlx.mlx_id);
}

int loop_game(t_data *data)
{
	draw_void(data);
	ft_key(data);
	raycasting(data);
	return (0);
}

int	draw_void(t_data *data)
{
	int	x;
	int	y;
	int grey = 0xd901f9;
	int black = 0x000000;
	int white = 0x666699;
	y = 0;
	while (y <= data->mlx.size.y)
	{
		x = 0;
		while (y <= data->mlx.size.y / 2 && x < data->mlx.size.x)
		{
			mlx_pixel_put( data->mlx.mlx_id, data->mlx.mlx_window, x, y, white);
			x++;
		}
		while (y <= data->mlx.size.y && y > data->mlx.size.y / 2 && x < data->mlx.size.x)
		{
			mlx_pixel_put( data->mlx.mlx_id, data->mlx.mlx_window, x, y, black);
			x++;
		}
		y++;
	}
	for (int k = 0; k <= 10; k++)
	{
		for (int j = 0; j <= 10; j++)
			mlx_pixel_put(data->mlx.mlx_id, data->mlx.mlx_window, (data->player.pos.x - 5) + k, (data->player.pos.y - 5) + j, grey);
	}
	return (0);
}