/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:03:29 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/03 10:38:57 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

static char	*add_texture(char *line);

int	search_texture(t_data *map, char *line)
{
	if (!ft_strncmp(line, "SO", 2) && map->texture[SOUTH] == NULL)
		map->texture[SOUTH] = add_texture(line);
	if (!ft_strncmp(line, "NO", 2) && map->texture[NORTH] == NULL)
		map->texture[NORTH] = add_texture(line);
	if (!ft_strncmp(line, "EA", 2) && map->texture[EAST] == NULL)
		map->texture[EAST] = add_texture(line);
	if (!ft_strncmp(line, "WE", 2) && map->texture[WEST] == NULL)
		map->texture[WEST] = add_texture(line);
	return (0);
}

static char	*add_texture(char *line)
{
	char	*texture;
	int		start;
	int		end;

	texture = NULL;
	start = -1;
	end = ft_strlen(line);
	while (line && start < (int)ft_strlen(line) && line[++start] != 'a');
	while (line && end > 0 && line[end--] != 'm');
	texture = ft_limited_strdup(line, start, end + 1);
	if (!texture)
		return (NULL);
	return (texture);
}
