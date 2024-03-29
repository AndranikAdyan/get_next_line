/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remainder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andranik <andranik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:02:27 by andranik          #+#    #+#             */
/*   Updated: 2024/03/06 16:43:12 by andranik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remainder(char *str)
{
	char	*remainder;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == 0)
		return (free(str), NULL);
	remainder = malloc(ft_strlen(str) - i);
	if (!remainder)
		return (NULL);
	j = -1;
	while (str[i] && str[++i])
		remainder[++j] = str[i];
	remainder[++j] = 0;
	free(str);
	return (remainder);
}
