/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:02:43 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/20 13:02:35 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static int	check_color(t_data *map, char *F, char *C);
static int	valid_color(char **color, int i);

int	search_color(t_data *map, char *line)
{
	int	i;
	static char	*F;
	static char	*C;

	i = -1;
	if (!ft_strncmp(line, "F", 1) && F == NULL)
	{
		while (line && !ft_isdigit(line[++i]));
		F = ft_limited_strdup(line, i, ft_strlen(line));
	}
	i = -1;
	if (!ft_strncmp(line, "C", 1) && C == NULL)
	{
		while (line && !ft_isdigit(line[++i]));
		C = ft_limited_strdup(line, i, ft_strlen(line));
	}
	if (C != NULL && F != NULL)
		return (check_color(map, F, C));
	return (0);
}

static int	check_color(t_data *map, char *F, char *C)
{
	int		i;
	char	**color_c;
	char	**color_f;

	color_c = ft_split(C, ',');
	color_f = ft_split(F, ',');
	i	= -1;
	while (color_c[++i])
	{
		if (valid_color(color_c, i))
			return (ERROR_COLOR);
		map->rgb[CEIL].rgb[i] = ft_atoi(color_c[i]);
	}
	if (i != 3)
		return (ERROR_COLOR);
	i = -1;
	while (color_f[++i])
	{
		if (valid_color(color_f, i))
			return (ERROR_COLOR);
		map->rgb[FLOOR].rgb[i] = ft_atoi(color_f[i]);
	}
	if (i != 3)
		return (ERROR_COLOR);
	return (0);
}

static	int	valid_color(char **color, int i)
{
	if (ft_atoi(color[i]) < 0 || ft_atoi(color[i]) > 255 || ft_strlen(color[i]) <= 0
		|| ft_strlen(color[i]) > 4 || !(color[i][0] >= '0' && color[i][0] <= '9'))
		return (1);
	return (0);
}
