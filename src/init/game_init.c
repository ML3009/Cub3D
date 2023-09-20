/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:10:05 by purple            #+#    #+#             */
/*   Updated: 2023/09/20 12:02:19 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void init_orientation(t_data *data);
void screen_size(t_data *data);
static int	path_texture(t_data *map);

int init_the_game(t_data *data)
{
	init_orientation(data);
	if (!(data->mlx.mlx_id = mlx_init()))
		return (MLX_ERROR);
	screen_size(data);
	if (!(data->mlx.mlx_window = mlx_new_window(data->mlx.mlx_id, data->mlx.size.x,  data->mlx.size.y, "Cub3D")))
		return (MLX_ERROR);
	if (path_texture(data) < 0)
		return (printf("Map : path error.\n"), -1);
	data->base_img[0].image = mlx_new_image(data->mlx.mlx_id,data->mlx.size.x, data->mlx.size.y);
	data->base_img[0].adress = mlx_get_data_addr(data->base_img[0].image , &data->base_img[0].bpp, &data->base_img[0].line_lenght, &data->base_img[0].endian);

	return (0);

}

void screen_size(t_data *data)
{
	int screen_width;
	int screen_height;

	mlx_get_screen_size(data->mlx.mlx_id, &screen_width, &screen_height);
	if (screen_width >= 1920)
		data->mlx.size.x = 1920;
	else
		data->mlx.size.x = 848;
	if (screen_height >= 1080)
		data->mlx.size.y = 1080;
	else
		data->mlx.size.y = 480;
}

void init_orientation(t_data *data)
{
	if (data->base_orient == 'S' || data->base_orient == 'N')
	{
		data->player.dir.y = 0;
		if (data->base_orient == 'S')
			data->player.dir.x = 1;
		else
			data->player.dir.x = -1;
	}
	else
	{
		data->player.dir.x = 0;
		if (data->base_orient == 'E')
			data->player.dir.y = 1;
		else
			data->player.dir.y = -1;
	}
	data->player.plane.x = 0;
	data->player.plane.y = 0.66;
}

static int	path_texture(t_data *map)
{
	int width = (int)map->mlx.size.x;
	int height = (int)map->mlx.size.y;
	map->img[NORTH].image = mlx_xpm_file_to_image (map->mlx.mlx_id, map->texture[NORTH], &width, &height);
	if (!map->img[NORTH].image)
		return (printf ("Texture : north\n"),-1);
	map->img[NORTH].adress = mlx_get_data_addr(map->img[NORTH].image, &map->img[NORTH].bpp, &map->img[NORTH].line_lenght, &map->img[NORTH].endian);
	map->img[SOUTH].image = mlx_xpm_file_to_image (map->mlx.mlx_id, map->texture[SOUTH], &width, &height);
	if (!map->img[SOUTH].image)
		return (printf ("Texture : south\n"), -1);
	map->img[SOUTH].adress = mlx_get_data_addr(map->img[SOUTH].image, &map->img[SOUTH].bpp, &map->img[SOUTH].line_lenght, &map->img[SOUTH].endian);
	map->img[EAST].image = mlx_xpm_file_to_image (map->mlx.mlx_id, map->texture[EAST], &width, &height);
	if (!map->img[EAST].image)
		return (printf ("Texture : east\n"), -1);
	map->img[EAST].adress = mlx_get_data_addr(map->img[EAST].image, &map->img[EAST].bpp, &map->img[EAST].line_lenght, &map->img[EAST].endian);
	map->img[WEST].image = mlx_xpm_file_to_image (map->mlx.mlx_id, map->texture[WEST], &width, &height);
	if (!map->img[WEST].image)
		return (printf ("Texture : west\n"), -1);
	map->img[WEST].adress = mlx_get_data_addr(map->img[WEST].image, &map->img[WEST].bpp, &map->img[WEST].line_lenght, &map->img[WEST].endian);
	return (0);
}
