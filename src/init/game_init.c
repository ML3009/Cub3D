/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:10:05 by purple            #+#    #+#             */
/*   Updated: 2023/09/08 15:08:18 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int init_the_game(t_data *data)
{
	int screen_width;
	int screen_height;

	ft_memset(&data->mlx, 0, sizeof(data->mlx));
	data->mlx.mlx_id = mlx_init();
	mlx_get_screen_size(data->mlx.mlx_id, &screen_width, &screen_height);
	data->mlx.size.x = screen_width;
	data->mlx.size.y = screen_height;
	if (!(data->mlx.mlx_id))
		return (MLX_ERROR);
	return (0);
		
}