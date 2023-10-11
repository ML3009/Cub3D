/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:13:57 by purple            #+#    #+#             */
/*   Updated: 2023/10/11 18:13:32 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void free_mlx(t_data *data)
{
	if (data->base_img.image != NULL)
		mlx_destroy_image(data->mlx.mlx_id, data->base_img.image);
	if (data->img[NORTH].image != NULL)
		mlx_destroy_image(data->mlx.mlx_id, data->img[NORTH].image);
	if (data->img[SOUTH].image != NULL )
		mlx_destroy_image(data->mlx.mlx_id, data->img[SOUTH].image);
	if (data->img[EAST].image != NULL)
		mlx_destroy_image(data->mlx.mlx_id, data->img[EAST].image);
	if (data->img[WEST].image != NULL)
		mlx_destroy_image(data->mlx.mlx_id, data->img[WEST].image);
	if (data->mlx.mlx_window != NULL)
		mlx_destroy_window(data->mlx.mlx_id, data->mlx.mlx_window);
	if (data->mlx.mlx_id != NULL)
		mlx_destroy_display(data->mlx.mlx_id);
	free(data->mlx.mlx_id);
}
