/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapval_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:07:24 by azaher            #+#    #+#             */
/*   Updated: 2023/01/20 12:21:52 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	int		*p;

	i = 0;
	p = s;
	while (n != 0)
	{
		p[i] = 0;
		i++;
		n--;
	}
}

void	valid_borders(char **map)
{
	int	i;
	int	l;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = ft_strlen(map[0]) - 1;
	l = 0;
	while (map[l])
		l++;
	while (i < l)
	{
		if (map[i][j] == '1' && (map[i][j] == map[i][k]))
			i++;
		else
			error_exit(map, "Error\nInvalid borders\n");
	}
}

void	valid_items(char **map)
{
	int	ar[3];
	int	i;
	int	j;

	i = 0;
	ft_bzero(ar, 3);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				ar[0]++;
			else if (map[i][j] == 'P')
				ar[1]++;
			else if (map[i][j] == 'C')
				ar[2]++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				error_exit(map, "Error\nItem does not exist\n");
			j++;
		}
		i++;
	}
	if (ar[0] != 1 || ar[1] != 1 || ar[2] < 1)
		error_exit(map, "Error\nInvalid item\n");
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	if (ft_strlen(s) < start || s == NULL)
		return (ft_calloc(1, 1));
	if (len >= SIZE_MAX || len + start > ft_strlen(s))
		dest = ft_calloc(ft_strlen(&s[start]) + 1, sizeof(char));
	else
		dest = ft_calloc(len + 1, sizeof(char));
	if (dest == 0)
		return (0);
	while (i < len && start + i < ft_strlen(s))
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest);
}
