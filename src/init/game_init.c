/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:10:05 by purple            #+#    #+#             */
/*   Updated: 2023/10/11 17:53:20 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void		init_orientation(t_data *data);
void		screen_size(t_data *data);
static int	path_texture(t_data *map);

int	init_the_game(t_data *data)
{
	init_orientation(data);
	data->mlx.mlx_id = mlx_init();
	if (!(data->mlx.mlx_id))
		return (MLX_ERROR);
	screen_size(data);
	data->mlx.mlx_window = mlx_new_window(data->mlx.mlx_id, \
	data->mlx.size.x, data->mlx.size.y, "Cub3D");
	if (!(data->mlx.mlx_window))
		return (MLX_ERROR);
	if (path_texture(data) < 0)
		return (printf(TEXT), -1);
	data->base_img.image = mlx_new_image(data->mlx.mlx_id, \
	data->mlx.size.x, data->mlx.size.y);
	if (!(data->base_img.image))
		return (free_mlx(data),printf(INIT),-1);
	data->base_img.adress = mlx_get_data_addr(data->base_img.image, \
	&data->base_img.bpp, &data->base_img.line_lenght, \
	&data->base_img.endian);
	if (!(data->base_img.adress))
		return (free_mlx(data),printf(INIT),-1);
	return (0);
}

void	screen_size(t_data *data)
{
	int	screen_width;
	int	screen_height;

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

void	init_orientation(t_data *data)
{
	data->ray.pos.x = data->bpose.x + 0.1;
	data->ray.pos.y = data->bpose.y + 0.1;
	if (data->base_orient == 87)
	{
		data->ray.dir.x = -1;
		data->ray.dir.y = 0;
		data->ray.plane.x = 0;
		data->ray.plane.y = 0.66;
	}
	if (data->base_orient == 69)
	{
		data->ray.dir.x = 1;
		data->ray.dir.y = 0;
		data->ray.plane.x = 0;
		data->ray.plane.y = -0.66;
	}
	if (data->base_orient == 83)
	{
		data->ray.dir.x = 0;
		data->ray.dir.y = 1;
		data->ray.plane.x = 0.66;
		data->ray.plane.y = 0;
	}
	if (data->base_orient == 78)
	{
		data->ray.dir.x = 0;
		data->ray.dir.y = -1;
		data->ray.plane.x = -0.66;
		data->ray.plane.y = 0;
	}
}

static int	path_texture(t_data *map)
{

	map->img[NORTH].image = mlx_xpm_file_to_image(map->mlx.mlx_id, \
	map->texture[NORTH], &map->img[NORTH].width, &map->img[NORTH].height);
	if (!map->img[NORTH].image)
		return (free_mlx(map), -1);

	map->img[NORTH].adress = mlx_get_data_addr(map->img[NORTH].image, \
	&map->img[NORTH].bpp, &map->img[NORTH].line_lenght, \
	&map->img[NORTH].endian);
	if (!(map->img[NORTH].adress))
		return (free_mlx(map), -1);

	map->img[SOUTH].image = mlx_xpm_file_to_image (map->mlx.mlx_id, \
	map->texture[SOUTH],&map->img[SOUTH].width, &map->img[SOUTH].height);
	if (!map->img[SOUTH].image)
		return (free_mlx(map), -1);

	map->img[SOUTH].adress = mlx_get_data_addr(map->img[SOUTH].image, \
	&map->img[SOUTH].bpp, &map->img[SOUTH].line_lenght, \
	&map->img[SOUTH].endian);
	if (!(map->img[SOUTH].adress))
		return (free_mlx(map), -1);

	map->img[EAST].image = mlx_xpm_file_to_image (map->mlx.mlx_id, \
	map->texture[EAST], &map->img[EAST].width, &map->img[EAST].height);
	if (!map->img[EAST].image)
		return (free_mlx(map), -1);

	map->img[EAST].adress = mlx_get_data_addr(map->img[EAST].image, \
	&map->img[EAST].bpp, &map->img[EAST].line_lenght, &map->img[EAST].endian);
	if (!(map->img[EAST].adress))
		return (free_mlx(map), -1);

	map->img[WEST].image = mlx_xpm_file_to_image (map->mlx.mlx_id, \
	map->texture[WEST], &map->img[WEST].width, &map->img[WEST].height);
	if (!map->img[WEST].image)
		return (free_mlx(map), -1);

	map->img[WEST].adress = mlx_get_data_addr(map->img[WEST].image, \
	&map->img[WEST].bpp, &map->img[WEST].line_lenght, \
	&map->img[WEST].endian);
	if (!(map->img[WEST].adress))
		return (free_mlx(map), -1);
	return (0);
}
