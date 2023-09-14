/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:30:32 by purple            #+#    #+#             */
/*   Updated: 2023/09/13 13:45:24 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int mouse_click(int button, int x, int y, void *param) {
	t_data *tmp;

	tmp = param;
    if (button == 1) 
	{
        if (x >= tmp->mlx.size.x / 2 && y <= tmp->mlx.size.y / 2 ) {
			printf ("JEUX LANCE\n");
        } else if (x >= tmp->mlx.size.x && y >= tmp->mlx.size.y / 2 ) {
            printf ("JEUX QUITTER\n");
        }
    }
    return (0);
}

int launch_menu(t_data *data)
{
	void *menu;

	menu = NULL;
	data->mlx.mlx_window = mlx_new_window(data->mlx.mlx_id,\
	1920, 1080, "MENU");
	if (!(data->mlx.mlx_window))
		return (MLX_ERROR);
	menu = mlx_xpm_file_to_image(data->mlx.mlx_id, MENU_SPRITE, &data->mlx.size.x,&data->mlx.size.y);
	mlx_put_image_to_window(data->mlx.mlx_id, data->mlx.mlx_window, menu,1,1);
	mlx_mouse_hook(data->mlx.mlx_id, mouse_click, data);
	return (0);
}