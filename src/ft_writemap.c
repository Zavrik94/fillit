/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:44:42 by azavrazh          #+#    #+#             */
/*   Updated: 2018/03/01 17:44:44 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			minmap(t_tetra *tetramin)
{
	int		res;

	res = 0;
	while (tetramin)
	{
		if (tetramin->xlong > res)
			res = tetramin->xlong;
		if ((tetramin->ylong - 1) > res)
			res = tetramin->ylong - 1;
		tetramin = tetramin->next;
	}
	return (res);
}

int			sqr(int i)
{
	int		sq;

	sq = i * i;
	return (sq);
}

char		*writemap(int count, t_tetra *tetramin)
{
	int		i;
	int		sq;
	char	*s;
	int		c;
	int		lng;

	i = -1;
	c = count * 4;
	sq = 0;
	while (sq < c)
		sq = sqr(++i);
	if (i < minmap(tetramin))
		i = minmap(tetramin);
	c = i;
	lng = i * i + i;
	s = (char*)malloc(sizeof(char) * (lng + 1));
	sq = -1;
	while (++sq != lng)
		if (sq == c && (c = c + i + 1) >= 0)
			s[sq] = '\n';
		else
			s[sq] = '.';
	s[sq] = '\0';
	return (s);
}

char		**biggermap(int i)
{
	int		x;
	int		y;
	char	**temp;

	x = -1;
	y = -1;
	temp = (char**)malloc(sizeof(char*) * i);
	while (++x <= i)
		temp[x] = (char*)malloc(sizeof(char) * i);
	while (++y <= i)
	{
		x = -1;
		while (++x < i)
			temp[y][x] = '.';
		temp[y][x] = '\0';
	}
	temp[y] = 0;
	g_ismapchange = 1;
	return (temp);
}
