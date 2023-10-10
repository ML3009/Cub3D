/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:22:03 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/10 17:36:18 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void mouse_pov(t_data *data)
{
	mlx_mouse_hide(data->mlx.mlx_id, data->mlx.mlx_window);

	return ;
}
