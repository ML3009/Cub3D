/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:29:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/03 15:31:35 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef	struct s_key
{
	int up;
	int down;
	int left;
	int vleft;
	int right;
	int vright;
	int esc;
}	t_key;

typedef struct s_player
{
	t_vector	pos;
	t_vector	d;
	t_vector	dir;
	t_vector	cam;
	t_vector	plane;
	t_vector	raydir;
	t_vector	map;
	t_vector	step;
	t_vector	side;
	t_vector	texture;
	unsigned int color;
	double		wall_dist;
	double		sstep;
	double		text_pos;
	int			orientation;
	int			sside;
	int			line_height;
	int 		draw_start;
	int			draw_end;
}	t_player;

typedef struct s_mlx
{
	void *mlx_id; // mlx_init
	void *mlx_window; // mlx_new_wind
	t_vector size;
}	t_mlx;

typedef struct s_ray
{
	size_t time;
	size_t old_time;
}	t_ray;

typedef	struct s_img
{
	void		*image; // xpm to imh
	char		*adress; // img to adress
	int			bpp; // nb de bits par pixel sur img
	int			endian; // maniere dont les bits sont organises
	int			line_lenght; // taille de la ligne
}	t_img;

typedef struct s_rgb
{
	int	full_rgb;
	int	rgb[3];
} t_rgb;


typedef struct s_data
{
	char		base_orient;
	char		**map;
	char		**texture;
	int			row;
	int			col;
	int			wallOk;
	t_img		base_img[2];
	t_img		img[4];
	t_player	player;
	t_mlx		mlx;
	t_key		key;
	t_rgb		rgb[2];

}	t_data;



