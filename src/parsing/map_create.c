/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:36:36 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/06 11:57:14 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	save_map(char *line, int fd, t_data *map);

int	create_map(char *file, t_data *map)
{
	char	*line;
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (EMPTY_FILE);
	count_row(file, map); // y
	count_col(file, map); // x
	line = get_next_line(fd);
	while (line && search_map(line) == false)
	{
		if (search_color(map, line) < 0)
			return (printf(COLOR), free(line), ERROR_COLOR);
		search_texture(map, line);
		free(line);
		line = get_next_line(fd);
	}
	if (map->textOk != 4 || map->rgb->full_rgb != 2)
		return (free(line), printf(TEXT), ERROR_TEXTURE);
	if (save_map(line, fd, map) < 0)
		return (printf(SAVE), ERROR_WALL);
	return (0);
}

int	save_map(char *line, int fd, t_data *map)
{
	int	i;

	i = -1;
	if (line && search_wall(line) == true)
	{
		map->map = malloc(sizeof(char *) * (map->row + 1));
		if (!map->map)
			return (printf(MALLOC), -1);
		while (line && search_map(line) == true)
		{
			map->map[++i] = ft_strdup(line);
			free(line);
			line = get_next_line(fd);
		}
	}
	else
		return(close(fd), free(line), ERROR_WALL);
	free(line);
	map->map[++i] = NULL;
	if (search_wall(map->map[i - 1]) == false)
		return (ERROR_WALL);
	line = get_next_line(fd);
	if (line != NULL)
		return (close(fd), free(line), ERROR_WALL);
	free(line);
	close(fd);
	return (0);
}
