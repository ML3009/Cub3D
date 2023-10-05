/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:46:55 by purple            #+#    #+#             */
/*   Updated: 2023/10/05 10:01:34 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	escape(t_data *data)
{
	(void)data;
	if (data->base_img[0].image)
		mlx_destroy_image(data->mlx.mlx_id, data->base_img[0].image);
	mlx_destroy_window(data->mlx.mlx_id, data->mlx.mlx_window);
	exit(0);
	return (0);
}

void	vision_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dir.x;
	data->ray.dir.x = data->ray.dir.x * cos(0.0250) \
	- data->ray.dir.y * sin(0.0250);
	data->ray.dir.y = old_dir_x * sin(0.0250) \
	+ data->ray.dir.y * cos(0.0250);
	old_plane_x = data->ray.plane.x;
	data->ray.plane.x = data->ray.plane.x * cos(0.0250) \
	- data->ray.plane.y * sin(0.0250);
	data->ray.plane.y = old_plane_x * sin(0.0250) \
	+ data->ray.plane.y * cos(0.0250);
}

void	vision_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dir.x;
	data->ray.dir.x = data->ray.dir.x * cos(-0.0250) \
	- data->ray.dir.y * sin(-0.0250);
	data->ray.dir.y = old_dir_x * sin(-0.0250) \
	+ data->ray.dir.y * cos(-0.0250);
	old_plane_x = data->ray.plane.x;
	data->ray.plane.x = data->ray.plane.x * cos(-0.0250) \
	- data->ray.plane.y * sin(-0.0250);
	data->ray.plane.y = old_plane_x * sin(-0.0250) \
	+ data->ray.plane.y * cos(-0.0250);
}
