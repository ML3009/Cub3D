/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:20:14 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/11 18:15:21 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/cube_bonus.h"

int main(int ac, char **av)
{
	int		check_map;
	t_data	map;


	check_map = 0;
	check_map = parsing(ac, av, &map);
	if (check_map >= 0)
		game_start(&map);
	free_all_map(&map);
	return (0);
}
