/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:37:09 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/05 10:38:22 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	check_map(t_data *map)
{
	char	**map_cp;
	int	y;
	int	x;
	/*printf ("row : %i\n", map->row);
	printf ("col : %i\n", map->col);*/
	for (int k = 0; map->map[k]; k++)
		printf("map : %s\n", map->map[k]);
	/*printf ("SO : [%s]\nNO : [%s]\nEA : [%s]\nWE : [%s]\n\n", map->texture[SOUTH], map->texture[NORTH], map->texture[EAST], map->texture[WEST]);
	printf ("R CEIL: %i \n", map->rgb[CEIL].rgb[0]);
	printf ("G CEIL : %i \n", map->rgb[CEIL].rgb[1]);
	printf ("B CEIL : %i\n\n", map->rgb[CEIL].rgb[2]);
	printf ("R FLOOR : %i \n", map->rgb[FLOOR].rgb[0]);
	printf ("G FLOOR : %i\n", map->rgb[FLOOR].rgb[1]);
	printf ("B FLOOR : %i\n", map->rgb[FLOOR].rgb[2]);*/
	map_cp = NULL;
	y = -1;
	map_cp = copy_map(map);
	if (!map_cp)
		return (printf("Map : malloc error.\n"), -1);
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || map->map[y][x] == 'E' || map->map[y][x] == 'W')
				break;
		if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || map->map[y][x] == 'E' || map->map[y][x] == 'W')
			break;
	}
	if (check_player(map_cp) == ERROR_PLAYER)
		return (ft_free_tab(map_cp), printf("Map : error player\n"), ERROR_PLAYER);
	map->bpose.x = x;
	map->bpose.y = y;
	map->base_orient = map->map[(int)map->bpose.y][(int)map->bpose.x];
	if (check_wall(map, map_cp, y, x) == ERROR_WALL)
	{
		for (int k = 0; map_cp[k]; k++)
			printf("map : %s\n", map_cp[k]);
		return (ft_free_tab(map_cp), printf("Map : error wall.\n"), ERROR_WALL);
	}
	ft_free_tab(map_cp);
	return (0);
}
