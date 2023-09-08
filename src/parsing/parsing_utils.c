/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:24:50 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/08 11:38:08 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

void	count_row(char *file, t_data *map)
{
	int	fd;
	char	*line;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		send_error("File does not exist.\n");
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	map->row = i;
	return ;
}

void	count_col(char *file, t_data *map)
{
	int	fd;
	char	*line;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		send_error("File does not exist.\n");
	line = get_next_line(fd);
	i = ft_strlen(line);
	free(line);
	close(fd);
	map->col = i - 1;
	return ;
}
