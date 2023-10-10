/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:20:34 by purple            #+#    #+#             */
/*   Updated: 2023/10/10 14:12:07 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	raycasting(t_data *data)
{
	int	x;

	x = -1;
	//mlx_clear_window(data->mlx.mlx_id, data->mlx.mlx_window);
	while (++x < data->mlx.size.x)
	{
		data->ray.camx = 2 * x / (double)data->mlx.size.x - 1;
		data->ray.rdir.x = data->ray.dir.x + data->ray.plane.x * data->ray.camx;
		data->ray.rdir.y = data->ray.dir.y + data->ray.plane.y * data->ray.camx;
		data->ray.map.x = (int)data->ray.pos.x;
		data->ray.map.y = (int)data->ray.pos.y;
		data->ray.hit = 0;
		init_dda(data);
		init_step(data);
		dda(data);
		wall_coo(data);
		draw_wall(data, x);
	}
	draw_mini_map(data);
	mlx_put_image_to_window(data->mlx.mlx_id, data->mlx.mlx_window, data->base_img.image, 0, 0);

}

void	draw_void(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->mlx.size.x)
	{
		j = -1;
		while (++j < data->mlx.size.y / 2)
			img_pix_put(&data->base_img, i, j, data->rgb[CEIL].rgb_hex);
		while (++j < data->mlx.size.y)
			img_pix_put(&data->base_img, i, j, data->rgb[FLOOR].rgb_hex);
	}
}

void draw_wall(t_data *data, int x)
{
	t_texture tmp;

	tmp = init_draw_wall(data);
	while (data->ray.dstart < data->ray.dend)
	{
		tmp.tex.y = (int)tmp.tex_pos & (TEXTURE - 1);
		tmp.tex_pos += tmp.step;
		tmp.color = tmp.texture.adress + (int)(tmp.tex.y *  tmp.texture.line_lenght + tmp.tex.x *( tmp.texture.bpp / 8));
		img_pix_put(&data->base_img, x, data->ray.dstart, *(int *)tmp.color);
		data->ray.dstart++;
	}
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->adress + ((y * img->line_lenght) + (x * (img->bpp / 8)));
	*(int *)pixel = color;
}
