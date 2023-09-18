/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:20:14 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/18 11:19:32 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"


int main(int ac, char **av)
{
	int		check_map;
	t_data	map;

	
	check_map = 0;
	check_map = parsing(ac, av, &map);
	if (check_map >= 0)
	{
		printf ("game start\n");
		game_start(&map);
	}
	ft_free_tab(map.map);
	return (0);
}
