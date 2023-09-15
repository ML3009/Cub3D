/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:29:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/15 15:25:51 by mvautrot         ###   ########.fr       */
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
	t_vector	dir;
	t_vector	plane;
}	t_player;

typedef struct s_mlx
{
	void *mlx_id;
	void *mlx_window;
	t_vector size;
}	t_mlx;

typedef struct s_ray
{
	size_t time;
	size_t old_time;
}	t_ray;

typedef struct s_data
{
	char		base_orient;
	void		*image;
	char		*adress;
	int			bpp;
	int			endian;
	int			line_lenght;
	char		**map;
	char		*SO;
	char		*NO;
	char		*EA;
	char		*WE;
	char		*F;
	char		*C;
	int			row;
	int			col;
	int			wallOk;
	t_player	player;
	t_mlx		mlx;
	t_key		key;

}	t_data;



