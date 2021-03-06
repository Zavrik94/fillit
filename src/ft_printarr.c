/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:44:15 by azavrazh          #+#    #+#             */
/*   Updated: 2018/03/01 17:44:16 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		iffree(int *res, int *cur, char **temp)
{
	free(res);
	free(cur);
	if (temp != NULL)
		freearr((void**)temp);
	return (1);
}

void	ft_printarr(char **arr)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (!arr)
	{
		return ;
	}
	while (arr[i])
	{
		c = 0;
		while (arr[i][c])
		{
			write(1, &arr[i][c], 1);
			c++;
		}
		write(1, "\n", 1);
		i++;
	}
}
