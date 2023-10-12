/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:05:05 by purple            #+#    #+#             */
/*   Updated: 2023/10/12 10:31:10 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cube_bonus.h"

static t_img	anim_tex(t_data *data);

t_img	select_text(t_data *data)
{
	if (data->ray.side == 0)
	{
		if (data->ray.rdir.x > 0.f)
			return (data->img[NORTH]);
		else
			return (data->img[SOUTH]);
	}
	else if (data->ray.side == 1)
	{
		if (data->ray.rdir.y > 0.f)
			return (data->img[EAST]);
		else
			return (data->img[WEST]);
	}
	else
		return (anim_tex(data));
}

double	define_wx(t_data *data)
{
	double	wallx;

	if (data->ray.side == 0 || data->ray.side == 2)
		wallx = data->ray.pos.y + data->ray.dwall \
		* data->ray.rdir.y;
	else
		wallx = data->ray.pos.x + data->ray.dwall \
		* data->ray.rdir.x;
	wallx -= floor(wallx);
	if (((data->ray.side == 0 || data->ray.side == 2) && data->ray.rdir.x < 0)
		|| ((data->ray.side == 1 || data->ray.side == 3)
			&& data->ray.rdir.y < 0))
		wallx = 1.0f - wallx;
	return (wallx);
}

t_texture	init_draw_wall(t_data *data)
{
	t_texture	texture;

	texture.texture = select_text(data);
	texture.wall_x = define_wx(data);
	texture.tex.x = (int)(texture.wall_x * texture.texture.width);
	texture.step = 1.0 * texture.texture.height / data->ray.line_height;
	texture.tex_pos = (data->ray.dstart - data->mlx.size.y / 2 \
	+ data->ray.line_height / 2) * texture.step;
	texture.color = NULL;
	return (texture);
}

static t_img	anim_tex(t_data *data)
{
	static int	i;

	i++;
	if (i < 5000)
		return (data->anim[0]);
	else if (i < 10000)
		return (data->anim[1]);
	else if (i < 15000)
		return (data->anim[2]);
	else if (i < 20000)
		return (data->anim[3]);
	else if (i < 25000)
		return (data->anim[4]);
	else if (i < 30000)
		return (data->anim[5]);
	else if (i < 35000)
		return (data->anim[6]);
	else if (i < 40000)
		return (data->anim[7]);
	else if (i < 45000)
		return (data->anim[8]);
	else if (i < 50000)
		return (data->anim[9]);
	else if (i < 55000)
		return (data->anim[10]);
	else if (i < 60000)
		return (data->anim[11]);
	else if (i < 65000)
		return (data->anim[12]);
	else if (i < 70000)
		return (data->anim[13]);
	else
	{
		i = 0;
		return (data->anim[14]);
	}
}
