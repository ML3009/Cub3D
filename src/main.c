/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:20:14 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/07 14:11:02 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"


int main(int ac, char **av)
{
	int	check_map;
	t_map	map;

	check_map = 0;
	if (ac > 2)
		ft_perror("Too many arguments.");
	check_map = parsing(ac, av, &map);
	if (check_map)
	{
		printf("GAME START\n");
		//game_start();
	}
	return (0);
}
