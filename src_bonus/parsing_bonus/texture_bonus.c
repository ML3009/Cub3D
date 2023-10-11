/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:03:29 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/11 18:31:54 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cube_bonus.h"

static char	*add_texture(char *texture, char *line);
static int	multiple_texture(char *texture);
static void	count_texture(t_data *map, char *line);
static int	create_texture(t_data *map, char *line, int text);

int	search_texture(t_data *map, char *line)
{
	count_texture(map, line);
	if (!ft_strncmp(line, "SO ", 3) && map->texture[SOUTH] == NULL)
		if (!create_texture(map, line, 0))
			return (-1);
	if (!ft_strncmp(line, "NO ", 3) && map->texture[NORTH] == NULL)
		if (!create_texture(map, line, 1))
			return (-1);
	if (!ft_strncmp(line, "EA ", 3) && map->texture[EAST] == NULL)
		if (!create_texture(map, line, 2))
			return (-1);
	if (!ft_strncmp(line, "WE ", 3) && map->texture[WEST] == NULL)
		if (!create_texture(map, line, 3))
			return (-1);
	return (0);
}

static int	create_texture(t_data *map, char *line, int text)
{
	if (text == 0)
	{
		map->texture[SOUTH] = add_texture(map->texture[SOUTH], line);
		if (!map->texture[SOUTH])
			return (0);
	}
	else if (text == 1)
	{
		map->texture[NORTH] = add_texture(map->texture[NORTH], line);
		if (!map->texture[NORTH])
			return (0);
	}
	else if (text == 2)
	{
		map->texture[EAST] = add_texture(map->texture[EAST], line);
		if (!map->texture[EAST])
			return (0);
	}
	else
	{
		map->texture[WEST] = add_texture(map->texture[WEST], line);
		if (!map->texture[WEST])
			return (0);
	}
	return (1);
}

static char	*add_texture(char *texture, char *line)
{
	int		start;
	int		end;

	start = -1;
	end = ft_strlen(line);
	while (line && start < (int)ft_strlen(line) && line[++start] != ' ')
		;
	while (line && start < (int)ft_strlen(line) && line[++start] == ' ')
		;
	while (line && end-- > 0 && (line[end] == ' ' || line[end] == '\n'))
		;
	if (line [end - 2] && (line[end] != 'm'
			|| line[end - 1] != 'p' || line[end - 2] != 'x'))
		return (NULL);
	texture = ft_limited_strdup(line, start, end);
	if (!texture)
		return (NULL);
	while (line && end > 0 && line[end--] != ' ')
		;
	while (line && end > 0 && line[end--] == ' ')
		;
	if ((end != 0 && end != 1) || multiple_texture(texture))
		return (free(texture), NULL);
	return (texture);
}

static int	multiple_texture(char *texture)
{
	int	i;

	i = -1;
	while (texture[++i])
		if (texture[i] == ' ')
			return (1);
	return (0);
}

static void	count_texture(t_data *map, char *line)
{
	if (!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "NO ", 3)
		|| !ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "WE ", 3))
		map->textok++;
	return ;
}
