/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:10:05 by purple            #+#    #+#             */
/*   Updated: 2023/09/11 08:58:20 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int init_the_game(t_data *data)
{
	int screen_width;
	int screen_height;

	ft_memset(&data->mlx, 0, sizeof(data->mlx));
	data->mlx.mlx_id = mlx_init();
	if (!(data->mlx.mlx_id))
		return (MLX_ERROR);
	mlx_get_screen_size(data->mlx.mlx_id, &screen_width, &screen_height);
	if (screen_width >= 1920)
		data->mlx.size.x = 1920;
	else
		data->mlx.size.x = 848;
	if (screen_height >= 1080)
		data->mlx.size.y = 1080;
	else
		data->mlx.size.y = 480;
	return (0);
		
}