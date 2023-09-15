/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:14:04 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/14 14:41:29 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	init_map(t_data *map)
{
	ft_memset(map, 0, sizeof(t_data));
	ft_memset(&map->player, 0, sizeof(t_player));
	ft_memset(&map->player.plane, 0, sizeof(t_vector));
	ft_memset(&map->player.pos, 0, sizeof(t_vector));
	ft_memset(&map->mlx, 0, sizeof(t_mlx));
	ft_memset(&map->key, 0, sizeof(t_key));
	ft_memset(&map->mlx.size, 0, sizeof(t_vector));
	ft_memset(&map->player.dir, 0, sizeof(t_vector));
	/*map->map = NULL;
	map->row = 0;
	map->col = 0;
	map->SO = NULL;
	map->NO = NULL;
	map->EA = NULL;
	map->WE = NULL;
	map->F = NULL;
	map->C = NULL;*/
}
