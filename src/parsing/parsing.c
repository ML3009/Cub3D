/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:46:50 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/19 11:22:08 by mvautrot         ###   ########.fr       */
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
	init_map(map);
	check_map = mapsing(av, map);
	return (check_map);
}

static int	mapsing(char **av, t_data *map)
{
	if (file_extension(av[1]) < 0)
		return (WRONG_FILE);
	if (open_file(av[1]) < 0)
		return (BAD_ACCESS);
	if (create_map(av[1], map) < 0)
		return (WRONG_MAP);
	if (check_map(map) < 0)
		return (WRONG_MAP);
	return (0);
}


