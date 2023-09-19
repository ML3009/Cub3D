/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limited_strdup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:28:26 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/19 16:04:11 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_limited_strdup(char *str, int begin, int end)
{
	char	*new_str;
	int		i;

	i = 0;
	if (end - begin < 0)
		return (NULL);
	if (end == ft_strlen(str) && begin == 0)
		return (str);
	new_str = ft_malloc(end - begin + 1, "char");
	if (!new_str)
		return (NULL);
	while (begin <= end)
	{
		new_str[i] = str[begin];
		begin++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
