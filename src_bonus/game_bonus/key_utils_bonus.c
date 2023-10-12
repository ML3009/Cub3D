/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:43:44 by purple            #+#    #+#             */
/*   Updated: 2023/10/12 10:49:12 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cube_bonus.h"

int	key_press(int keycode, t_data *tmp)
{
	if (keycode == XK_Up || keycode == XK_w)
		tmp->key.up = 1;
	if (keycode == XK_Down || keycode == XK_s)
		tmp->key.down = 1;
	if (keycode == XK_a)
		tmp->key.left = 1;
	if (keycode == XK_Left)
		tmp->key.vleft = 1;
	if (keycode == XK_d)
		tmp->key.right = 1;
	if (keycode == XK_Right)
		tmp->key.vright = 1;
	if (keycode == XK_Escape)
		tmp->key.esc = 1;
	if (keycode == XK_e)
		tmp->key.odoor = 1;
	if (keycode == XK_r)
		tmp->key.cdoor = 1;
	if (keycode == XK_m)
		tmp->key.map = 1;
	return (0);
}

int	key_drop(int keycode, t_data *tmp)
{
	if (keycode == XK_Up || keycode == XK_w)
		tmp->key.up = 0;
	if (keycode == XK_Down || keycode == XK_s)
		tmp->key.down = 0;
	if (keycode == XK_a)
		tmp->key.left = 0;
	if (keycode == XK_Left)
		tmp->key.vleft = 0;
	if (keycode == XK_d)
		tmp->key.right = 0;
	if (keycode == XK_Right)
		tmp->key.vright = 0;
	if (keycode == XK_Escape)
		tmp->key.esc = 0;
	if (keycode == XK_e)
		tmp->key.odoor = 0;
	if (keycode == XK_r)
		tmp->key.cdoor = 0;
	if (keycode == XK_m)
		tmp->key.map = 0;
	return (0);
}

void	ft_key(t_data *data)
{
	if (data->key.up == 1)
		go_fwd(data);
	if (data->key.down == 1)
		go_bck(data);
	if (data->key.left == 1)
		go_left(data);
	if (data->key.right == 1)
		go_right(data);
	if (data->key.esc == 1)
		escape(data);
	if (data->key.vleft == 1)
		vision_left(data);
	if (data->key.vright == 1)
		vision_right(data);
	if (data->map[(int)(data->ray.pos.y + data->ray.dir.y)]
		[(int)(data->ray.pos.x + data->ray.dir.x)] == '2'
		&& data->key.odoor == 1)
		data->map[(int)(data->ray.pos.y + data->ray.dir.y)]
		[(int)(data->ray.pos.x + data->ray.dir.x)] = '3';
	if (data->map[(int)(data->ray.pos.y + data->ray.dir.y)]
		[(int)(data->ray.pos.x + data->ray.dir.x)] == '3'
		&& data->key.cdoor == 1)
		data->map[(int)(data->ray.pos.y + data->ray.dir.y)]
		[(int)(data->ray.pos.x + data->ray.dir.x)] = '2';
}
