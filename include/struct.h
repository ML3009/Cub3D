/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:29:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/08 12:42:05 by mvautrot         ###   ########.fr       */
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
}	t_player;



typedef struct s_data
{
	char	**map;
	char	*SO;
	char	*NO;
	char	*EA;
	char	*WE;
	char	*F;
	char	*C;
	int		row;
	int		col;
	t_player	player;

}	t_data;



