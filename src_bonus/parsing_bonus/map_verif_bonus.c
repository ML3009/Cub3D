/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:37:09 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/11 13:43:33 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cube_bonus.h"

static int	check_map_2(t_data *map, int y, int x, char **map_cp);

int	check_map(t_data *map)
{
	char	**map_cp;
	int		y;
	int		x;

	map_cp = NULL;
	y = -1;
	map_cp = copy_map(map);
	if (!map_cp)
		return (printf(MALLOC), -1);
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S'
				|| map->map[y][x] == 'E' || map->map[y][x] == 'W')
				break ;
		if (map->map[y][x] == 'N' || map->map[y][x] == 'S'
			|| map->map[y][x] == 'E' || map->map[y][x] == 'W')
			break ;
	}
	if (check_map_2(map, y, x, map_cp) < 0)
		return (-1);
	if (check_wall(map, map_cp, y, x) == ERROR_WALL)
		return (ft_free_tab(map_cp), printf(WALL), ERROR_WALL);
	return (ft_free_tab(map_cp), 0);
}

static int	check_map_2(t_data *map, int y, int x, char **map_cp)
{
	if (check_player(map_cp) == ERROR_PLAYER)
		return (ft_free_tab(map_cp), printf(PLAYER), ERROR_PLAYER);
	map->bpose.x = x;
	map->bpose.y = y;
	map->base_orient = map->map[(int)map->bpose.y][(int)map->bpose.x];
	return (0);
}
