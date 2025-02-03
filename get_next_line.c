/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:19:52 by aadyan            #+#    #+#             */
/*   Updated: 2025/02/03 18:33:53 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_line(int fd, char **str)
{
	char	*buf;
	int		bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return ;
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(*str);
			*str = NULL;
			break ;
		}
		buf[bytes] = '\0';
		if (bytes == 0)
			break ;
		*str = ft_join(*str, buf);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	free(buf);
}

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
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	remainder = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!remainder)
		return (NULL);
	j = 0;
	while (str[++i])
		remainder[j++] = str[i];
	remainder[j] = 0;
	free(str);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*s;

	if ((fd != 0 && fd < 2) || BUFFER_SIZE <= 0)
		return (0);
	read_line(fd, &str);
	s = ft_cutstr(str);
	if (s && !*s)
	{
		free(s);
		free(str);
		str = NULL;
		s = NULL;
		return (NULL);
	}
	str = ft_remainder(str);
	return (s);
}
