/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:16:20 by aadyan            #+#    #+#             */
/*   Updated: 2025/01/13 21:10:00 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int fd = open("only_nl.txt", O_RDONLY);
	char *str;
	int i = 0;

	while (i < 10)
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (str)
			free(str);
		i++;
	}

	close(fd);
	return 0;
}
