/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:20:14 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/02 13:54:32 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	free_all_map(t_data map);

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
	free_all_map(map);
	return (0);
}

void	free_all_map(t_data map)
{

	//free(map.SO);
	//free(map.NO);
	//free(map.WE);
	//free(map.EA);
	//free(map.F);
	//free(map.C);
	ft_free_tab(map.map);

}
