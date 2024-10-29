/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:13:20 by andranik          #+#    #+#             */
/*   Updated: 2024/10/29 16:14:28 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *str, char sign);
int		ft_strlen(char *str);
char	*ft_join(char *str1, char *str2);
void	read_line(int fd, char **str);
char	*ft_remainder(char *str);
char	*ft_cutstr(char *str);

#endif
