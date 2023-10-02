/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:23:38 by purple            #+#    #+#             */
/*   Updated: 2023/09/20 12:47:26 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"
static void init_step(t_data *data);

void init_dda(t_data *data)
{
	data->player.map.x = (int)data->player.pos.x;
	data->player.map.y = (int)data->player.pos.y;
	if (data->player.raydir.x == 0)
		data->player.d.x = 1e30;
	else
		data->player.d.x = fabs(1/data->player.raydir.x);
	if (data->player.raydir.y == 0)
			data->player.d.y = 1e30;
	else
		data->player.d.y = fabs(1/data->player.raydir.y);

	init_step(data);
}

static void init_step(t_data *data)
{
	if (data->player.raydir.x < 0)
	{
		data->player.step.x = -1;
		data->player.side.x = (data->player.pos.x - data->player.map.x) * data->player.d.x;		
	}
	else
	{
		data->player.step.x = 1;
		data->player.side.x = (data->player.map.x + 1.0 - data->player.pos.x) * data->player.d.x;		
	}
	if (data->player.raydir.y < 0)
	{
		data->player.step.y = -1;
		data->player.side.y = (data->player.pos.y - data->player.map.y) * data->player.d.y;		
	}
	else
	{
		data->player.step.y = 1;
		data->player.side.y = (data->player.map.y + 1.0 - data->player.pos.y) * data->player.d.y;		
	}
}

void check_orientation(t_data *data)
{
	if (data->player.step.x == -1 && data->player.sside == 0)
		data->player.orientation = EAST;
	if (data->player.step.x == 1 && data->player.sside == 0)
		data->player.orientation = WEST;
	if (data->player.step.x == -1 && data->player.sside == 1)
		data->player.orientation = NORTH;
	if (data->player.step.x == 1 && data->player.sside == 1)
		data->player.orientation = SOUTH;
}