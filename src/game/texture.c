/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:05:05 by purple            #+#    #+#             */
/*   Updated: 2023/10/10 16:47:51 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

t_img select_text(t_data *data)
{
	if (data->ray.side == 0)
	{
		if (data->ray.rdir.x > 0.f)
			return(data->img[NORTH]);
		else
			return(data->img[SOUTH]);
	}
	else
	{
		if (data->ray.rdir.y > 0.f)
			return(data->img[EAST]);
		else
			return(data->img[WEST]);
	}
}

double define_wx(t_data *data)
{
	double wallx;

	if (data->ray.side == 0)
		wallx =  data->ray.pos.y + data->ray.dwall \
		* data->ray.rdir.y;
	else
		wallx = data->ray.pos.x + data->ray.dwall \
		* data->ray.rdir.x;
	wallx -= floor(wallx);
	if ((data->ray.side == 0 && data->ray.rdir.x < 0) || (data->ray.side == 1 && data->ray.rdir.y < 0))
		wallx = 1.0f - wallx;
	return (wallx);
}

t_texture 	init_draw_wall(t_data *data)
{
	t_texture texture;

	texture.texture = select_text(data);
	texture.wall_x = define_wx(data);
	texture.tex.x = (int)(texture.wall_x * texture.texture.width);
	texture.step = 1.0 * texture.texture.height / data->ray.line_height;
	texture.tex_pos = (data->ray.dstart - data->mlx.size.x / 2 \
	+ data->ray.line_height / 2) \
	* texture.step;
	texture.color = NULL;
	return (texture);
}