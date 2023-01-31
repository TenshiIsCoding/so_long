/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:18:36 by azaher            #+#    #+#             */
/*   Updated: 2023/01/20 16:54:40 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_rings(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	find_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	assign_textures(t_game *g)
{
	g->img.spth = "./SONIC.xpm";
	g->img.s = mlx_xpm_file_to_image(g->mlx, g->img.spth, &g->img.x, &g->img.y);
	g->img.hpth = "./GHZBG.xpm";
	g->img.h = mlx_xpm_file_to_image(g->mlx, g->img.hpth, &g->img.x, &g->img.y);
	g->img.gpth = "./GRASS.xpm";
	g->img.g = mlx_xpm_file_to_image(g->mlx, g->img.gpth, &g->img.x, &g->img.y);
	g->img.rpth = "./RING.xpm";
	g->img.r = mlx_xpm_file_to_image(g->mlx, g->img.rpth, &g->img.x, &g->img.y);
	g->img.epth = "./GOALRING.xpm";
	g->img.e = mlx_xpm_file_to_image(g->mlx, g->img.epth, &g->img.x, &g->img.y);
}

void	map_render(char map, t_game *g, int x, int y)
{
	if (map == '0')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.h, x, y);
	else if (map == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.g, x, y);
	else if (map == 'C')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.r, x, y);
	else if (map == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.e, x, y);
	else if (map == 'P')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.s, x, y);
}

void	display_map(char **map, t_game *g)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			x = j * 64;
			y = i * 64;
			map_render(map[i][j], g, x, y);
			j++;
		}
		j = 0;
		i++;
	}
}
