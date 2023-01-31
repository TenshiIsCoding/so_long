/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaher <azaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:32:15 by azaher            #+#    #+#             */
/*   Updated: 2023/01/11 14:56:38 by azaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
		return (0);
	if (s1 == 0)
		return (0);
	while (s1[i])
	{
		s2[i] = s1 [i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_countwords(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

void	ft_free(char **ret, int p)
{
	int	i;

	i = 0;
	while (i <= p)
	{
		free(ret[i]);
		i++;
	}
	free (ret);
}

void	ft_storewords(char **ret, char *s, char c)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c)
			j = i;
		while (s[i] != c && s[i])
			i++;
		if (i != j)
		{
			ret[p] = ft_substr(s, j, i - j);
			if (!ret[p])
				ft_free(ret, p);
			p++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**ret;

	if (s == NULL)
		return (0);
	words = ft_countwords((char *)s, c);
	ret = malloc((words + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ft_storewords(ret, (char *)s, c);
	ret[words] = NULL;
	return (ret);
}
