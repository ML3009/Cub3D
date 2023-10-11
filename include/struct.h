/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:29:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/11 18:26:46 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_key
{
	int	up;
	int	down;
	int	left;
	int	vleft;
	int	right;
	int	vright;
	int	esc;
}	t_key;

typedef struct s_ray
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	t_vector	rdir;
	t_vector	map;
	t_vector	sdist;
	t_vector	ddist;
	t_vector	step;
	double		camx;
	double		dwall;
	int			hit;
	int			side;
	int			line_height;
	int			dstart;
	int			dend;

}	t_ray;

typedef struct s_mlx
{
	void		*mlx_id;
	void		*mlx_window;
	t_vector	size;
}	t_mlx;

typedef struct s_time
{
	size_t	time;
	size_t	old_time;
}	t_time;

typedef struct s_img
{
	void		*image;
	char		*adress;
	int			bpp;
	int			endian;
	int			line_lenght;
	int			width;
	int			height;
}	t_img;

typedef struct s_rgb
{
	int	full_rgb;
	int	rgb[3];
	int	rgb_hex;
}	t_rgb;

typedef struct s_texture
{
	t_img		texture;
	t_vector	tex;
	double		wall_x;
	double		step;
	double		tex_pos;
	char		*color;
}	t_texture;

typedef struct s_data
{
	char		base_orient;
	char		**map;
	char		**texture;
	int			row;
	int			col;
	int			wallok;
	int			textok;
	t_img		base_img;
	t_img		img[4];
	t_ray		ray;
	t_mlx		mlx;
	t_key		key;
	t_rgb		rgb[2];
	t_vector	bpose;
}	t_data;

#endif
