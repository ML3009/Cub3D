/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:29:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/12 11:30:37 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef	struct s_key
{
	int up;
	int down;
	int left;
	int right;
	int esc;	
}	t_key;

typedef struct s_player
{
	t_vector	pos;
	double	direction[2]; //
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
	t_player	player;
	t_mlx		mlx;
	t_key		key;

}	t_data;



