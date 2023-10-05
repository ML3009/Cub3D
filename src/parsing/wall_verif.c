/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:39:43 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/05 11:14:34 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static void	atypic_wall(t_data *data, char **map, int y, int x);
static int	check_again(t_data *data, char **map, int y, int x);
//static int	find_way(char **map_cp);

int	check_wall(t_data *map, char **map_cp, int y, int x)
{
	atypic_wall(map, map_cp, y, x);
	y = -1;
	while (map_cp[++y])
	{
		x = -1;
		while (map_cp[y][++x])
			if (map_cp[y][x] == '0')
				check_wall(map, map_cp, y, x);
	}
	/*if (find_way(map_cp) < 0)
		return (ERROR_WALL);*/
	if (map->wallOk > 0)
		return (ERROR_WALL);
	return (0);
}

/*static int	find_way(char **map_cp)
{
	int x;
	int	y;
	int	save_pos;

	y = 0;
	x = -1;
	while (map_cp[y][++x])
	{
		if (map_cp[y][x] == ' ')
		{
			save_pos = -1;
			while (map_cp[++save_pos][x] == ' ' && )

		}
	}
	return (0);
}*/



static void	atypic_wall(t_data *data, char **map, int y, int x)
{
	map[y][x] = 'Y';
	if (!check_again(data, map, y, x) && map[y][x] && map[y + 1][x] == '0')
		atypic_wall(data, map, y + 1, x);
	if (!check_again(data, map, y, x) && map[y][x] && map[y - 1][x] == '0')
		atypic_wall(data, map, y - 1, x);
	if (!check_again(data, map, y, x) && map[y][x] && map[y][x + 1] == '0')
		atypic_wall(data, map, y, x + 1);
	if (!check_again(data, map, y, x) && map[y][x] && map[y][x - 1] == '0')
		atypic_wall(data, map, y, x - 1);
	return ;
}

static int	check_again(t_data *data, char **map, int y, int x)
{
	if (map[y + 1] == NULL || map[y + 1][x] == ' ' || map[y + 1][x] == '\0' || map[y + 1][x] == '\t'|| map[y + 1][x] == '\n')
		return (data->wallOk++, -1);
	else if (map[y - 1] == NULL || map[y - 1][x] == ' ' || map[y - 1][x] == '\0' || map[y - 1][x] == '\t' || map[y - 1][x] == '\n')
		return (data->wallOk++, -1);
	else if (map[y][x + 1] == ' ' || map[y][x + 1] == '\0' || map[y][x + 1] == '\t' || map[y][x + 1] == '\n')
		return (data->wallOk++, -1);
	else if (map[y][x - 1] == ' ' || map[y][x - 1] == '\0' || map[y][x - 1] == '\t' || map[y][x - 1] == '\n')
		return (data->wallOk++, -1);
	else
		return (0);
}
