/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_verif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:38:26 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/09 14:13:55 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	check_player(char **map)
{
	int	y;
	int	x;
	int	player;

	y = -1;
	player = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
				player++;
	}
	if (player > 1 || player < 1)
		return (ERROR_PLAYER);
	return (0);
}
