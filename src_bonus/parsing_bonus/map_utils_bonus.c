/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:24:50 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/11 18:15:44 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cube_bonus.h"

void	count_row(char *file, t_data *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		send_error(EF);
	line = get_next_line(fd);
	while (line)
	{
		if (search_map(line) == true)
			i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	map->row = i;
	return ;
}

int	count_col(char *file, t_data *map, char *size)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		send_error(EF);
	line = get_next_line(fd);
	while (line)
	{
		if (search_map(line) == true)
		{
			if (!size)
				size = ft_strdup(line);
			if (size && ft_strlen(line) > ft_strlen(size))
			{
				free(size);
				size = ft_strdup(line);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	map->col = ft_strlen(size);
	return (free(line), free(size), close(fd), 0);
}

char	**copy_map(t_data *map)
{
	int		i;
	char	**map_cp;

	i = -1;
	map_cp = malloc(sizeof(char *) * (map->row + 1));
	while (map->map[++i])
		map_cp[i] = ft_strdup(map->map[i]);
	map_cp[i] = NULL;
	return (map_cp);
}

void	free_all_map(t_data *map)
{
	free(map->texture[NORTH]);
	free(map->texture[SOUTH]);
	free(map->texture[WEST]);
	free(map->texture[EAST]);
	free(map->texture);
	ft_free_tab(map->map);
	return ;
}
