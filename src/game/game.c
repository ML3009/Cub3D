/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:47:04 by purple            #+#    #+#             */
/*   Updated: 2023/09/12 16:06:22 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"
# include <X11/keysym.h>
# include <X11/X.h>

int render_rainbow(void *data) {
	t_data *tmp = data;
    static int color = 0xFF0000;
	//static int black = 0x000000;
	usleep(5);
	mlx_clear_window(tmp->mlx.mlx_id, tmp->mlx.mlx_window);
	//mlx_pixel_put(tmp->mlx.mlx_id, tmp->mlx.mlx_window, 50, 50, color);
	for (int k = 0; k < 50; k++)
	{
		for (int j = 0; j < 50; j++)
			mlx_pixel_put(tmp->mlx.mlx_id, tmp->mlx.mlx_window, (tmp->player.pos.x) + k, (tmp->player.pos.y) + j, color);
	}
	mlx_pixel_put(tmp->mlx.mlx_id, tmp->mlx.mlx_window, (tmp->player.pos.x), (tmp->player.pos.y), color);
    if (color == 0xFF0000)
        color = 0x00FF00; // Green
    else if (color == 0x00FF00)
        color = 0x0000FF; // Blue
    else
        color = 0xFF0000; // Red
    return (0);
}

int key_hook(int keycode, t_data *tmp) 
{
	if (keycode == XK_Up)
		tmp->player.pos.y -= 20;
	if (keycode == XK_Down)
		tmp->player.pos.y += 20;
	if (keycode == XK_Right)
		tmp->player.pos.x += 20;
	if (keycode == XK_Left)
		tmp->player.pos.x -= 20;
	printf("x :%d\n",tmp->player.pos.x);
	printf("y :%d\n",tmp->player.pos.y);
	render_rainbow(tmp);
	return (0);

}


void game_start(t_data *data)
{
	if (init_the_game(data) < 0)
		return ;
	data->player.pos.x = data->mlx.size.x / 2;
	data->player.pos.y = data->mlx.size.y / 2;

	printf("x :%d\n",data->player.pos.x);
	printf("y :%d\n",data->player.pos.y);
	//render_rainbow(data);
	mlx_key_hook(data->mlx.mlx_window, key_hook, data);
	mlx_loop_hook(data->mlx.mlx_id, render_rainbow, data);
	mlx_loop(data->mlx.mlx_id);
}