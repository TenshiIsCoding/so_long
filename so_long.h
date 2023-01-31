/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:30:03 by azaher            #+#    #+#             */
/*   Updated: 2023/01/20 16:52:16 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "ft_printf.h"

typedef struct s_img{
	void	*s;
	char	*spth;
	void	*h;
	char	*hpth;
	void	*g;
	char	*gpth;
	void	*r;
	char	*rpth;
	void	*e;
	char	*epth;
	int		x;
	int		y;
}	t_textures;

typedef struct s_game{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	char		**n_map;
	t_textures	img;
	char		*relative_path;
	int			img_width;
	int			img_height;
	int			moves;
}	t_game;

char	*get_next_line(int fd);
int		ft_printf(const char *s, ...);
size_t	ft_strlen(const char *s);
size_t	ft_nln_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
char	**map_fill(char *path);
int		map_is_rectangular(int fd);
void	valid_fl_line(char **map);
void	ft_bzero(void *s, size_t n);
void	error_exit(char **map, char *errormsg);
void	valid_borders(char **map);
void	valid_items(char **map);
char	**mapval(char *path);
void	*ft_calloc(size_t count, size_t size);
int		*map_size(char **map);
void	assign_textures(t_game *g);
void	display_map(char **map, t_game *g);
int		count_rings(char **map);
int		*find_player(t_game *g);
void	move_player_right(t_game *g, int i, int j);
void	move_player_left(t_game *g, int i, int j);
void	move_player_up(t_game *g, int i, int j);
void	move_player_down(t_game *g, int i, int j);
void	first_tsunami(t_game *g, int i, int j, int *size);
void	second_tsunami(t_game *g, int i, int j, int *size);
int		find_exit(char **map);
void	pathval(t_game *g, int *size);
void	free_map(char **ret);

#endif