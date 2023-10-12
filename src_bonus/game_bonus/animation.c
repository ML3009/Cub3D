/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:57:49 by purple            #+#    #+#             */
/*   Updated: 2023/10/12 10:32:12 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/cube_bonus.h"

int	init_anim(t_data *data)
{
	int		i;
	char	*str;
	char	*nb;

	i = 0;
	while (++i < 16)
	{
		nb = ft_itoa(i);
		str = ft_strjoin("asset/xpm/sprite/", nb, 1);
		free(nb);
		str = ft_strjoin(str, ".xpm", 0);
		data->anim[i - 1].image = mlx_xpm_file_to_image (data->mlx.mlx_id, \
		str, &data->anim[i - 1].width, &data->anim[i - 1].height);
		if (!data->anim[i - 1].image)
			return (free(str), printf ("Texture !: %d\n", i), -1);
		data->anim[i - 1].adress = mlx_get_data_addr(data->anim[i - 1].image, \
		&data->anim[i - 1].bpp, &data->anim[i - 1].line_lenght, \
		&data->anim[i - 1].endian);
		if (!(data->anim[i - 1].adress))
			return (free(str), printf ("Texture ?: %d\n", i), -1);
		free(str);
	}
	return (0);
}
