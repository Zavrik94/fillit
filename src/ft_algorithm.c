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

void		puttetra(char **g_map, t_tetra *tetramin, int *coord)
{
	int		i;
	int		c;
	int		x;
	int		y;
	int		reserv;

	i = 0;
	x = tetramin->x - 1;
	y = tetramin->y - 1;
	reserv = coord[0];
	while (tetramin->tetr[++y] && ++i < tetramin->ylong)
	{
		x = tetramin->x - 1;
		coord[0] = reserv;
		c = -1;
		while (tetramin->tetr[++x] && ++c < tetramin->xlong)
		{
			if (tetramin->tetr[y][x] == '#')
				g_map[coord[1]][coord[0]] = tetramin->letter;
			coord[0]++;
		}
		coord[1]++;
	}
}

void		deletetetra(char **g_map, t_tetra *tetramin)
{
	int		x;
	int		y;

	y = -1;
	while (g_map[++y])
	{
		x = -1;
		while (g_map[y][++x])
			if (g_map[y][x] == tetramin->letter)
				g_map[y][x] = '.';
	}
}

int			ismove(char **g_map, t_tetra *tetramin)
{
	char	**temp;
	int		x;
	int		y;
	int		*cur;
	int		*res;

	y = -1;
	temp = (char**)malloc(sizeof(char*) * (ft_strlen(g_map[0]) + 1));
	while (g_map[++y])
	{
		temp[y] = (char*)malloc(sizeof(char) * (ft_strlen(g_map[0]) + 1));
		x = -1;
		while (g_map[y][++x])
			temp[y][x] = g_map[y][x];
		temp[y][x] = '\0';
	}
	temp[y] = 0;
	cur = currcoord(temp, tetramin);
	deletetetra(temp, tetramin);
	res = findnextstart(temp, tetramin, cur);
	if (iffree(res, cur, temp) && res == NULL)
		return (0);
	return (1);
}

t_tetra		*move(t_tetra *tetramin, int i)
{
	int		*res;
	int		*cor;

	if (ismove(g_map, tetramin) == 0 && tetramin->prev == NULL)
	{
		i = (int)ft_strlen(g_map[0]) + 1;
		freearr((void**)g_map);
		g_map = biggermap(i);
		tetramin = firstlist(tetramin);
		return (tetramin->next);
	}
	else if (ismove(g_map, tetramin) == 0)
	{
		deletetetra(g_map, tetramin);
		tetramin = move(tetramin->prev, 0)->prev;
	}
	else
	{
		cor = currcoord(g_map, tetramin);
		deletetetra(g_map, tetramin);
		res = findnextstart(g_map, tetramin, cor);
		puttetra(g_map, tetramin, res);
		iffree(cor, res, NULL);
	}
	return (tetramin->next);
}

void		settetra(t_tetra *tetramin)
{
	int		*coord;

	if (tetramin == NULL)
		return ;
	coord = findstart(g_map, tetramin);
	while (coord == NULL)
	{
		tetramin = move(tetramin->prev, 0);
		if (g_ismapchange == 1)
		{
			tetramin = firstlist(tetramin);
			g_ismapchange = 0;
		}
		free(coord);
		coord = findstart(g_map, tetramin);
	}
	free(coord);
	coord = findstart(g_map, tetramin);
	puttetra(g_map, tetramin, coord);
	free(coord);
	settetra(tetramin->next);
}
