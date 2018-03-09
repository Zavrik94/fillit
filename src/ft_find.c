/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:50:36 by azavrazh          #+#    #+#             */
/*   Updated: 2018/03/09 13:35:23 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define RULE1 (xc + tet->xlong) > ((int)ft_strlen(g_map[0]))
#define RULE2 (yc + tet->ylong - 1) > ((int)ft_strlen(g_map[0]))

int		*ft_coord(char **s)
{
	int	x;
	int	y;
	int	*res;

	y = -1;
	res = initres();
	while (s[++y])
	{
		x = -1;
		while (s[y][++x])
			if (s[y][x] == '#')
			{
				if (x < res[0])
					res[0] = x;
				if (y < res[1])
					res[1] = y;
				if (x > res[2])
					res[2] = x;
				if (y > res[3])
					res[3] = y;
			}
	}
	res[2] = res[2] - res[0] + 1;
	res[3] = res[3] - res[1] + 1;
	return (res);
}

int		checkpossible(char **g_map, t_tetra *tet, int xc, int yc)
{
	int	i;
	int	c;
	int	x;
	int	y;
	int	temp;

	i = -1;
	y = tet->y - 1;
	temp = xc;
	if ((RULE1) || (RULE2))
		return (0);
	while (tet->tetr[++y] && ++i < (tet->ylong))
	{
		x = tet->x - 1;
		xc = temp;
		c = -1;
		while (tet->tetr[++x] && ++c < tet->xlong)
		{
			if (tet->tetr[y][x] == '#' && g_map[yc][xc] != '.')
				return (0);
			xc++;
		}
		yc++;
	}
	return (1);
}

int		*findstart(char **g_map, t_tetra *tetramin)
{
	int x;
	int y;
	int *res;

	y = -1;
	if (!(res = (int*)malloc(sizeof(int) * 2)))
		return (0);
	while (g_map[++y])
	{
		x = -1;
		while (g_map[y][++x])
			if (checkpossible(g_map, tetramin, x, y))
			{
				res[0] = x;
				res[1] = y;
				return (res);
			}
	}
	free(res);
	return (NULL);
}

int		*currcoord(char **g_map, t_tetra *tetramin)
{
	int	x;
	int	y;
	int	*res;

	y = -1;
	if (!(res = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	res[0] = ft_strlen(g_map[0]);
	res[1] = ft_strlen(g_map[0]);
	while (g_map[++y])
	{
		x = -1;
		while (g_map[y][++x])
			if (g_map[y][x] == tetramin->letter)
			{
				if (x < res[0])
					res[0] = x;
				if (y < res[1])
					res[1] = y;
			}
	}
	return (res);
}

int		*findnextstart(char **g_map, t_tetra *tetramin, int *coord)
{
	int	x;
	int	y;
	int	*res;
	int	i;

	x = coord[0];
	y = coord[1] - 1;
	if (!(res = (int*)malloc(sizeof(int) * 4)))
		return (NULL);
	i = 0;
	while (g_map[++y])
	{
		if (i++ != 0)
			x = -1;
		while (g_map[y][++x])
			if (checkpossible(g_map, tetramin, x, y))
			{
				res[0] = x;
				res[1] = y;
				return (res);
			}
	}
	free(res);
	return (NULL);
}
