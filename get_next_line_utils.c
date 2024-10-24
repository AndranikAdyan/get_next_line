/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:48:05 by andranik          #+#    #+#             */
/*   Updated: 2024/10/20 16:03:33 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, char sign)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == sign)
			return (str);
		str++;
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_join(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str1 && str1[i])
		str[j++] = str1[i++];
	i = 0;
	while (str2 && str2[i])
		str[j++] = str2[i++];
	str[j] = '\0';
	if (str1)
		free(str1);
	return (str);
}

void	read_line(int fd, char **str)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes;

	bytes = 0;
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			break ;
		buf[bytes] = 0;
		if (bytes == 0)
			break ;
		*str = ft_join(*str, buf);
		if (ft_strchr(*str, '\n'))
			break ;
	}
}

char	*ft_cutstr(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\n')
		s[i] = str[i];
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
