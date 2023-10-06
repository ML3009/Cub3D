/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:02:43 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/06 11:41:15 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static int	check_color(t_data *map, char *F, char *C);
static int	valid_color(char **color, int i);

int	search_color(t_data *map, char *line)
{
	int	i;
	int j = 0;
	static char	F[20];
	static char	C[20];

	i = -1;
	if ((!ft_strncmp(line, "F", 1) && ft_strlen(F) > 1) || (!ft_strncmp(line, "C", 1) && ft_strlen(C) > 1))
		map->rgb->full_rgb++;
	if (!ft_strncmp(line, "F", 1) && ft_strlen(F) < 1)
	{
		map->rgb->full_rgb++;
		while (line && !ft_isdigit(line[++i]));
		if (line[i - 1] == '-')
			i--;
		while (i < (int)ft_strlen(line))
			F[j++] = line[i++];
	}
	i = -1;
	j = 0;
	if (!ft_strncmp(line, "C", 1) && ft_strlen(C) < 1)
	{
		map->rgb->full_rgb++;
		while (line && !ft_isdigit(line[++i]));
		if (line[i - 1] == '-')
			i--;
		while (i < (int)ft_strlen(line))
			C[j++] = line[i++];
	}
	if (ft_strlen(F) > 1 && ft_strlen(C) > 1)
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
	if (ft_atoi(color[i]) < 0 || ft_atoi(color[i]) > 255 || ft_strlen(color[i]) <= 0
		|| ft_strlen(color[i]) > 4 || !(color[i][0] >= '0' && color[i][0] <= '9'))
		return (1);
	return (0);
}


