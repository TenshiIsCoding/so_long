/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:30:19 by azaher            #+#    #+#             */
/*   Updated: 2023/01/21 13:14:45 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc)
{
	if (argc != 2)
	{
		perror("Error\nIncorrect amount of arguments\n");
		exit (1);
	}
}

void	valid_map_path(char	*path)
{
	char	*str;

	str = ft_strrchr(path, '.');
	if (!str)
	{
		perror("Error\nIncorrect file extension");
		exit (1);
	}
	if (ft_strcmp(str, ".ber"))
	{
		perror("Error\nIncorrect file extension");
		exit (1);
	}
}

int	move_player(int keycode, t_game *g)
{
	int	*cord;

	cord = find_player(g);
	if (keycode == 13)
		(move_player_up(g, cord[0], cord[1]), free(cord));
	else if (keycode == 1)
		(move_player_down(g, cord[0], cord[1]), free(cord));
	else if (keycode == 0)
		(move_player_left(g, cord[0], cord[1]), free(cord));
	else if (keycode == 2)
		(move_player_right(g, cord[0], cord[1]), free(cord));
	else if (keycode == 53)
	{
		free_map(g->map);
		free(cord);
		exit (1);
	}
	return (0);
}

int	destroy_win(int keycode, t_game *g)
{
	(void)keycode;
	(void)g;
	exit (1);
}

int	main(int argc, char **argv)
{
	t_game	*g;
	int		*cord;
	int		x;
	int		y;

	g = malloc(sizeof(t_game));
	check_args(argc);
	valid_map_path(argv[1]);
	g->map = mapval(argv[1]);
	g->n_map = mapval(argv[1]);
	g->mlx = mlx_init();
	g->moves = 0;
	cord = map_size(g->map);
	pathval(g, cord);
	x = (cord[1] * 64);
	y = (cord[0] * 64);
	g->mlx_win = mlx_new_window(g->mlx, x, y, "so_long");
	assign_textures(g);
	display_map(g->map, g);
	mlx_hook(g->mlx_win, 2, 0, move_player, g);
	mlx_hook(g->mlx_win, 17, 0, destroy_win, g);
	mlx_loop(g->mlx);
}
