/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_search_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:52:19 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/11 13:43:19 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cube_bonus.h"

bool	search_map(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] != '1' && line[i] != '\0')
		i++;
	if (line[i] == '1')
	{
		while (line[i])
		{
			if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
				&& line[i] != 'E' && line[i] != 'S' && line[i] != 'W'
				&& line[i] != '\n' && line[i] != ' ' && line[i] != '\t')
				return (false);
			i++;
		}
		return (true);
	}
	return (false);
}

bool	search_wall(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] != '1' && line[i] != '\0')
		i++;
	if (line && line[i] == '1')
	{
		while (line && line[i] != '\0')
		{
			if (line[i] != '1' && line[i] != '\n'
				&& line[i] != ' ' && line[i] != '\t')
				return (false);
			i++;
		}
		return (true);
	}
	return (false);
}
