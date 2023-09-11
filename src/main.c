/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:20:14 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/08 17:33:35 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"


int main(int ac, char **av)
{
	int		check_map;
	t_map	map;

	check_map = 0;
	check_map = parsing(ac, av, &data);
	if (check_map >= 0)
	{
		printf("GAME START\n");
		game_start(&data);
	}
	ft_free_tab(map.map);
	return (0);
}
