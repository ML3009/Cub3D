/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:24:50 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/12 15:06:10 by mvautrot         ###   ########.fr       */
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
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		send_error("File does not exist.\n");
	line = get_next_line(fd);
	while (line)
	{
		if (search_map(line) == true)
			break;
		free(line);
		line = get_next_line(fd);
	}
	i = ft_strlen(line);
	free(line);
	close(fd);
	map->col = i - 1;
	return ;
}


int	check_wall(t_data *map)
{
	int	j;

	j = -1;
	while (map->map[0][++j])
			if (map->map[0][j] != ' ' && map->map[0][j] != '1' && map->map[0][j] != '\n')
				printf ("ERROR_MAP_ROW_FIRST\n");
	j = -1;
	while (map->map[map->row - 1][++j])
		if (map->map[map->row - 1][j] != ' ' && map->map[map->row - 1][j] != '1' && map->map[map->row - 1][j] != '\n')
				printf ("ERROR_ROW_LAST\n");
	j = -1;
	while (++j < (map->row))
	{
		if (map->map[j][0] != ' ' && map->map[j][0] != '1' && map->map[j][0] != '\n')
			printf("ERROR_MAP_COL_FIRST\n");

	}
	j = -1;
	printf (" MAP COL %c\n", map->map[0][map->col - 1]);
	while (++j < (map->row -1))
	{
		if (map->map[j][map->row -1] != '1')
			break;
	}
			printf("ERROR_MAP_COL_LAST\n");
	return (0);

		//if (map->map[j][map->col - 1] && map->map[j][map->col - 1] != ' ' && map->map[j][map->col - 1] != '1' && map->map[j][map->col - 1] != '\n')
}
