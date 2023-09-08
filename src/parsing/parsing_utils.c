/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:24:50 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/08 15:15:28 by mvautrot         ###   ########.fr       */
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
		if (search_map(line) == true)
			i++;
		free(line);
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
	while (line)
	{
		if (search_map(line) == true)
			break;
		free(line);
		line = get_next_line(fd);
	}
	i = ft_strlen(line);
	free(line);
	close(fd);
	map->col = i - 1;
	return ;
}


int	check_wall(char *file)
{
	int		fd;
	char	*line;
	char	*bf_line;
	//int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf("File does not exist.\n"), EMPTY_FILE);
	line = get_next_line(fd);
	bf_line = ft_strdup(line);
	while (line)
	{
		if (search_wall(line) == false && search_map(line) == true)
			break ;
		free(bf_line);
		bf_line = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	if (search_wall(line) == false)
		return(free(line), free(bf_line), ERROR_WALL);
		//printf ("YOUHOU!\n");
	return (0);

}
