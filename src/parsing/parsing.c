/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:46:50 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/07 14:34:16 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube.h"

int	parsing(int ac, char **av, t_map *map)
{
	(void)ac;
	if (name_file(av[1]) < 0)
		return (WRONG_FILE);
	if (open_file(av[1], map) < 0)
		return (BAD_ACCESS);


	return (0);
}

int	name_file(char *file)
{
	int	i;

	if (!file)
		return (EMPTY_FILE);
	i = -1;
	while (file[++i]);
	if ((file[i - 1] != 'b' && file[i - 2] != 'u'
		&& file[i - 3] != 'c' && file[i - 4] != '.') || ft_strlen(file) < 4)
		return (printf("Wrong file extension.\n"), WRONG_FILE_NAME);
	return (0);
}

int	open_file(char *file, t_map *map)
{
	int	fd;
	char	*line;
	int	i;

	(void)map;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf("File does not exist.\n"), EMPTY_FILE);
	while (1)
	{
		line = get_next_line(fd);
		printf("line : %s\n", line);
		//if (line[0] == '1')
		//	map->map[i++] = ft_strdup(line);
		if (line == NULL)
			break ;
	}
	return (0);

}
