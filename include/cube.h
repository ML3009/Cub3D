/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:20:34 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/08 16:02:08 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/libft/include/libft.h"
#include "struct.h"
#include "define.h"


/*----[ PARSING ]----*/

int		parsing(int ac, char **av, t_data *map);
int		file_extension(char *file);
void	init_map(t_data *map);
int		open_file(char *file, t_data *map);
void	count_row(char *file, t_data *map);
void	count_col(char *file, t_data *map);
bool	search_map(char *line);
bool	search_wall(char *line);
int		open_map(char *file, t_data *map, int fd);
int		check_wall(t_data *map);


