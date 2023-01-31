/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:29:05 by azaher            #+#    #+#             */
/*   Updated: 2023/01/18 11:01:34 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*find_player(t_game *g)
{
	int	*ar;

	ar = malloc(2 * sizeof(int));
	ar[0] = 0;
	while (g->map[ar[0]])
	{
		ar[1] = 0;
		while (g->map[ar[0]][ar[1]])
		{
			if (g->map[ar[0]][ar[1]] == 'P')
			{
				return (ar);
			}
			ar[1]++;
		}
		ar[0]++;
	}
	free(ar);
	return (0);
}

void	move_player_right(t_game *g, int i, int j)
{
	if (g->map[i][j + 1] == '0')
	{
		g->map[i][j] = '0';
		g->map[i][j + 1] = 'P';
		g->moves++;
		ft_printf("You moved %d times!\n", g->moves);
		display_map(g->map, g);
	}
	else if (g->map[i][j + 1] == 'C')
	{
		g->map[i][j] = '0';
		g->map[i][j + 1] = 'P';
		g->moves++;
		ft_printf("You moved %d times!\n", g->moves);
		display_map(g->map, g);
	}
	else if (g->map[i][j + 1] == 'E')
	{
		if (count_rings(g->map) == 0)
			exit (1);
		else
			display_map(g->map, g);
	}
	else if (g->map[i][j + 1] == '1')
		display_map(g->map, g);
}

void	move_player_left(t_game *g, int i, int j)
{
	if (g->map[i][j - 1] == '0')
	{
		g->map[i][j] = '0';
		g->map[i][j - 1] = 'P';
		g->moves++;
		ft_printf("You moved %d times!\n", g->moves);
		display_map(g->map, g);
	}
	else if (g->map[i][j - 1] == 'C')
	{
		g->map[i][j] = '0';
		g->map[i][j - 1] = 'P';
		g->moves++;
		ft_printf("You moved %d times!\n", g->moves);
		display_map(g->map, g);
	}
	else if (g->map[i][j - 1] == 'E')
	{
		if (count_rings(g->map) == 0)
			exit (1);
		else
			display_map(g->map, g);
	}
	else if (g->map[i][j - 1] == '1')
		display_map(g->map, g);
}

void	move_player_up(t_game *g, int i, int j)
{
	if (g->map[i - 1][j] == '0')
	{
		g->map[i][j] = '0';
		g->map[i - 1][j] = 'P';
		g->moves++;
		ft_printf("You moved %d times!\n", g->moves);
		display_map(g->map, g);
	}
	else if (g->map[i - 1][j] == 'C')
	{
		g->map[i][j] = '0';
		g->map[i - 1][j] = 'P';
		g->moves++;
		ft_printf("You moved %d times!\n", g->moves);
		display_map(g->map, g);
	}
	else if (g->map[i - 1][j] == 'E')
	{
		if (count_rings(g->map) == 0)
			exit (1);
		else
			display_map(g->map, g);
	}
	else if (g->map[i][j - 1] == '1')
		display_map(g->map, g);
}

void	move_player_down(t_game *g, int i, int j)
{
	if (g->map[i + 1][j] == '0')
	{
		g->map[i][j] = '0';
		g->map[i + 1][j] = 'P';
		g->moves++;
		ft_printf("You moved %d times!\n", g->moves);
		display_map(g->map, g);
	}
	else if (g->map[i + 1][j] == 'C')
	{
		g->map[i][j] = '0';
		g->map[i + 1][j] = 'P';
		g->moves++;
		ft_printf("You moved %d times!\n", g->moves);
		display_map(g->map, g);
	}
	else if (g->map[i + 1][j] == 'E')
	{
		if (count_rings(g->map) == 0)
			exit (1);
		else
			display_map(g->map, g);
	}
	else if (g->map[i][j + 1] == '1')
		display_map(g->map, g);
}
