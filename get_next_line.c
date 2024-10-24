/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:19:52 by aadyan            #+#    #+#             */
/*   Updated: 2024/10/24 16:58:37 by aadyan           ###   ########.fr       */
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
	remainder = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!remainder)
		return (NULL);
	j = -1;
	while (str[i] && str[++i])
		remainder[++j] = str[i];
	remainder[++j] = 0;
	free(str);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	read_line(fd, &str);
	if (!str)
		return (0);
	s = ft_cutstr(str);
	if (s && !*s)
	{
		free(s);
		return (NULL);
	}
	str = ft_remainder(str);
	return (s);
}
