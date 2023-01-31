/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapval_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:24:58 by azaher            #+#    #+#             */
/*   Updated: 2023/01/19 16:29:20 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_fill(char *path)
{
	char	*tab[2];
	char	**map;
	int		fd;

	tab[0] = "";
	tab[1] = ft_strdup("");
	fd = open(path, O_RDONLY, 0444);
	while (1)
	{
		tab[0] = get_next_line(fd);
		if (!tab[0])
			break ;
		tab[1] = ft_strjoin(tab[1], tab[0]);
		free(tab[0]);
	}
	map = ft_split(tab[1], '\n');
	free(tab[0]);
	free(tab[1]);
	return (map);
}

int	rows_and_collumns(char *line, int rows, int fd)
{
	int	ncollumns;
	int	collumns;

	collumns = ft_nln_strlen(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line && ft_strcmp(line, "\n") == 0)
		{
			perror("Error\nInvalid map NL");
			exit (1);
		}
		if (line)
		{
			ncollumns = ft_nln_strlen(line);
			rows++;
		}
		free(line);
		if (ncollumns != collumns)
			return (1);
	}
	if (collumns < rows)
		return (1);
	free(line);
	return (0);
}

int	map_is_rectangular(int fd)
{
	char	*line;
	int		rows;

	rows = 1;
	line = get_next_line(fd);
	if (line)
	{
		rows_and_collumns(line, rows, fd);
	}
	else
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

void	valid_fl_line(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j] != 0)
	{
		if (map[0][j] == '1')
			j++;
		else
			error_exit(map, "Error\nInvalid top border\n");
	}
	while (map[i] != NULL)
	{
		i++;
	}
	j = 0;
	while (map[i - 1][j] != 0)
	{
		if (map[i - 1][j] == '1')
			j++;
		else
			error_exit(map, "Error\nInvalid bottom border\n");
	}
}

int	*map_size(char **map)
{
	int	*coord;

	coord = malloc(2 * sizeof(int));
	ft_bzero(coord, 2);
	while (map[coord[0]])
	{
		coord[0]++;
	}
	while (map[1][coord[1]])
	{
		coord[1]++;
	}
	return (coord);
}
