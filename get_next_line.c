/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:19:52 by aadyan            #+#    #+#             */
/*   Updated: 2024/03/30 13:39:26 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str = 0;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	str = read_line(fd, str);
	if (!str)
		return (0);
	s = ft_cutstr(str);
	if (s && !s[0])
	{
		free(s);
		return (NULL);
	}
	str = ft_remainder(str);
	return (s);
}
