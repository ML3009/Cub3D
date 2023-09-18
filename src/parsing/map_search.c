/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:52:19 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/18 12:13:26 by mvautrot         ###   ########.fr       */
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
	if (!ft_strncmp(line, "SO", 2) && map->SO == NULL)
		map->SO = ft_strdup(line);
	if (!ft_strncmp(line, "NO", 2) && map->NO == NULL)
		map->NO = ft_strdup(line);
	if (!ft_strncmp(line, "EA", 2) && map->EA == NULL)
		map->EA = ft_strdup(line);
	if (!ft_strncmp(line, "WE", 2) && map->WE == NULL)
		map->WE = ft_strdup(line);
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
