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

t_tetra		*firstlist(t_tetra *tetramin)
{
	while (tetramin->prev != NULL)
		tetramin = tetramin->prev;
	return (tetramin);
}

t_tetra		*fillist(char ***res2)
{
	int		i;
	t_tetra	*tetramin;
	t_tetra	*temp;

	tetramin = (t_tetra*)malloc(sizeof(t_tetra));
	tetramin->prev = NULL;
	i = -1;
	while (res2[++i])
	{
		tetramin->x = ft_coord(res2[i])[0];
		tetramin->y = ft_coord(res2[i])[1];
		tetramin->xlong = ft_coord(res2[i])[2];
		tetramin->ylong = ft_coord(res2[i])[3] + 1;
		tetramin->tetr = res2[i];
		tetramin->next = NULL;
		tetramin->letter = i + 65;
		temp = tetramin;
		tetramin->next = (t_tetra*)malloc(sizeof(t_tetra));
		tetramin = tetramin->next;
		tetramin->prev = temp;
	}
	tetramin = tetramin->prev;
	tetramin->next = NULL;
	tetramin = firstlist(tetramin);
	return (tetramin);
}
