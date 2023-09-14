/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:46:55 by purple            #+#    #+#             */
/*   Updated: 2023/09/13 15:59:48 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int escape(t_data *data)
{
	(void)data;
	if (data->image)
		mlx_destroy_image(data->mlx.mlx_id, data->image);
	mlx_destroy_window(data->mlx.mlx_id, data->mlx.mlx_window);
	//mlx_destroy_display(data->mlx.mlx_id);
	exit(0);
	return (0);
}

void vision_left(t_data *data)
{
	(void)data;
}

void vision_right(t_data *data)
{
	(void)data;
}