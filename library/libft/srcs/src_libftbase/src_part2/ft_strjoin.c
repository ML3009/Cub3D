/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <purple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:15:36 by wmessmer          #+#    #+#             */
/*   Updated: 2023/09/19 16:03:53 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	char	*new;
	int		size;
	int		i;

	i = 0;
	size = (ft_strlen(s1) + ft_strlen(s2));
	new = ft_malloc(size, "char");
	if (!new)
		return (NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (*s2)
		new[i++] = *s2++;
	new[size] = '\0';
	free (s1);
	return (new);
}
