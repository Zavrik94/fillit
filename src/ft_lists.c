/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:45:15 by azavrazh          #+#    #+#             */
/*   Updated: 2018/03/09 13:45:18 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		freelist(t_tetra *list)
{
	t_tetra *temp;

	list = firstlist(list);
	free(list->prev);
	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	free(list);
}

t_tetra		*firstlist(t_tetra *tetramin)
{
	while (tetramin->prev != NULL)
		tetramin = tetramin->prev;
	return (tetramin);
}

void		fill(t_tetra *tetramin, int *cor, char **res2, int i)
{
	tetramin->x = cor[0];
	tetramin->y = cor[1];
	tetramin->xlong = cor[2];
	tetramin->ylong = cor[3] + 1;
	tetramin->tetr = res2;
	tetramin->next = NULL;
	tetramin->letter = i + 65;
}

t_tetra		*fillist(char ***res2, int i)
{
	t_tetra	*tetramin;
	t_tetra	*temp;
	int		*cor;

	tetramin = (t_tetra*)malloc(sizeof(t_tetra));
	tetramin->prev = NULL;
	while (res2[++i])
	{
		cor = ft_coord(res2[i]);
		fill(tetramin, cor, res2[i], i);
		temp = tetramin;
		tetramin->next = (t_tetra*)malloc(sizeof(t_tetra));
		tetramin = tetramin->next;
		tetramin->prev = temp;
		free(cor);
	}
	tetramin = tetramin->prev;
	tetramin->next = NULL;
	free(tetramin->next);
	tetramin = firstlist(tetramin);
	return (tetramin);
}
