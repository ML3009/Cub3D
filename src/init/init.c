/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:14:04 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/19 13:27:32 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	init_map(t_data *map)
{
	ft_memset(map, 0, sizeof(t_data));
	ft_memset(&map->player, 0, sizeof(t_player));
	ft_memset(&map->player.plane, 0, sizeof(t_vector));
	ft_memset(&map->player.map, 0, sizeof(t_vector));
	ft_memset(&map->player.step, 0, sizeof(t_vector));
	ft_memset(&map->player.texture, 0, sizeof(t_vector));
	ft_memset(&map->player.side, 0, sizeof(t_vector));
	ft_memset(&map->player.d, 0, sizeof(t_vector));
	ft_memset(&map->player.dir, 0, sizeof(t_vector));
	ft_memset(&map->player.cam, 0, sizeof(t_vector));
	ft_memset(&map->player.raydir, 0, sizeof(t_vector));
	ft_memset(&map->player.pos, 0, sizeof(t_vector));
	ft_memset(&map->mlx, 0, sizeof(t_mlx));
	ft_memset(&map->key, 0, sizeof(t_key));
	ft_memset(&map->mlx.size, 0, sizeof(t_vector));
}