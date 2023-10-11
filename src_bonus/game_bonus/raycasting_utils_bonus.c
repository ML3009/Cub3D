/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:23:38 by purple            #+#    #+#             */
/*   Updated: 2023/10/11 15:36:20 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cube_bonus.h"

double	ft_abs(double i);

void	init_dda(t_data *data)
{
	if (data->ray.rdir.x == 0)
		data->ray.ddist.x = 1e30;
	else
		data->ray.ddist.x = ft_abs(1 / data->ray.rdir.x);
	if (data->ray.rdir.y == 0)
		data->ray.ddist.y = 1e30;
	else
		data->ray.ddist.y = ft_abs(1 / data->ray.rdir.y);
}

void	init_step(t_data *data)
{
	if (data->ray.rdir.x < 0)
	{
		data->ray.step.x = -1;
		data->ray.sdist.x = (data->ray.pos.x \
		- data->ray.map.x) * data->ray.ddist.x;
	}
	else
	{
		data->ray.step.x = 1;
		data->ray.sdist.x = (data->ray.map.x + 1.0 \
		- data->ray.pos.x) * data->ray.ddist.x;
	}
	if (data->ray.rdir.y < 0)
	{
		data->ray.step.y = -1;
		data->ray.sdist.y = (data->ray.pos.y \
		- data->ray.map.y) * data->ray.ddist.y;
	}
	else
	{
		data->ray.step.y = 1;
		data->ray.sdist.y = (data->ray.map.y + 1.0 \
		- data->ray.pos.y) * data->ray.ddist.y;
	}
}

void	dda(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.sdist.x < data->ray.sdist.y)
		{
			data->ray.sdist.x += data->ray.ddist.x;
			data->ray.map.x += data->ray.step.x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sdist.y += data->ray.ddist.y;
			data->ray.map.y += data->ray.step.y;
			data->ray.side = 1;
		}
		if (((data->map[(int)data->ray.map.y][(int)data->ray.map.x]) == '1' \
		|| (data->map[(int)data->ray.map.y][(int)data->ray.map.x]) == '2') \
		&& (data->map[(int)data->ray.map.y][(int)data->ray.map.x]) \
		!= data->base_orient)
			data->ray.hit = 1;
	}
}

void	wall_coo(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.dwall = (data->ray.sdist.x - data->ray.ddist.x);
	else
		data->ray.dwall = (data->ray.sdist.y - data->ray.ddist.y);
	data->ray.line_height = (int)(data->mlx.size.y / data->ray.dwall);
	data->ray.dstart = -data->ray.line_height / 2 + data->mlx.size.y / 2;
	if (data->ray.dstart < 0)
		data->ray.dstart = 0;
	data->ray.dend = data->ray.line_height / 2 + data->mlx.size.y / 2;
	if (data->ray.dend >= data->mlx.size.y)
		data->ray.dend = data->mlx.size.y - 1;
}

double	ft_abs(double i)
{
	if (i < 0)
		i *= -1;
	return (i);
}
