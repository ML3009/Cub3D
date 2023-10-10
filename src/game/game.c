/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <medpurple@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:47:04 by purple            #+#    #+#             */
/*   Updated: 2023/10/09 21:26:58 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	loop_game(t_data *data);
int	rbg_hexa(t_data *data, int texture);

void	game_start(t_data *data)
{
	data->rgb[FLOOR].rgb_hex = rbg_hexa(data, FLOOR)
	if (init_the_game(data) < 0)
		return ;
	mlx_loop_hook(data->mlx.mlx_id, loop_game, data);
	mlx_hook(data->mlx.mlx_window, 2, KeyPressMask, &key_press, data);
	mlx_hook(data->mlx.mlx_window, 3, KeyReleaseMask, &key_drop, data);
	mlx_hook(data->mlx.mlx_window, ClientMessage, 0, escape, data);
	mlx_hook(data->mlx.mlx_window, DestroyNotify, 0, escape, data);
	mlx_loop(data->mlx.mlx_id);
}

int	loop_game(t_data *data)
{
	ft_key(data);
	draw_void(data);
	raycasting(data);
	return (0);
}


int	rbg_hexa(t_data *data, int texture)
	return (data->rbg[texture].rgb[0] << 16 \
	| data->rbg[texture].rgb[1] << 8 \
	| data->rbg[texture].rgb[3]);