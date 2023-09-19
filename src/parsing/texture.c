/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:03:29 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/19 15:04:10 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static int	path_texture(t_data *map);

int	search_texture(t_data *map, char *line)
{
	if (!ft_strncmp(line, "SO", 2) && map->texture[SOUTH] == NULL)
		map->texture[SOUTH] = ft_strdup(line);
	if (!ft_strncmp(line, "NO", 2) && map->texture[NORTH] == NULL)
		map->texture[NORTH] = ft_strdup(line);
	if (!ft_strncmp(line, "EA", 2) && map->texture[EAST] == NULL)
		map->texture[EAST] = ft_strdup(line);
	if (!ft_strncmp(line, "WE", 2) && map->texture[WEST] == NULL)
		map->texture[WEST] = ft_strdup(line);
	if (map->texture[SOUTH] != NULL && map->texture[NORTH] != NULL
		&& map->texture[EAST] != NULL && map->texture[WEST] != NULL)
		return (path_texture(map));
	return (0);
}

static int	path_texture(t_data *map)
{
	(void)map;
	return (0);
}
