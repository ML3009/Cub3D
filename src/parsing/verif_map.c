/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:39:43 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/14 11:40:37 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	check_map(t_data *map)
{
	int	i;
	printf ("row : %i\n", map->row);
	printf ("col : %i\n", map->col);
	for (int k = 0; map->map[k]; k++)
		printf("map : %s\n", map->map[k]);
	i = -1;
	while (map->map[0][++i] != '1');
	if (check_wall(map, i) == ERROR_WALL)
		return (printf("Wall does not ok.\n"), ERROR_WALL);

	return (0);
}

int	check_wall(t_data *map, int pos)
{
	(void)map;
	printf("%i\n", pos);

	return (0);


}
