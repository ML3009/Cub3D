/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:20:34 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/07 14:21:58 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/libft/include/libft.h"
#include "struct.h"
#include "define.h"


/*----[ PARSING ]----*/

int		parsing(int ac, char **av, t_map *map);
int		name_file(char *file);
void	init_map(t_map *map);
int		open_file(char *file, t_map *map);


