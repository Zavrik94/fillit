/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:44:21 by azavrazh          #+#    #+#             */
/*   Updated: 2018/03/01 17:44:25 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char        *ft_read(char *file)
{
    int     fd;
    char    buff[545];
    char    buffer[1];
    int     i;

    fd = 0;
    i = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit (0);
    while ((read(fd, buffer, 1)))
    {
        buff[i] = buffer[0];
        i++;
        if (i > 545)
            exit (0);
    }
    buff[i] = '\0';
    close(fd);
    return (ft_strdup(buff));
}
