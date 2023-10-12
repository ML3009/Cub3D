/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:53:11 by purple            #+#    #+#             */
/*   Updated: 2023/10/12 10:41:36 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cube_bonus.h"

void	mlx_free_anim(t_data *data);

void	free_mlx_b(t_data *data)
{
	free_all_map(data);
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
	mlx_free_anim(data);
	if (data->mlx.mlx_window != NULL)
		mlx_destroy_window(data->mlx.mlx_id, data->mlx.mlx_window);
	if (data->mlx.mlx_id != NULL)
		mlx_destroy_display(data->mlx.mlx_id);
	free(data->mlx.mlx_id);
}

void	mlx_free_anim(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 15)
	{
		if (data->anim[i].image != NULL)
			mlx_destroy_image(data->mlx.mlx_id, data->anim[i].image);
	}
	return ;
}
