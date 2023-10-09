/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:02:43 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/09 14:11:18 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static int	check_color(t_data *map, char *F, char *C);
static int	valid_color(char **color, int i);
static int	line_color(char *line, int i);

int	search_color(t_data *map, char *line, int i, int j)
{
	static char	f[20];
	static char	c[20];

	if ((!ft_strncmp(line, "F", 1) && ft_strlen(f) > 1)
		|| (!ft_strncmp(line, "C", 1) && ft_strlen(c) > 1))
		map->rgb->full_rgb++;
	if (!ft_strncmp(line, "F", 1) && ft_strlen(f) < 1)
	{
		map->rgb->full_rgb++;
		i = line_color(line, i);
		while ((line && line [i] != ' ') && i < (int)ft_strlen(line))
			f[j++] = line[i++];
	}
	i = -1;
	j = 0;
	if (!ft_strncmp(line, "C", 1) && ft_strlen(c) < 1)
	{
		map->rgb->full_rgb++;
		i = line_color(line, i);
		while ((line && line [i] != ' ') && (i < (int)ft_strlen(line)))
			c[j++] = line[i++];
	}
	if (ft_strlen(f) > 1 && ft_strlen(c) > 1)
		return (check_color(map, f, c));
	return (0);
}

static int	line_color(char *line, int i)
{
	while (line && !ft_isdigit(line[++i]))
		;
	if (line[i - 1] == '-')
			i--;
	return (i);
}

static int	check_color(t_data *map, char *F, char *C)
{
	int		i;
	char	**color_c;
	char	**color_f;

	color_c = ft_split(C, ',');
	color_f = ft_split(F, ',');
	i = -1;
	while (color_c[++i])
	{
		if (valid_color(color_c, i))
			return (ft_free_tab(color_c), ft_free_tab(color_f), ERROR_COLOR);
		map->rgb[CEIL].rgb[i] = ft_atoi(color_c[i]);
	}
	if (i != 3)
		return (ft_free_tab(color_c), ft_free_tab(color_f), ERROR_COLOR);
	i = -1;
	while (color_f[++i])
	{
		if (valid_color(color_f, i))
			return (ft_free_tab(color_c), ft_free_tab(color_f), ERROR_COLOR);
		map->rgb[FLOOR].rgb[i] = ft_atoi(color_f[i]);
	}
	if (i != 3)
		return (ft_free_tab(color_c), ft_free_tab(color_f), ERROR_COLOR);
	return (ft_free_tab(color_c), ft_free_tab(color_f), 0);
}

static	int	valid_color(char **color, int i)
{
	if (ft_atoi(color[i]) < 0 || ft_atoi(color[i]) > 255
		|| ft_strlen(color[i]) <= 0 || ft_strlen(color[i]) > 4
		|| !(color[i][0] >= '0' && color[i][0] <= '9'))
		return (1);
	return (0);
}
