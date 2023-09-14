/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:46:50 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/14 14:43:48 by purple           ###   ########.fr       */
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
	if (check_map(map) < 0)
		return (WRONG_MAP);
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
	if (create_map(file, map, fd) < 0)
		return (WRONG_MAP);
	return (GOOD_ACCESS);
}



/*t_data	copy_map(t_data *map)
{

}*/

