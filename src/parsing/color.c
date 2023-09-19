/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:02:43 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/19 15:03:14 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static int	check_color(t_data *map);

int	search_color(t_data *map, char *line)
{
	int	i;

	i = -1;
	if (!ft_strncmp(line, "F", 1) && map->F == NULL)
	{
		while (line && !ft_isdigit(line[++i]));
		map->F = ft_limited_strdup(line, i, ft_strlen(line));
	}
	i = -1;
	if (!ft_strncmp(line, "C", 1) && map->C == NULL)
	{
		while (line && !ft_isdigit(line[++i]));
		map->C = ft_limited_strdup(line, i, ft_strlen(line));
	}
	if (map->C != NULL && map->F != NULL)
		return (check_color(map));
	return (0);
}

static int	check_color(t_data *map)
{
	int		i;
	char	**color_c;
	char	**color_f;

	color_c = ft_split(map->C, ',');
	color_f = ft_split(map->F, ',');
	i	= -1;
	while (color_c[++i])
		if (ft_atoi(color_c[i]) < 0 || ft_atoi(color_c[i]) > 255)
			return (ERROR_COLOR);
	if (i != 3)
		return (ERROR_COLOR);
	i = -1;
	while (color_f[++i])
		if (ft_atoi(color_f[i]) < 0 || ft_atoi(color_f[i]) > 255)
			return (ERROR_COLOR);
	if (i != 3)
		return (ERROR_COLOR);
	return (0);
}
