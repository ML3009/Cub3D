/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:14:04 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/11 13:43:03 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cube_bonus.h"

void	init_map(t_data *map)
{
	ft_memset(map, 0, sizeof(t_data));
	map->texture = malloc(sizeof(char *) * 4);
	if (!map->texture)
		printf(MALLOC);
	ft_memset(map->texture, 0, sizeof(char *) * 4);
	ft_memset(&map->ray.pos, 0, sizeof(t_vector));
	ft_memset(&map->ray.dir, 0, sizeof(t_vector));
	ft_memset(&map->ray.plane, 0, sizeof(t_vector));
	ft_memset(&map->ray.map, 0, sizeof(t_vector));
	ft_memset(&map->ray.sdist, 0, sizeof(t_vector));
	ft_memset(&map->ray.ddist, 0, sizeof(t_vector));
	ft_memset(&map->ray.step, 0, sizeof(t_vector));
	ft_memset(&map->mlx, 0, sizeof(t_mlx));
	ft_memset(&map->key, 0, sizeof(t_key));
	ft_memset(&map->mlx.size, 0, sizeof(t_vector));
	ft_memset(&map->base_img, 0, sizeof(t_img));
	ft_memset(&map->img, 0, sizeof(t_img));
	ft_memset(&map->rgb, 0, sizeof(t_rgb));
}
