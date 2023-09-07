/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:27:07 by mvautrot          #+#    #+#             */
/*   Updated: 2023/09/07 14:25:12 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	send_error(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		write(1, "(null)", 6);
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}
