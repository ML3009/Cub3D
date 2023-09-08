/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:14:04 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/08 12:43:31 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	init_map(t_data *map)
{
	map->map = NULL;
	map->row = 0;
	map->col = 0;
	map->SO = NULL;
	map->NO = NULL;
	map->EA = NULL;
	map->WE = NULL;
	map->F = NULL;
	map->C = NULL;
}
