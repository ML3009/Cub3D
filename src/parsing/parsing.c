/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:46:50 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/11 14:25:28 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static int	mapsing(char **av, t_data *map);

int	parsing(int ac, char **av, t_data *map)
{
	int	check_map;

	if (ac > 2)
		send_error("Too many arguments.\n");
	else if (ac < 2)
		send_error("Too few arguments.\n");
	check_map = mapsing(av, map);
	return (check_map);
}

static int	mapsing(char **av, t_data *map)
{
	init_map(map);
	if (file_extension(av[1]) < 0)
		return (WRONG_FILE);
	if (open_file(av[1], map) < 0)
		return (BAD_ACCESS);
	return (0);
}

int	file_extension(char *file)
{
	int	i;

	if (!file)
		return (EMPTY_FILE);
	i = -1;
	while (file[++i]);
	if ((file[i - 1] != 'b' && file[i - 2] != 'u'
		&& file[i - 3] != 'c' && file[i - 4] != '.') || ft_strlen(file) < 4)
		return (printf("Wrong file extension.\n"), WRONG_FILE_NAME);
	return (0);
}

int	open_file(char *file, t_data *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf("File does not exist.\n"), EMPTY_FILE);
	if (open_map(file, map, fd) < 0)
		return (WRONG_MAP);
	return (GOOD_ACCESS);
}

int	open_map(char *file, t_data *map, int fd)
{
	char	*line;
	char	*bf_line;
	int	i;

	i = 0;
	line = NULL;
	bf_line = NULL;

	count_row(file, map); // y
	count_col(file, map); // x
	map->map = malloc(sizeof(char *) * (map->row + 2));
	line = get_next_line(fd);
	bf_line = ft_strdup(line);
	while (line)
	{
		if (search_map(bf_line) == true && search_map(line) == true)
				map->map[i++] = ft_strdup(bf_line);
		free(bf_line);
		bf_line = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	if (search_map(bf_line) == true)
		map->map[i++] = ft_strdup(bf_line);
	free(bf_line);
	map->map[i] = NULL;
	close(fd);
		printf ("row : %i\n", map->row);
	printf ("col : %i\n", map->col);
	for (int k = 0; map->map[k]; k++)
		printf("map : %s\n", map->map[k]);
	//if (check_wall(map) == ERROR_WALL)
	//	return (printf("Wall does not ok.\n"), ERROR_WALL);
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
			&& line[i] != 'E' && line[i] != 'S' && line[i] != 'W' && line[i] != '\n' && line[i] != ' ')
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
	if (line[i] == '1')
	{
		//printf ("test\n");
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
