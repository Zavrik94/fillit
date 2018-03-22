/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:43:15 by azavrazh          #+#    #+#             */
/*   Updated: 2018/03/07 19:47:01 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkit(char **tetra, int chk, int hash)
{
	int x;
	int y;

	y = -1;
	while (tetra[++y])
	{
		x = -1;
		while (tetra[y][++x])
			if (tetra[y][x] == '#' && hash++ > -1)
			{
				if (x != 0 && tetra[y][x - 1] == '#')
					chk++;
				if (y != 0 && tetra[y - 1][x] == '#')
					chk++;
				if (x != 3 && tetra[y][x + 1] == '#')
					chk++;
				if (y != 3 && tetra[y + 1][x] == '#')
					chk++;
			}
	}
	if (hash == 4 && (chk == 6 || chk == 8))
		return (1);
	return (0);
}

int		tetr_check(char ***res)
{
	int i;

	i = -1;
	while (res[++i])
		if (checkit(res[i], 0, 0) == 0)
			return (0);
	return (1);
}

int		ft_checker(char *s)
{
	int i;
	int line;
	int tetr;

	i = -1;
	line = 4;
	tetr = 20;
	while (s[++i])
	{
		if ((s[i] != '#' && s[i] != '.' && s[i] != '\n') || (s[i] == '\n' && \
			s[i + 1] == '\n' && s[i + 2] == '\0'))
			return (0);
		if (i == line && s[i] != '\n')
			return (0);
		else if (i == line && s[i] == '\n')
			line += 5;
		if (i == tetr && s[i] != '\n')
			return (0);
		else if (i == tetr && s[i] == '\n' && line++ > -1)
			tetr += 21;
	}
	if (i == 0)
		return (0);
	return (1);
}
