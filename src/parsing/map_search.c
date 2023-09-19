/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:52:19 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/19 11:42:44 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"


bool	search_map(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] != '1' && line[i] != '\0')
		i++;
	if (line[i] == '1')
	{
		while (line[i])
		{
			if (line[i] != '1' && line[i] != '0'&& line[i] != 'N'
			&& line[i] != 'E' && line[i] != 'S' && line[i] != 'W'
			&& line[i] != '\n' && line[i] != ' ')
				return (false);
			i++;
		}
		return (true);
	}
	return (false);
}

bool	search_wall(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] != '1' && line[i] != '\0')
		i++;
	if (line && line[i] == '1')
	{
		while (line && line[i] != '\0')
		{
			if (line[i] != '1' && line[i] != '\n' && line[i] != ' ')
				return (false);
			i++;
		}
		return (true);
	}
	return (false);
}

int	search_pos(t_data *map, char *line)
{
	if (!ft_strncmp(line, "SO", 2) && map->texture[SOUTH] == NULL)
		map->texture[SOUTH] = ft_strdup(line);
	if (!ft_strncmp(line, "NO", 2) && map->texture[NORTH] == NULL)
		map->texture[NORTH] = ft_strdup(line);
	if (!ft_strncmp(line, "EA", 2) && map->texture[EAST] == NULL)
		map->texture[EAST] = ft_strdup(line);
	if (!ft_strncmp(line, "WE", 2) && map->texture[WEST] == NULL)
		map->texture[WEST] = ft_strdup(line);
	//if (map->SO != NULL && map->NO != NULL && map->EA != NULL && map->WE != NULL)
	//	return (path_ok(map));
	return (0);
}

int	search_texture(t_data *map, char *line)
{
	if (!ft_strncmp(line, "F", 1) && map->F == NULL)
		map->F = ft_strdup(line); 
	if (!ft_strncmp(line, "C", 1) && map->C == NULL)
		map->C = ft_strdup(line);
	return (0);
}

/*int	path_ok(t_data *map)
{





}*/
