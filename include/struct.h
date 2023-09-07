/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:29:06 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/07 11:36:02 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/libft/include/libft.h"


typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;


typedef struct s_player
{
	t_vector	pos;
}	t_player;



typedef struct s_map
{
	char	**map;
	t_player	player;

}	t_map;



