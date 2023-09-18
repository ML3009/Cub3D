/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:36:36 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/18 11:59:37 by mvautrot         ###   ########.fr       */
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
	line = NULL;
	count_row(file, map); // y
	count_col(file, map); // x
	map->map = malloc(sizeof(char *) * (map->row + 1));
	line = get_next_line(fd);
	while (line && search_wall(line) == false)
	{
		if (search_pos(map, line) < 0)
			return (printf ("Texture error\n"), ERROR_TEXTURE);
		if (search_texture(map, line) < 0)
			return (printf("Color error\n"), ERROR_COLOR);
		free(line);
		line = get_next_line(fd);
	}
	if (save_map(line, fd, map) < 0)
		return (printf ("Map error\n"), ERROR_WALL);
	return (0);
}

int	save_map(char *line, int fd, t_data *map)
{
	int	i;

	i = -1;
	if (line && search_wall(line) == true)
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
