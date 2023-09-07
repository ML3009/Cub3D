/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:46:50 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/07 16:09:59 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static int	count_line(char *file);

int	parsing(int ac, char **av, t_map *map)
{
	if (ac > 2)
		send_error("Too many arguments.\n");
	else if (ac < 2)
		send_error("Too few arguments.\n");
	init_map(map);
	if (name_file(av[1]) < 0)
		return (WRONG_FILE);
	if (open_file(av[1], map) < 0)
		return (BAD_ACCESS);

	return (0);
}

int	name_file(char *file)
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

int	open_file(char *file, t_map *map)
{
	int	fd;
	char	*line;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf("File does not exist.\n"), EMPTY_FILE);
	map->map = malloc(sizeof(char *) * count_line(file));
	line = get_next_line(fd);
	while (line)
	{
		map->map[i++] = ft_strdup(line);
		line = get_next_line(fd);
	}
	map->map[i] = NULL;
	i = 0;
	while (map->map && map->map[i])
	{
		printf("map : %s\n", map->map[i]);
		i++;
	}
	return (0);

}

static int	count_line(char *file)
{
	int	fd;
	char	*line;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf("File does not exist.\n"), EMPTY_FILE);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

