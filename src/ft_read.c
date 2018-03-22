/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:50:15 by azavrazh          #+#    #+#             */
/*   Updated: 2018/03/09 13:50:16 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		freearr(void **arr)
{
	int y;

	y = -1;
	while(arr[++y])
		free(arr[y]);
	free(arr);
}

int			*initres(void)
{
	int		*res;

	if (!(res = (int*)malloc(sizeof(int) * 4)))
		return (NULL);
	res[0] = 4;
	res[1] = 4;
	res[2] = 0;
	res[3] = 0;
	return (res);
}

char		*ft_read(char *file)
{
	int		fd;
	char	buff[545];
	char	buffer[1];
	int		i;

	fd = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(0);
	while ((read(fd, buffer, 1)))
	{
		buff[i] = buffer[0];
		i++;
		if (i > 545)
			exit(0);
	}
	buff[i] = '\0';
	close(fd);
	return (ft_strdup(buff));
}
