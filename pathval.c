/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:17:47 by azaher            #+#    #+#             */
/*   Updated: 2023/01/19 16:22:04 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_tsunami(t_game *g, int i, int j, int *size)
{
	int	k;
	int	l;

	k = size[0];
	l = size[1];
	if (i < 0 || i >= k || j < 0 || j >= l || g->n_map[i][j] == '1'
	|| g->n_map[i][j] == 'G' || g->n_map[i][j] == 'E')
		return ;
	g->n_map[i][j] = 'G';
	first_tsunami(g, i + 1, j, size);
	first_tsunami(g, i - 1, j, size);
	first_tsunami(g, i, j + 1, size);
	first_tsunami(g, i, j - 1, size);
}

void	second_tsunami(t_game *g, int i, int j, int *size)
{
	int	k;
	int	l;

	k = size[0];
	l = size[1];
	if (i < 0 || i >= k || j < 0 || j >= l || g->n_map[i][j] == '1'
	|| g->n_map[i][j] == 'F')
		return ;
	g->n_map[i][j] = 'F';
	second_tsunami(g, i + 1, j, size);
	second_tsunami(g, i - 1, j, size);
	second_tsunami(g, i, j + 1, size);
	second_tsunami(g, i, j - 1, size);
}

void	free_map(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free (ret);
}

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if (c == 0)
		return ((char *)&str[ft_strlen(str)]);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}

void	pathval(t_game *g, int *size)
{
	int	*ar;

	ar = find_player(g);
	first_tsunami(g, ar[0], ar[1], size);
	if (count_rings(g->n_map) == 1)
	{
		free_map(g->n_map);
		perror("Error\nInvalid Path C");
		exit (1);
	}
	second_tsunami(g, ar[0], ar[1], size);
	if (find_exit(g->n_map) == 1)
	{
		free_map(g->n_map);
		perror("Error\nInvalid Path E");
		exit (1);
	}
	free_map(g->n_map);
	free(ar);
}
