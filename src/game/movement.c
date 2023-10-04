/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:46:58 by purple            #+#    #+#             */
/*   Updated: 2023/10/04 14:57:30 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void go_fwd(t_data *data)
{
	if (data->map[(int)(data->ray.pos.x + data->ray.dir.x * 0.045)][(int)(data->ray.pos.y + data->ray.dir.y * 0.045)] == 48)
	{
		data->ray.pos.x += data->ray.dir.x * 0.045;
		data->ray.pos.y += data->ray.dir.y * 0.045;
		raycasting(data);
	}
}

void go_bck(t_data *data)
{
	if (data->map[(int)(data->ray.pos.x - data->ray.dir.x * 0.045)][(int)(data->ray.pos.y - data->ray.dir.y * 0.045)] == 48)
	{
		data->ray.pos.x -= data->ray.dir.x * 0.045;
		data->ray.pos.y -= data->ray.dir.y * 0.045;
		raycasting(data);
	}
}

void go_left(t_data *data)
{
	if (data->map[(int)(data->ray.pos.x - data->ray.plane.x * 0.045)][(int)(data->ray.pos.y - data->ray.plane.y * 0.045)] == 48)
	{
		data->ray.pos.x -= data->ray.plane.x * 0.045;
		data->ray.pos.y -= data->ray.plane.y * 0.045;
		raycasting(data);
	}
}

void go_right(t_data *data)
{
	if (data->map[(int)(data->ray.pos.x + data->ray.plane.x * 0.045)][(int)(data->ray.pos.y + data->ray.plane.y * 0.045)] == 48)
	{
		data->ray.pos.x += data->ray.plane.x * 0.045;
		data->ray.pos.y += data->ray.plane.y * 0.045;
		raycasting(data);
	}
}