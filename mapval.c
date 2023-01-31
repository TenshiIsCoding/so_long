/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapval.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:49:03 by azaher            #+#    #+#             */
/*   Updated: 2023/01/19 16:26:46 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	error_exit(char **map, char *errormsg)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	perror(errormsg);
	exit (1);
}

size_t	ft_nln_strlen(const char *s)
{
	size_t	l;

	l = 0;
	if (s == 0)
		return (0);
	while (*s != '\0' && *s != '\n')
	{
		l++;
		s++;
	}
	return (l);
}

char	**mapval(char *path)
{
	char	**map;
	int		error;
	int		i;
	int		fd;

	i = 0;
	fd = open(path, O_RDONLY, 0444);
	if (fd < 0)
	{
		perror("");
		exit (1);
	}
	error = map_is_rectangular(fd);
	if (error == 1)
	{
		perror("Error\nInvalid map\n");
		exit (1);
	}
	map = map_fill(path);
	valid_fl_line(map);
	valid_borders(map);
	valid_items(map);
	return (map);
}
