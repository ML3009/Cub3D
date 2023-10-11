/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_verif_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:50:21 by mvautrot          #+#    #+#             */
/*   Updated: 2023/10/11 13:43:12 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cube_bonus.h"

int	file_extension(char *file)
{
	int	i;

	if (!file)
		return (printf(EF), EMPTY_FILE);
	i = -1;
	while (file[++i])
		;
	if ((file[i - 1] != 'b' && file[i - 2] != 'u'
			&& file[i - 3] != 'c' && file[i - 4] != '.') || ft_strlen(file) < 4)
		return (printf(WFN), FILE_NAME);
	return (0);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
		return (printf(EF), EMPTY_FILE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf(EF), EMPTY_FILE);
	close (fd);
	return (GOOD_ACCESS);
}
