/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:47:04 by purple            #+#    #+#             */
/*   Updated: 2023/09/08 16:17:57 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void game_start(t_data *data)
{
	if (init_the_game(data) < 0)
		return ;
	//if (launch_menu(data) < 0)
	//	return ;
	
	mlx_loop(data->mlx.mlx_id);
}