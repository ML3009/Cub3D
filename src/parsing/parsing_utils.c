/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:24:50 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/08 17:33:42 by purple           ###   ########.fr       */
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
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if ((map->map[0][j] != '1' && map->map[0][j] != ' ')
				&& (map->map[map->row - 1][j] != '1' && map->map[map->row - 1][j] != ' '))
				printf("test0\n");
			if ((map->map[i][0] != '1' && map->map[i][0] != ' ')
				&& (map->map[i][map->col - 1] != '1' && map->map[i][map->col - 1] != ' '))
				printf("test\n");
			j++;
		}
		i++;
	}

	printf ("row : %i\n", map->row);
	printf ("col : %i\n", map->col);
	for (int k = 0; map->map[k]; k++)
		printf("map : %s\n", map->map[k]);


	return (0);

}
