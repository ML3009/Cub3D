/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:36:36 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/18 11:29:53 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"
bool	search_wall(char *line);

int	create_map(char *file, t_data *map, int fd)
{
	char	*line;
	int	i;

	i = -1;
	line = NULL;
	count_row(file, map); // y
	count_col(file, map); // x
	map->map = malloc(sizeof(char *) * (map->row + 1));
	line = get_next_line(fd);
	while (line && search_wall(line) == false)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (search_wall(line) == true)
	{
		while (line && search_map(line) == true)
		{
			map->map[++i] = ft_strdup(line);
			free(line);
			line = get_next_line(fd);
		}
	}
	free(line);
	map->map[++i] = NULL;
	if (search_wall(map->map[i - 1]) == false)
		return (printf("Wall does not ok.\n"), ERROR_WALL);
	close(fd);
	return (0);
}

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
