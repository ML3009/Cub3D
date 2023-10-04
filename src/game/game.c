/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:47:04 by purple            #+#    #+#             */
/*   Updated: 2023/10/03 14:26:41 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"
int loop_game(t_data *data);

void game_start(t_data *data)
{
	if (init_the_game(data) < 0)
		return ;
	mlx_hook(data->mlx.mlx_window,2, KeyPressMask, &key_press, data);
	mlx_hook(data->mlx.mlx_window,3, KeyReleaseMask, &key_drop, data);
	mlx_loop_hook(data->mlx.mlx_id, loop_game, data);
	mlx_hook(data->mlx.mlx_window, ClientMessage, 0, escape, data);
	mlx_hook(data->mlx.mlx_window, DestroyNotify, 0, escape, data);
	mlx_loop(data->mlx.mlx_id);
}

int loop_game(t_data *data)
{
 	ft_key(data);
	raycasting(data);
	return (0);
}