/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:29:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/11 13:56:50 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;


typedef struct s_player
{
	t_vector	pos;
	double	direction[2]; 
}	t_player;

typedef struct s_mlx
{
	void *mlx_id;
	void *mlx_window;
	t_vector size;
}	t_mlx;

typedef struct s_data
{
	char		base_orient;
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

}	t_data;



