/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:04:02 by andranik          #+#    #+#             */
/*   Updated: 2024/03/06 17:18:19 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int	main(int argc, char const *argv[])
{
	int		fd;
	int		i;
	char	*str;

	(void)argc;
	(void)argv;
	fd = open("get_next_line.c", O_RDONLY);
	i = 0;
	while (i < 30)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	close(fd);
	return (0);
}
