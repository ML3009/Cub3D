/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:24:50 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/04 13:25:12 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	count_row(char *file, t_data *map)
{
	int	fd;
	char	*line;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		send_error("File does not exist.\n");
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

void	count_col(char *file, t_data *map)
{
	int	fd;
	char	*line;
	char	*size;
	int	i;

	i = 0;
	size = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		send_error("File does not exist.\n");
	line = get_next_line(fd);
	while (line)
	{
		if (search_map(line) == true)
		{
			if (size && ft_strlen(line) > ft_strlen(size))
				free(size);
			size = ft_strdup(line);
		}
		free(line);
		line = get_next_line(fd);
	}
	i = ft_strlen(size);
	free(line);
	free(size);
	close(fd);
	map->col = i;
	return ;
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
