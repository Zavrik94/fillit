/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:43:15 by azavrazh          #+#    #+#             */
/*   Updated: 2018/03/01 17:43:32 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    puttetra(char **g_map, t_tetra *tetramin, int   *coord)
{
    int     i;
    int     c;
    int     x;
    int     y;
    int     reserv;

    i = 1;
    c = 0;
    x = tetramin->x;
    y = tetramin->y;
    reserv = coord[0];
    while (tetramin->tetr[y] && i < tetramin->ylong)
    {
        x = tetramin->x;
        coord[0] = reserv;
        c = 0;
        while(tetramin->tetr[x] && c < tetramin->xlong)
        {
            if (tetramin->tetr[y][x] == '#')
                g_map[coord[1]][coord[0]] = 65 + tetramin->n;
            coord[0]++;
            x++;
            c++;
        }
        coord[1]++;
        y++;
        i++;
    }   
}

 void    deletetetra(char **g_map,t_tetra *tetramin)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (g_map[y])
    {
        x = 0;
        while (g_map[y][x])
        {
            if (g_map[y][x] == tetramin->letter)
                g_map[y][x] = '.';
            x++;
        }
        y++;
    }
}


int     ismove(char **g_map, t_tetra *tetramin)
{
    char    **temp;
    int     x;
    int     y;
    int     *cur;

    x = 0;
    y = 0;
    temp = (char**)malloc(sizeof(char*) * ft_strlen(g_map[0]) + 1);
    while (g_map[y])
    {
        temp[y] = (char*)malloc(sizeof(char) * ft_strlen(g_map[0]) + 1);
        x = 0;
        while (g_map[y][x])
        {
            temp[y][x] = g_map[y][x];
            x++;
        }
        temp[y][x] = '\0';
        y++;
    }
    temp[y] = 0;
    cur = currcoord(temp, tetramin);
    deletetetra(temp, tetramin);
    if (findnextstart(temp, tetramin, cur) == NULL)
    {
        free(temp);
        return (0);
    }
    free(temp);
    return (1);
}

t_tetra   *move(t_tetra *tetramin)
{
    int *res;

    if (ismove(g_map, tetramin) == 0 && tetramin->prev == NULL)
    {
            g_map = biggermap(g_map);
            tetramin = firstlist(tetramin);
            return (tetramin->next);
    }
    else if (ismove(g_map, tetramin) == 0)
    {
        deletetetra(g_map, tetramin);
        tetramin = move(tetramin->prev)->prev;
    }
    else
    {
        res = currcoord(g_map, tetramin);
        deletetetra(g_map, tetramin);
        res = findnextstart(g_map, tetramin, res);
        puttetra(g_map, tetramin, res);
    }
    return (tetramin->next);
}

void    settetra(t_tetra *tetramin)
{
    int     *coord;

    if (tetramin == NULL)
        return ;
    while (findstart(g_map, tetramin) == NULL)
    {
        tetramin = move(tetramin->prev);
        if (g_ismapchange == 1)
        {
            tetramin = firstlist(tetramin);
            g_ismapchange = 0;
        }
    }
    coord = findstart(g_map, tetramin);
    puttetra(g_map, tetramin, coord);
    settetra(tetramin->next);
}
